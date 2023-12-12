<?php
$conn = oci_connect('sqldb', '1234', 'localhost/XE', 'AL32UTF8');
if (!$conn) {
  $e = oci_error();
  trigger_error(htmlentities($e['message'], ENT_QUOTES), E_USER_ERROR);
}
$user_id = $_POST['user_id'];

$check_query = "SELECT COUNT(*) FROM users WHERE user_id = :userId";
$check_stmt = oci_parse($conn, $check_query);
oci_bind_by_name($check_stmt, ':userId', $user_id);
oci_execute($check_stmt);
$result = oci_fetch_assoc($check_stmt);

if ($result['COUNT(*)'] > 0) {
  echo "이미 존재하는 아이디입니다.";
  exit; 
}

$sql = "INSERT INTO users (user_id, user_name, user_password, user_phoneNumber) VALUES (:userId, :userName, :userPassword, :userPhoneNumber)";
$stmt = oci_parse($conn, $sql);

oci_bind_by_name($stmt, ':userId', $_POST['user_id']);
oci_bind_by_name($stmt, ':userName', $_POST['user_name']);
oci_bind_by_name($stmt, ':userPassword', $_POST['user_password']);
oci_bind_by_name($stmt, ':userPhoneNumber', $_POST['user_phoneNumber']);

$r = oci_execute($stmt);
if (!$r) {
  $e = oci_error($stmt);
  trigger_error(htmlentities($e['message'], ENT_QUOTES), E_USER_ERROR);
}

echo "회원가입이 성공적으로 완료되었습니다.";
echo "<button onclick=\"location.href='mainHTML.php'\">초기화면으로 가기</button>";
?>