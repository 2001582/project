CREATE TABLE users ( -- 유저 정보 테이블
    user_id VARCHAR(20) PRIMARY KEY, -- 유저 아이디(기본키)
    user_name VARCHAR(50) NOT NULL, -- 유저 이름
    user_password VARCHAR(20) NOT NULL, -- 유저 비밀번호
    user_phoneNumber VARCHAR(20) NOT NULL -- 유저 휴대폰 번호
);

CREATE TABLE categories ( -- 카테고리 테이블
    category_id INT PRIMARY KEY, -- 카테고리 식별값(기본키)
    category_name VARCHAR(100) NOT NULL UNIQUE -- 카테고리 이름, 꼭 있어야 하며 각 이름은 중복X
);
CREATE SEQUENCE category_seq -- id 자동 1씩 증가
    START WITH 1
    INCREMENT BY 1;

CREATE TABLE posts ( -- 글 테이블
    post_id INT PRIMARY KEY, -- 글 식별값(기본키)
    user_id VARCHAR(20) REFERENCES users(user_id) NOT NULL, -- 작성자를 유저 테이블에서 참조(외래키)
    category_id INT REFERENCES categories(category_id) NOT NULL, -- 카테고리를 카테고리 테이블에서 참조(외래키)
    title varchar(255) NOT NULL, -- 글 제목(필수)
    p_content CLOB NOT NULL, -- 글 내용 저장, CLOB는 데이터를 별도로 저장하는 데이터타입(글이 길어지는 것을 대비)
    p_created_at TIMESTAMP DEFAULT SYSTIMESTAMP -- 작성시간, TIMESTAMP 데이터 타입(기본값은 시스템 시각)
);
CREATE SEQUENCE post_seq -- id 자동 1씩 증가
    START WITH 1
    INCREMENT BY 1;
    
CREATE TABLE likes ( -- 추천 테이블
    user_id VARCHAR(20) REFERENCES users(user_id), -- 추천한 유저, 유저 테이블에서 참조(외래키)
    post_id INT REFERENCES posts(post_id), -- 추천된 글, 글 테이블에서 참조(외래키)
    PRIMARY KEY (user_id, post_id) -- 추천한 유저, 추천된 글을 복합키로 하여 기본키 구성(유저가 같은 글을 반복 추천X)
);

CREATE TABLE comments ( -- 댓글 테이블
   comment_id INT PRIMARY KEY, -- 댓글 식별값(기본키)
   post_id INT REFERENCES posts(post_id) NOT NULL, -- 어떤 글의 댓글인지를 글 테이블에서 참조(외래키) 
   user_id VARCHAR(20) REFERENCES users(user_id) NOT NULL, -- 어떤 유저가 단 댓글인지를 유저 테이블에서 참조(외래키)
   c_content CLOB NOT NULL  -- 댓글 내용 데이터타입 CLOB
   c_created_at TIMESTAMP DEFAULT SYSTIMESTAMP -- 작성시간, TIMESTAMP 데이터 타입(기본값은 시스템 시각)
); 
CREATE SEQUENCE comment_seq -- id 자동 1씩 증가
    START WITH 1
    INCREMENT BY 1;


CREATE TABLE bookmarks ( -- 북마크 테이블
   user_id VARCHAR(20) REFERENCES users(user_id), -- 어떤 유저가 북마크했는지를 유저 테이블에서 참조(외래키)
   post_id INT REFERENCES posts(post_id), -- 어떤 글이 북마크됐는지를 글 테이블에서 참조(외래키)
   PRIMARY KEY (user_id, post_id) -- 북마크한 유저와 북마크된 글을 복합키로 하여 기본키 구성(유저가 같은 글 반복 스크랩x)
);

CREATE TABLE photos ( -- 사진 테이블
    photo_id INT PRIMARY KEY, -- 사진 식별값(기본키)
    post_id INT REFERENCES posts(post_id) NOT NULL, -- 어떤 글에 들어갈 사진인지를 글 테이블에서 참조(외래키)
    file_path VARCHAR(255) NOT NULL -- 사진 경로
);
CREATE SEQUENCE photo_seq -- id 자동 1씩 증가
    START WITH 1
    INCREMENT BY 1;