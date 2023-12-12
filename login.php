<?php
session_start(); 

error_reporting(E_ALL);
ini_set('display_errors', 'On');

$conn = oci_connect('sqldb', '1234', 'localhost/XE', 'AL32UTF8');
if (!$conn) {
  $e = oci_error();
  trigger_error(htmlentities($e['message'], ENT_QUOTES), E_USER_ERROR);
}

if(!empty($_POST)){
  $sql = "SELECT * FROM users WHERE user_id = :userId AND user_password = :userPassword";

  $stmt = oci_parse($conn, $sql);

  oci_bind_by_name($stmt, ':userId', $_POST['user_id']);
  oci_bind_by_name($stmt, ':userPassword', $_POST['user_password']);

  $r = oci_execute($stmt);
  if (!$r) {
    $e = oci_error($stmt);
    trigger_error(htmlentities($e['message'], ENT_QUOTES), E_USER_ERROR);
  }

  $row = oci_fetch_array($stmt, OCI_ASSOC+OCI_RETURN_NULLS);

  if($row){ 
    $_SESSION['loggedin'] = true; 
    $_SESSION['user_id'] = $_POST['user_id']; 
    $_SESSION['user_name'] = $row['USER_NAME'];
    header("Location: mainHTML.php"); 
  }
  else{
    echo "아이디 혹은 비밀번호가 잘못되었습니다."; 
  }
}
?>  