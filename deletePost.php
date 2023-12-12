<?php
session_start();
$conn = oci_connect('sqldb', '1234', 'localhost/XE', 'AL32UTF8');

$post_id = $_GET['post_id'];

$sql = "DELETE FROM likes WHERE post_id = :post_id";
$stmt = oci_parse($conn, $sql);
oci_bind_by_name($stmt, ':post_id', $post_id, -1, SQLT_INT);
oci_execute($stmt);

$sql = "DELETE FROM bookmarks WHERE post_id = :post_id";
$stmt = oci_parse($conn, $sql);
oci_bind_by_name($stmt, ':post_id', $post_id, -1, SQLT_INT);
oci_execute($stmt);

$sql = "DELETE FROM comments WHERE post_id = :post_id";
$stmt = oci_parse($conn, $sql);
oci_bind_by_name($stmt, ':post_id', $post_id, -1, SQLT_INT);
oci_execute($stmt);

$sql = "DELETE FROM photos WHERE post_id = :post_id";
$stmt = oci_parse($conn, $sql);
oci_bind_by_name($stmt, ':post_id', $post_id, -1, SQLT_INT);
oci_execute($stmt);

$sql = "DELETE FROM posts WHERE post_id = :post_id";
$stmt = oci_parse($conn, $sql);
oci_bind_by_name($stmt, ':post_id', $post_id, -1, SQLT_INT);
oci_execute($stmt);

header('Location: mainHTML.php');
?>