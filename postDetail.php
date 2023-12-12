<?php
session_start();
$conn = oci_connect('sqldb', '1234', 'localhost/XE', 'AL32UTF8');

$post_id = $_GET['post_id'];
$sql = "SELECT p.*, TO_CHAR(p.p_created_at, 'YYYY-MM-DD HH24:MI:SS') AS p_created_at, u.user_id, c.category_name, ph.file_path FROM posts p 
        JOIN users u ON p.user_id = u.user_id 
        JOIN categories c ON p.category_id = c.category_id 
        LEFT JOIN photos ph ON p.post_id = ph.post_id 
        WHERE p.post_id = :post_id";
$stmt = oci_parse($conn, $sql);
oci_bind_by_name($stmt, ':post_id', $post_id, -1, SQLT_INT);
oci_execute($stmt);

$row = oci_fetch_array($stmt, OCI_ASSOC + OCI_RETURN_NULLS);
$title = htmlspecialchars($row['TITLE'], ENT_QUOTES, 'UTF-8');
$category = htmlspecialchars($row['CATEGORY_NAME'], ENT_QUOTES, 'UTF-8');
$content = $row['P_CONTENT'] !== null ? $row['P_CONTENT']->read($row['P_CONTENT']->size()) : '';
$content = $content !== '' ? htmlspecialchars($content, ENT_QUOTES, 'UTF-8') : '';
$author = htmlspecialchars($row['USER_ID'], ENT_QUOTES, 'UTF-8');
$time = $row['P_CREATED_AT'];
$image_url = htmlspecialchars($row['FILE_PATH'], ENT_QUOTES, 'UTF-8');

$isAuthor = false;
if (isset($_SESSION['user_id']) && $_SESSION['user_id'] == $author) {
    $isAuthor = true;
}

$sql = "SELECT COUNT(*) AS comments_count FROM comments WHERE post_id = :post_id";
$stmt = oci_parse($conn, $sql);
oci_bind_by_name($stmt, ':post_id', $post_id, -1, SQLT_INT);
oci_execute($stmt);

$row = oci_fetch_array($stmt, OCI_ASSOC + OCI_RETURN_NULLS);
$comments_count = $row['COMMENTS_COUNT'];

$sql = "SELECT c.*, TO_CHAR(c.c_created_at, 'YYYY-MM-DD HH24:MI:SS') AS c_created_at, u.user_id, c.c_content FROM comments c
        JOIN users u ON c.user_id = u.user_id
        WHERE c.post_id = :post_id
        ORDER BY c.c_created_at DESC";
$stmt = oci_parse($conn, $sql);
oci_bind_by_name($stmt, ':post_id', $post_id, -1, SQLT_INT);
oci_execute($stmt);

$comments = array();
while ($row = oci_fetch_array($stmt, OCI_ASSOC + OCI_RETURN_NULLS)) {
    $comments[] = $row;
}

$sql = "SELECT COUNT(*) AS likes_count FROM likes WHERE post_id = :post_id";
$stmt = oci_parse($conn, $sql);
oci_bind_by_name($stmt, ':post_id', $post_id, -1, SQLT_INT);
oci_execute($stmt);
$row = oci_fetch_array($stmt, OCI_ASSOC + OCI_RETURN_NULLS);
$likes_count = $row['LIKES_COUNT'];
?>

<!DOCTYPE html>
<html>

<head>
    <!-- 인코딩 방식-->
    <meta charset="utf-8" />
    <!-- 너비를 장치에 맞게 맞추고, 초기 확대, 축소 수준 1로 -->
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no" />

    <title>SPACEPOINT</title>

    <!-- 메인 영역(외부 CSS)-->
    <link rel="stylesheet" type="text/css"
        href="https://cdnjs.cloudflare.com/ajax/libs/OwlCarousel2/2.1.3/assets/owl.carousel.min.css" />
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.3.0/css/font-awesome.min.css">

    <!-- 부트스트랩 CSS -->
    <link rel="stylesheet" type="text/css" href="css/bootstrap.css" />

    <!-- 폰트 스타일 CSS(외부 CSS)-->
    <link href="https://fonts.googleapis.com/css?family=Poppins:400,600,700&display=swap" rel="stylesheet">

    <!-- 내부 주요 CSS -->
    <link href="css/style.css" rel="stylesheet" />

    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
</head>

<body class="sub_page">
    <div class="header_area">
        <header class="header_section">
            <div class="container">
                <nav class="navbar navbar-expand-lg custom_nav-container pt-3">
                    <a class="navbar-brand mr-5" href="mainHTML.php">
                        <span>
                            SPACEPOINT
                        </span>
                    </a>
                    <div class="collapse navbar-collapse" id="navbarSupportedContent">
                        <div class="d-flex ml-auto flex-column flex-lg-row align-items-center">
                            <ul class="navbar-nav  ">
                                <?php
                                if (isset($_SESSION['loggedin'])) { // 로그인 상태라면
                                    echo "<li class='nav-item'>";
                                    echo "<a class='nav-link'>환영합니다, " . $_SESSION['user_name'] . "님!</a>";
                                    echo "</li>";
                                    echo "<li class='nav-item'>";
                                    echo "<a class='nav-link' href='logout.php'>로그아웃</a>";
                                    echo "<li class='nav-item'>";
                                    echo "<a class='nav-link' href='mypageHTML.php'>마이페이지</a>";
                                    echo "</li>";
                                    echo "</li>";
                                } else { // 로그아웃 상태라면
                                    echo "<li class='nav-item'>";
                                    echo "<a class='nav-link' href='loginHTML.php'>로그인</a>";
                                    echo "</li>";
                                }
                                ?>
                                <li class="nav-item">
                                    <a class="nav-link" href="registerHTML.php">회원가입</a>
                                </li>
                            </ul>
                        </div>
                    </div>
                </nav>
            </div>
        </header>
    </div>

    <!-- 본문 영역 -->
    <div class="container">
        <div class="post_detail">
            <h2 class="category_name">
                카테고리:
                <?php echo $category; ?>
            </h2>
            <h1 class="post_title">
                <?php echo $title; ?>
            </h1>
            <div class="post_info">
                <span class="author_name">
                    작성자:
                    <?php echo $author; ?>
                </span>
                <span class="post_time">
                    작성시각:
                    <?php echo $time; ?>
                </span>
            </div>
            <img class="post_image" src="<?php echo $image_url; ?>" alt="게시글 이미지">
            <div class="post_content">
                <?php echo nl2br($content); ?>
            </div>
        </div>
        <div class="button_container">
            <?php
            if ($isAuthor) {
                echo "<button class='register_btn' onclick=\"location.href='deletePost.php?post_id={$post_id}'\">삭제하기</button>";
            } else {
                echo "<button class='register_btn like-btn'>추천 : {$likes_count}개</button>";
                echo "<button class='register_btn bookmark-btn'>나중에 볼 게시물</button>";
            }
            ?>
        </div>
    </div>

    <div class="comments_section">
        <h2 class="comments_count">
            댓글
            <?php echo $comments_count; ?>개
        </h2>
        <form class="comment_form" method="post" action="comment.php">
            <textarea name="comment" placeholder="댓글을 작성하세요."></textarea>
            <input type="hidden" name="post_id" value="<?php echo $post_id; ?>">
            <button class="register_btn" button type="submit">작성</button>
        </form>
        <?php
        foreach ($comments as $comment) {
            $comment_content = $comment['C_CONTENT']->load();
            $comment_content = htmlspecialchars($comment_content, ENT_QUOTES, 'UTF-8');
            $comment_author = htmlspecialchars($comment['USER_ID'], ENT_QUOTES, 'UTF-8');
            $comment_time = $comment['C_CREATED_AT'];
            echo "<div class='comment'>";
            echo "<div class='comment_info'>";
            echo "<span class='comment_author'>작성자: {$comment_author}</span>";
            echo "<span class='comment_time'>작성시각: {$comment_time}</span>";
            if (isset($_SESSION['user_id']) && $_SESSION['user_id'] == $comment_author) {
                echo "<button class='delete_comment_btn' onclick=\"location.href='deleteComment.php?comment_id={$comment['COMMENT_ID']}'\">삭제하기</button>";
            }
            echo "</div>";
            echo "<div class='comment_content'>{$comment_content}</div>";
            echo "</div>";
        }
        ?>
    </div>

    <script type="text/javascript" src="js/bootstrap.js"></script>
    <script>
        $(".like-btn").click(function () {
            var user_id = "<?= $_SESSION['user_id'] ?>";
            if (!user_id) {
                alert("로그인이 필요합니다");
                return;
            }
            $.post("likes.php",
                {
                    post_id: "<?= $post_id ?>",
                    user_id: user_id
                },
                function (data, status) {
                    location.reload(); 
               });
        });
        $(".bookmark-btn").click(function () {
            var user_id = "<?= $_SESSION['user_id'] ?>";
            if (!user_id) {
                alert("로그인이 필요합니다");
                return;
            }
            $.post("bookmark.php",
                {
                    post_id: "<?= $post_id ?>",
                    user_id: user_id
                },
                function (data, status) {
                    if (data.trim() == 'added') {
                        alert("나중에 볼 게시물에 추가되었습니다");
                    } else if (data.trim() == 'deleted') {
                        alert("나중에 볼 게시물에서 삭제되었습니다");
                    }
                });
        });
    </script>
</body>

<style>
    .post_detail {
        text-align: center;
        margin-top: 50px;
    }

    .category_name {
        text-align: left;
        font-size: 20px;
    }

    .post_info {
        text-align: right;
    }

    .post_image {
        width: 70%;
        height: auto;
        margin: 20px 0;
    }

    .post_content {
        text-align: left;
        margin-left: 15%;
        max-width: 70%;
    }

    .content_section {
        text-align: left;
        margin-top: 50px;
        margin-right: 15%;
    }

    .button_container {
        display: flex;
        justify-content: flex-end;
        margin-right: 15%;
        margin-top: 20px;
    }

    .comments_section {
        text-align: center;
        margin-top: 50px;
        background-color: #f2f2f2;
        padding: 20px;
    }

    .comments_count {
        text-align: left;
        font-size: 20px;
        margin-left: 15%;
        padding-top: 10px;
    }

    .comment_form {
        display: flex;
        justify-content: center;
        align-items: center;
        margin-top: 20px;
    }

    .comment_form textarea {
        width: 70%;
        height: 100px;
        margin-left: 100px;
    }

    .comment_form button {
        padding: 10px 20px;
        background-color: red;
        color: white;
        border: none;
        cursor: pointer;
    }

    .comment {
        text-align: left;
        margin: 20px 15%;
        padding: 10px;
        border-bottom: 1px solid #ddd;
    }

    .comment_info {
        margin-bottom: 10px;
    }

    .comment_author {
        margin-right: 20px;
    }

    .comment_content {
        margin-left: 10px;
    }
</style>

</html>