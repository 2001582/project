<?php
session_start();
session_destroy();
header("Location: mainHTML.php"); 
?>