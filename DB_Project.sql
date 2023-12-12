CREATE TABLE users ( -- ���� ���� ���̺�
    user_id VARCHAR(20) PRIMARY KEY, -- ���� ���̵�(�⺻Ű)
    user_name VARCHAR(50) NOT NULL, -- ���� �̸�
    user_password VARCHAR(20) NOT NULL, -- ���� ��й�ȣ
    user_phoneNumber VARCHAR(20) NOT NULL -- ���� �޴��� ��ȣ
);

CREATE TABLE categories ( -- ī�װ� ���̺�
    category_id INT PRIMARY KEY, -- ī�װ� �ĺ���(�⺻Ű)
    category_name VARCHAR(100) NOT NULL UNIQUE -- ī�װ� �̸�, �� �־�� �ϸ� �� �̸��� �ߺ�X
);
CREATE SEQUENCE category_seq -- id �ڵ� 1�� ����
    START WITH 1
    INCREMENT BY 1;

CREATE TABLE posts ( -- �� ���̺�
    post_id INT PRIMARY KEY, -- �� �ĺ���(�⺻Ű)
    user_id VARCHAR(20) REFERENCES users(user_id) NOT NULL, -- �ۼ��ڸ� ���� ���̺��� ����(�ܷ�Ű)
    category_id INT REFERENCES categories(category_id) NOT NULL, -- ī�װ��� ī�װ� ���̺��� ����(�ܷ�Ű)
    title varchar(255) NOT NULL, -- �� ����(�ʼ�)
    p_content CLOB NOT NULL, -- �� ���� ����, CLOB�� �����͸� ������ �����ϴ� ������Ÿ��(���� ������� ���� ���)
    p_created_at TIMESTAMP DEFAULT SYSTIMESTAMP -- �ۼ��ð�, TIMESTAMP ������ Ÿ��(�⺻���� �ý��� �ð�)
);
CREATE SEQUENCE post_seq -- id �ڵ� 1�� ����
    START WITH 1
    INCREMENT BY 1;
    
CREATE TABLE likes ( -- ��õ ���̺�
    user_id VARCHAR(20) REFERENCES users(user_id), -- ��õ�� ����, ���� ���̺��� ����(�ܷ�Ű)
    post_id INT REFERENCES posts(post_id), -- ��õ�� ��, �� ���̺��� ����(�ܷ�Ű)
    PRIMARY KEY (user_id, post_id) -- ��õ�� ����, ��õ�� ���� ����Ű�� �Ͽ� �⺻Ű ����(������ ���� ���� �ݺ� ��õX)
);

CREATE TABLE comments ( -- ��� ���̺�
   comment_id INT PRIMARY KEY, -- ��� �ĺ���(�⺻Ű)
   post_id INT REFERENCES posts(post_id) NOT NULL, -- � ���� ��������� �� ���̺��� ����(�ܷ�Ű) 
   user_id VARCHAR(20) REFERENCES users(user_id) NOT NULL, -- � ������ �� ��������� ���� ���̺��� ����(�ܷ�Ű)
   c_content CLOB NOT NULL  -- ��� ���� ������Ÿ�� CLOB
   c_created_at TIMESTAMP DEFAULT SYSTIMESTAMP -- �ۼ��ð�, TIMESTAMP ������ Ÿ��(�⺻���� �ý��� �ð�)
); 
CREATE SEQUENCE comment_seq -- id �ڵ� 1�� ����
    START WITH 1
    INCREMENT BY 1;


CREATE TABLE bookmarks ( -- �ϸ�ũ ���̺�
   user_id VARCHAR(20) REFERENCES users(user_id), -- � ������ �ϸ�ũ�ߴ����� ���� ���̺��� ����(�ܷ�Ű)
   post_id INT REFERENCES posts(post_id), -- � ���� �ϸ�ũ�ƴ����� �� ���̺��� ����(�ܷ�Ű)
   PRIMARY KEY (user_id, post_id) -- �ϸ�ũ�� ������ �ϸ�ũ�� ���� ����Ű�� �Ͽ� �⺻Ű ����(������ ���� �� �ݺ� ��ũ��x)
);

CREATE TABLE photos ( -- ���� ���̺�
    photo_id INT PRIMARY KEY, -- ���� �ĺ���(�⺻Ű)
    post_id INT REFERENCES posts(post_id) NOT NULL, -- � �ۿ� �� ���������� �� ���̺��� ����(�ܷ�Ű)
    file_path VARCHAR(255) NOT NULL -- ���� ���
);
CREATE SEQUENCE photo_seq -- id �ڵ� 1�� ����
    START WITH 1
    INCREMENT BY 1;