<?php
    $img =  file_get_contents("../img/42.png");
    $img = 'data:image/png;base64,'.base64_encode($img);
    if (!isset($_SERVER['PHP_AUTH_USER'])) {
        header('WWW-Authenticate: Basic realm="Espace membres"');
        header('HTTP/1.0 401 Unauthorized');
    }
    else {
        if ($_SERVER['PHP_AUTH_USER'] == "zaz" AND $_SERVER['PHP_AUTH_PW'] == "jaimelespetitsponeys")
            echo "<html><body>\nBonjour Zaz<br />\n<img src='".$img."'>\n</body></html>\n";    
        else
            echo "<html><body>Cette zone est accessible uniquement aux membres du site</body></html>\n";
    }
?>
