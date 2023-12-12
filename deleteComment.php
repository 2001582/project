<?php
session_start();
$conn = oci_connect('sqldb', '1234', 'localhost/XE', 'AL32UTF8');
if (!isset($_SESSION['user_id'])) {
    die('로그인이 필요합니다.');
}
$user_id = $_SESSION['user_id'];
$comment_id = $_GET['comment_id'];

$sql = "SELECT post_id FROM comments WHERE comment_id = :comment_id";
$stmt = oci_parse($conn, $sql);
oci_bind_by_name($stmt, ':comment_id', $comment_id, -1, SQLT_INT);
oci_execute($stmt);
$row = oci_fetch_array($stmt, OCI_ASSOC + OCI_RETURN_NULLS);
$post_id = $row['POST_ID'];

$sql = "DELETE FROM comments WHERE comment_id = :comment_id AND user_id = :user_id";
$stmt = oci_parse($conn, $sql);

oci_bind_by_name($stmt, ':user_id', $user_id, -1, SQLT_CHR);
oci_bind_by_name($stmt, ':comment_id', $comment_id, -1, SQLT_INT);

oci_execute($stmt);
$error = oci_error($stmt);
if ($error) {
    var_dump($error);
    exit();
}

header("Location: postDetail.php?post_id={$post_id}"); 
exit();
?>