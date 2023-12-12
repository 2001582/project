<?php
session_start();

if (isset($_SESSION['loggedin'])) {
  $user_id = $_SESSION['user_id'];

  $conn = oci_connect('sqldb', '1234', 'localhost/XE', 'AL32UTF8');
  $sql = "SELECT * FROM users WHERE user_id = :user_id";
  $stmt = oci_parse($conn, $sql);
  oci_bind_by_name($stmt, ':user_id', $user_id, -1, SQLT_CHR);
  oci_execute($stmt);
  $user = oci_fetch_array($stmt, OCI_ASSOC);
}
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
    <!-- header section strats -->
    <header class="header_section">
      <div class="container">
        <nav class="navbar navbar-expand-lg custom_nav-container pt-3">
          <a class="navbar-brand mr-5" href="mainHTML.php">
            <img src="images/logo.png" alt="">
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

  <!-- 유저 정보 영역 -->
  <section style="margin-top: 50px;">
    <div class="container">
      <h2>회원정보</h2>
      <div style="margin-bottom: 30px; margin-top: 30px;">
        <?php if (isset($user)): ?>
          <p>이름:
            <?= htmlspecialchars($user['USER_NAME'], ENT_QUOTES, 'UTF-8') ?>
          </p>
          <p>아이디:
            <?= htmlspecialchars($user['USER_ID'], ENT_QUOTES, 'UTF-8') ?>
          </p>
          <p>전화번호:
            <?= htmlspecialchars($user['USER_PHONENUMBER'], ENT_QUOTES, 'UTF-8') ?>
          </p>
        <?php endif; ?>
      </div>
      <a href="deleteAccount.php" class="btn btn-danger">회원탈퇴</a>
    </div>
  </section>

  <section style="margin-top: 50px;">
    <div class="container">
      <h2>나중에 볼 게시물</h2>
      <div id="bookmarkedPostList">
        <?php
        $sql = "SELECT post_id FROM bookmarks WHERE user_id = :user_id ORDER BY post_id DESC";
        $stmt = oci_parse($conn, $sql);
        oci_bind_by_name($stmt, ':user_id', $user_id, -1, SQLT_CHR);
        oci_execute($stmt);

        while ($row = oci_fetch_array($stmt, OCI_ASSOC)) {
          $post_id = $row['POST_ID'];

          $sql = "SELECT * FROM posts WHERE post_id = :post_id";
          $stmt2 = oci_parse($conn, $sql);
          oci_bind_by_name($stmt2, ':post_id', $post_id, -1, SQLT_CHR);
          oci_execute($stmt2);
          $post = oci_fetch_array($stmt2, OCI_ASSOC);

          $sql = "SELECT * FROM photos WHERE post_id = :post_id";
          $stmt3 = oci_parse($conn, $sql);
          oci_bind_by_name($stmt3, ':post_id', $post_id, -1, SQLT_CHR);
          oci_execute($stmt3);
          $photo = oci_fetch_array($stmt3, OCI_ASSOC);

          echo "<div class='post'>";
          echo "<a href='postDetail.php?post_id=" . $post_id . "'>";
          echo "<img src='" . htmlspecialchars($photo['FILE_PATH'], ENT_QUOTES, 'UTF-8') . "' alt='post photo'>";
          echo "</a>";
          echo "<h3>" . htmlspecialchars($post['TITLE'], ENT_QUOTES, 'UTF-8') . "</h3>";
          echo "</div>";
        }
        ?>
      </div>
    </div>
  </section>
</body>
<style>
  .post {
    width: 33.33%;
    float: left;
    box-sizing: border-box;
    padding: 10px;
    box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
  }

  .post img {
    width: 100%;
    height: 200px;
    object-fit: cover;
  }

  .post h3 {
    font-size: 16px;
    margin-top: 10px;
  }
</style>

</html>