<?php session_start(); ?>
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
</head>

<body class="sub_page">
  <div class="header_area">
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

  <style>
    .form-container {
      display: flex;
      flex-direction: column;
      align-items: center;
      justify-content: center;
      height: 100vh;
    }

    .form-container form {
      display: flex;
      flex-direction: column;
      width: 50%;
    }

    .form-container textarea {
      height: 200px;
    }

    .form-container input[type="submit"] {
      background-color: #FF0000;
      color: white;
      padding: 10px;
      border: none;
      cursor: pointer;
    }

    .form-container input[type="submit"]:hover {
      background-color: #FF4500;
    }
  </style>

  <div class="form-container">
    <form action="writePost.php" method="post" enctype="multipart/form-data">
      <label for="title">제목:</label><br>
      <input type="text" id="title" name="title"><br>
      <label for="category">카테고리:</label><br>
      <select id="category" name="category">
        <?php
        $conn = oci_connect('sqldb', '1234', 'localhost/XE', 'AL32UTF8');
        $stmt = oci_parse($conn, "SELECT category_name FROM categories");
        oci_execute($stmt);

        while (($row = oci_fetch_array($stmt, OCI_BOTH)) != false) {
          echo "<option value=\"$row[0]\">$row[0]</option>";
        }
        ?>
      </select><br>
      <label for="content">내용:</label><br>
      <textarea id="content" name="content"></textarea><br>
      <label for="file">사진 업로드:</label>
      <input type="file" id="file" name="file"><br>
      <input type="submit" value="글 작성">
    </form>
  </div>
</body>

</html>