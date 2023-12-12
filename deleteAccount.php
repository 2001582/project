<?php
session_start();

if (isset($_SESSION['loggedin'])) {
    $user_id = $_SESSION['user_id'];

    $conn = oci_connect('sqldb', '1234', 'localhost/XE', 'AL32UTF8');

    $sql = "DELETE FROM comments WHERE user_id = :user_id";
    $stmt = oci_parse($conn, $sql);
    oci_bind_by_name($stmt, ':user_id', $user_id, -1, SQLT_CHR);
    oci_execute($stmt);

    $sql = "DELETE FROM likes WHERE user_id = :user_id";
    $stmt = oci_parse($conn, $sql);
    oci_bind_by_name($stmt, ':user_id', $user_id, -1, SQLT_CHR);
    oci_execute($stmt);

    $sql = "DELETE FROM bookmarks WHERE user_id = :user_id";
    $stmt = oci_parse($conn, $sql);
    oci_bind_by_name($stmt, ':user_id', $user_id, -1, SQLT_CHR);
    oci_execute($stmt);

    $sql = "SELECT post_id FROM posts WHERE user_id = :user_id";
    $stmt = oci_parse($conn, $sql);
    oci_bind_by_name($stmt, ':user_id', $user_id, -1, SQLT_CHR);
    oci_execute($stmt);
    while ($row = oci_fetch_array($stmt, OCI_ASSOC)) {
        $post_id = $row['POST_ID'];
        $sql = "DELETE FROM photos WHERE post_id = :post_id";
        $stmt2 = oci_parse($conn, $sql);
        oci_bind_by_name($stmt2, ':post_id', $post_id, -1, SQLT_CHR);
        oci_execute($stmt2);
    }
    $sql = "DELETE FROM posts WHERE user_id = :user_id";
    $stmt = oci_parse($conn, $sql);
    oci_bind_by_name($stmt, ':user_id', $user_id, -1, SQLT_CHR);
    oci_execute($stmt);

    $sql = "DELETE FROM users WHERE user_id = :user_id";
    $stmt = oci_parse($conn, $sql);
    oci_bind_by_name($stmt, ':user_id', $user_id, -1, SQLT_CHR);
    oci_execute($stmt);

    $_SESSION = array();
    session_destroy();

    header("Location: mainHTML.php");
    exit;
} else {
    header("Location: mainHTML.php");
    exit;
}
?>