<?php
    include('auth.php');
    session_start();
    $login = $_GET['login'];
    $passwd = $_GET['passwd'];
    if (auth($login, $passwd) == TRUE)
    {
        
        extract($_GET);
        $_SESSION['loggued_on_user'] = $_GET['login'];
        echo "OK\n";
    }
    else
    {
        echo "ERROR\n";
    }
?>
