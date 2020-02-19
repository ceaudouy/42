<?php
    session_start();
    if (isset($_SESSION['loggued_on_user']) AND !empty($_SESSION['loggued_on_user']))
    {
        echo $_SESSION['loggued_on_user']."\n";
    }
    else
        echo "ERROR\n";
?>