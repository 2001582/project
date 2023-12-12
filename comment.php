<?php 
session_start();
$conn = oci_connect('sqldb', '1234', 'localhost/XE', 'AL32UTF8');
if (!isset($_SESSION['user_id'])) {
    die('로그인이 필요합니다.');
}
$user_id = $_SESSION['user_id'];
$post_id = $_POST['post_id'];
if (!isset($_POST['comment']) || $_POST['comment'] === '') {
    die('댓글을 입력하세요.');
}
$comment = $_POST['comment'];

$sql = "INSERT INTO comments (comment_id, post_id, user_id, c_content) VALUES (comment_seq.NEXTVAL, :post_id, :user_id, :c_content)";
$stmt = oci_parse($conn, $sql);

oci_bind_by_name($stmt, ':user_id', $user_id, -1, SQLT_CHR);
oci_bind_by_name($stmt, ':post_id', $post_id, -1, SQLT_INT);
oci_bind_by_name($stmt, ':c_content', $comment, -1, SQLT_CHR); 

oci_execute($stmt);
$error = oci_error($stmt);
if ($error) {
    var_dump($error);
    exit();
}

header("Location: postDetail.php?post_id=" . $post_id);
exit();
?>