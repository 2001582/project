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

  <!-- 회원가입 영역 -->
  <div class="body_bg layout_padding">
    <section class="contact_section">
      <div class="container">
        <div class="heading_container">
          <h2>회원가입</h2>
        </div>
      </div>
      <div class="container contact_bg layout_padding2-top">
        <div class="contact_form ">
          <form action="register.php" method="post">
            <input type="text" id="user_name" name="user_name" placeholder="이름"><br>
            <input type="text" id="user_id" name="user_id" placeholder="아이디"><br>
            <input type="password" id="user_password" name="user_password" placeholder="비밀번호"><br>
            <input type="text" id="user_phoneNumber" name="user_phoneNumber" placeholder="휴대폰 번호"><br>
            <button type="submit">가입하기</button>
          </form>
        </div>
      </div>
    </section>
  </div>

  <script type="text/javascript" src="js/bootstrap.js"></script>
</body>

</html>