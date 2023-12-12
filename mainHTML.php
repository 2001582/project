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

<body>
  <div class="header_area">
    <!-- 헤더 영역 -->
    <header class="header_section">
      <div class="container">
        <nav class="navbar navbar-expand-lg custom_nav-container pt-3">
          <!-- 로고-->
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

    <!-- 메인 영역 -->
    <section class=" main_section position-relative">
      <div id="carouselExampleIndicators" class="carousel slide" data-ride="carousel">
        <div class="carousel-inner">
          <div class="carousel-item active">
            <div class="container">
              <div class="row">
                <div class="col-md-7">
                  <div class="detail-box">
                    <div>
                      <h1>
                        환영합니다. <br>
                        <span>
                          여러분의 공간을 공유해주세요
                        </span>
                      </h1>
                      <p>
                        데스크 셋업, 인테리어, 소품 등에 대한 사진을 서로 나누며
                      </p>
                      <p>
                        머무는 공간을 더 아름답게 가꾸어보아요
                      </p>
                      <div class="btn-box">
                        <a href="loginHTML.php" class="btn-1">
                          함께하기
                        </a>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </section>
  </div>

  <?php
  $conn = oci_connect('sqldb', '1234', 'localhost/XE', 'AL32UTF8');
  $results_per_page = 12;

  $sort = isset($_GET['sort']) ? $_GET['sort'] : 'latest';
  $category_id = isset($_GET['category_id']) ? $_GET['category_id'] : 0;
  $search = isset($_GET['search']) ? $_GET['search'] : '';

  if (!isset($_GET['page'])) {
    $page = 1;
  } else {
    $page = $_GET['page'];
  }

  $start_from = ($page - 1) * $results_per_page;
  $max_row = $start_from + $results_per_page;
  $min_row = $start_from + 1;

  $sql = "SELECT COUNT(*) AS cnt FROM posts";
  $stmt = oci_parse($conn, $sql);
  oci_execute($stmt);
  $row = oci_fetch_assoc($stmt);
  $num_of_results = $row['CNT'];
  $number_of_pages = ceil($num_of_results / $results_per_page);

  $where_clause = "";
  if ($category_id != 0) {
    $where_clause .= " WHERE category_id = :category_id";
  }
  if ($search != '') {
    $where_clause .= ($where_clause != "" ? " AND" : " WHERE") . " (TITLE LIKE :search OR p_content LIKE :search)";
  }

  $sql = "
  SELECT a.*, ph.FILE_PATH FROM (
      SELECT p.*, ROWNUM rnum 
      FROM (
          SELECT * FROM posts" .
    $where_clause . "
          ORDER BY " . ($sort == 'popular' ? "(SELECT COUNT(*) FROM likes l WHERE l.post_id = posts.post_id) DESC" : "p_created_at DESC") . "
      ) p 
      WHERE ROWNUM <= :max_row
  ) a LEFT JOIN photos ph ON a.post_id = ph.post_id 
  WHERE a.rnum >= :min_row
  " . ($sort == 'popular' ? "ORDER BY (SELECT COUNT(*) FROM likes l WHERE l.post_id = a.post_id) DESC" : "ORDER BY a.p_created_at DESC");

  $stmt = oci_parse($conn, $sql);
  if ($category_id != 0) {
    oci_bind_by_name($stmt, ':category_id', $category_id, -1, SQLT_INT);
  }
  if ($search != '') {
    $search = '%' . $search . '%';
    oci_bind_by_name($stmt, ':search', $search, -1, SQLT_CHR);
  }
  oci_bind_by_name($stmt, ':min_row', $min_row, -1, SQLT_INT);
  oci_bind_by_name($stmt, ':max_row', $max_row, -1, SQLT_INT);
  oci_execute($stmt);

  $posts = array();
  while ($row = oci_fetch_array($stmt, OCI_ASSOC + OCI_RETURN_NULLS)) {
    $posts[] = $row;
  }

  $sql = "SELECT * FROM categories";
  $stmt = oci_parse($conn, $sql);
  oci_execute($stmt);

  $categories = array();
  while ($row = oci_fetch_array($stmt, OCI_ASSOC + OCI_RETURN_NULLS)) {
    $categories[] = $row;
  }
  ?>

  <!--게시판 영역-->
  <section class="board_section layout_padding">
    <section class="post_section ">
      <div class="container">
        <div class="heading_container">
          <h2>
            게시글
          </h2>
        </div>
        <div style="display: flex; justify-content: flex-start;">
          <form method="get" action="" style="margin-right: 20px;">
            <select name="sort" onchange="this.form.submit()">
              <option value="latest" <?php echo $sort == 'latest' ? 'selected' : ''; ?>>최신순</option>
              <option value="popular" <?php echo $sort == 'popular' ? 'selected' : ''; ?>>인기순</option>
            </select>
          </form>

          <form method="get" action="">
            <select name="category_id" onchange="this.form.submit()">
              <option value="0">전체</option>
              <?php
              foreach ($categories as $category) {
                echo '<option value="' . $category['CATEGORY_ID'] . '"' . ($category_id == $category['CATEGORY_ID'] ? ' selected' : '') . '>' . $category['CATEGORY_NAME'] . '</option>';
              }
              ?>
              <input type="hidden" name="sort" value="<?php echo $sort; ?>">
            </select>
          </form>
        </div>

      </div>
      <div class="container">
        <div class="row">
          <div class="col-md-12">
            <div class="board-container">
              <?php
              for ($i = 0; $i < count($posts); $i++) {
                $row = $posts[$i];
                ?>
                <div class="board-item">
                  <a href="postDetail.php?post_id=<?php echo $row['POST_ID']; ?>">
                    <img src="<?php echo $row['FILE_PATH']; ?>" alt="게시글 이미지">
                  </a>
                  <p>
                    <?php echo htmlspecialchars($row['TITLE'], ENT_QUOTES, 'UTF-8'); ?>
                  </p>
                </div>
                <?php
              }
              ?>
            </div>
          </div>
        </div>
      </div>
    </section>
  </section>

  <!-- 페이지네이션 -->
  <div class="row">
    <div class="col-md-12">
      <div class="pagination">
        <?php
        for ($page = 1; $page <= $number_of_pages; $page++) {
          echo '<a href="mainHTML.php?page=' . $page . '&sort=' . $sort . '">' . $page . '</a> ';
        }
        ?>
      </div>
    </div>
  </div>

  <style>
    .search-center-container {
      display: flex;
      justify-content: center;
      align-items: center;
      height: 15vh;
    }

    .search-center-form {
      display: flex;
      justify-content: flex-start;
      align-items: center;
      width: 60%;
    }

    .search-input {
      flex-grow: 1;
    }
  </style>

  <!-- 검색창 및 글쓰기 버튼 -->
  <div class="search-center-container">
    <form method="GET" action="mainHTML.php" class="search-center-form">
      <input name="search" placeholder="검색" class="search-input">
      <button type="submit" class="register_btn">검색</button>
      <?php
      if (isset($_SESSION['loggedin'])) {
        echo '<a href="writePostHTML.php" class="register_btn">글쓰기</a>';
      } else {
        echo '<a href="loginHTML.php" class="register_btn">글쓰기</a>';
      }
      ?>
    </form>
  </div>

  <script type="text/javascript" src="js/bootstrap.js"></script>
</body>

</html>