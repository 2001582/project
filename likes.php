<?php
session_start();
$conn = oci_connect('sqldb', '1234', 'localhost/XE', 'AL32UTF8');

$post_id = $_POST['post_id'];
$user_id = $_POST['user_id'];

$sql = "SELECT * FROM likes WHERE post_id = :post_id AND user_id = :user_id";
$stmt = oci_parse($conn, $sql);
oci_bind_by_name($stmt, ':post_id', $post_id, -1, SQLT_INT);
oci_bind_by_name($stmt, ':user_id', $user_id, -1, SQLT_CHR);
oci_execute($stmt);

if(oci_fetch_array($stmt, OCI_ASSOC + OCI_RETURN_NULLS)) {
    $sql = "DELETE FROM likes WHERE post_id = :post_id AND user_id = :user_id";
} else {
    $sql = "INSERT INTO likes (post_id, user_id) VALUES (:post_id, :user_id)";
}

$stmt = oci_parse($conn, $sql);
oci_bind_by_name($stmt, ':post_id', $post_id, -1, SQLT_INT);
oci_bind_by_name($stmt, ':user_id', $user_id, -1, SQLT_CHR);
oci_execute($stmt);
?>