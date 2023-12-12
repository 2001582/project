<?php
session_start();
$conn = oci_connect('sqldb', '1234', 'localhost/XE', 'AL32UTF8');

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $post_id = $_POST['post_id'];
    $user_id = $_POST['user_id'];

    $sql = "SELECT * FROM bookmarks WHERE user_id = :user_id AND post_id = :post_id";
    $stmt = oci_parse($conn, $sql);
    oci_bind_by_name($stmt, ':user_id', $user_id, -1, SQLT_CHR);
    oci_bind_by_name($stmt, ':post_id', $post_id, -1, SQLT_INT);
    oci_execute($stmt);

    if(oci_fetch_array($stmt, OCI_ASSOC + OCI_RETURN_NULLS)) {
        $sql = "DELETE FROM bookmarks WHERE user_id = :user_id AND post_id = :post_id";
        $status = 'deleted';
    } else {
        $sql = "INSERT INTO bookmarks (user_id, post_id) VALUES (:user_id, :post_id)";
        $status = 'added';
    }

    $stmt = oci_parse($conn, $sql);
    oci_bind_by_name($stmt, ':user_id', $user_id, -1, SQLT_CHR);
    oci_bind_by_name($stmt, ':post_id', $post_id, -1, SQLT_INT);
    oci_execute($stmt);

    echo $status;
}
?>
