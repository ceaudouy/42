<?php
    $action = $_GET['action'];
    $name = $_GET['name'];
    $value = $_GET['value'];
    if ($action == "set") {
        setcookie($name, $value, time()+3600);
    }
    if ($action == "get") {
        if (isset($_COOKIE[$name]))
            echo "$_COOKIE[$name]\n";
    }
    if ($action == "del") {
        setcookie($name, "", time()-3600);
    }
?>
