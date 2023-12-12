<?php
session_start();

if (isset($_POST['title'], $_POST['category'], $_POST['content'])) {
    $conn = oci_connect('sqldb', '1234', 'localhost/XE', 'AL32UTF8');

    $stmt = oci_parse($conn, "SELECT category_id FROM categories WHERE category_name = :category");
    oci_bind_by_name($stmt, ':category', $_POST['category']);
    oci_execute($stmt);
    $row = oci_fetch_array($stmt, OCI_BOTH);
    $category_id = $row[0];

     $stmt = oci_parse($conn, "INSERT INTO posts (post_id, user_id, category_id, title, p_content) VALUES (post_id_seq.nextval, :user_id, :category_id, :title, :content)");
     $user_id = $_SESSION['user_id']; 
     oci_bind_by_name($stmt, ':user_id', $user_id);
     oci_bind_by_name($stmt, ':category_id', $category_id);
     oci_bind_by_name($stmt, ':title', $_POST['title']);
     oci_bind_by_name($stmt, ':content', $_POST['content']);
     oci_execute($stmt);

    if (isset($_FILES['file']) && $_FILES['file']['error'] === UPLOAD_ERR_OK) {
        $file_tmp_name = $_FILES['file']['tmp_name'];
        $file_name = $_FILES['file']['name'];
        $file_size = $_FILES['file']['size'];
        $file_type = $_FILES['file']['type'];
        $target_dir = "uploads/";

        $allowed_extensions = array('jpg', 'jpeg', 'png', 'gif');
        $file_extension = pathinfo($file_name, PATHINFO_EXTENSION);
        if (!in_array($file_extension, $allowed_extensions)) {
            exit("Error: Invalid file extension");
        }

        if ($file_size > 2 * 1024 * 1024) {
            exit("Error: File size is too large");
        }

        $file_path = $target_dir . basename($file_name);
        if (move_uploaded_file($file_tmp_name, $file_path)) {
            $stmt = oci_parse($conn, "INSERT INTO photos (photo_id, post_id, file_path) VALUES (photo_id_seq.nextval, post_id_seq.currval, :file_path)");
            oci_bind_by_name($stmt, ':file_path', $file_path);
            oci_execute($stmt);
        } else {
            exit("Error: Failed to upload file");
        }
    }

    header("Location: mainHTML.php");
    exit;
}
header("Location: writePostHTML.php");
exit;
?>
