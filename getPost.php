<?php
$conn = oci_connect('sqldb', '1234', 'localhost/XE', 'AL32UTF8');
if (!$conn) {
    $e = oci_error();
    trigger_error(htmlentities($e['message'], ENT_QUOTES), E_USER_ERROR);
}
$results_per_page = 12;
$page = isset($_GET['page']) ? $_GET['page'] : 1;
$category_id = isset($_GET['category_id']) ? $_GET['category_id'] : 0;

$start_from = ($page - 1) * $results_per_page;
$max_row = $start_from + $results_per_page;
$min_row = $start_from + 1;

$sql = "
SELECT a.*, ph.FILE_PATH FROM (
    SELECT p.*, ROWNUM rnum 
    FROM (
        SELECT * FROM posts 
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
oci_bind_by_name($stmt, ':min_row', $min_row, -1, SQLT_INT);
oci_bind_by_name($stmt, ':max_row', $max_row, -1, SQLT_INT);
oci_execute($stmt);

$posts = array();
while ($row = oci_fetch_array($stmt, OCI_ASSOC + OCI_RETURN_NULLS)) {
    array_unshift($posts, $row);
}

echo json_encode($posts);
?>
