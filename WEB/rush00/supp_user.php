<?php
session_start();
$_SESSION['loggued_on_user'] = "a";
    if (isset($_SESSION['loggued_on_user']) && !empty($_SESSION['loggued_on_user']))
    {
        include_once('lib.php');
        $id = $_GET['login'];
        $req = "DELETE FROM `Users` WHERE id = ".$id;
        $conn = sql_connect();
        mysqli_query($conn, $req);
        mysqli_close($conn);
        header("Location:admin.php");
    } else {
        header("Location:index.php");
    }
?>