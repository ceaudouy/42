<?php
        function    search_user($file, $login)
        {
            $i = 0;
            while (isset($file[$i]))
            {
                if ($file[$i]['login'] == $login)
                    return ($i);
                    $i++;
            }
            echo "ERROR\n";
            exit (1);
        }

        if (isset($_POST['login']) AND !empty($_POST['login']) AND isset($_POST['oldpw']) AND !empty($_POST['oldpw']) AND isset($_POST['newpw']) AND !empty($_POST['newpw']) AND isset($_POST['submit']) AND !empty($_POST['submit'])) {
        $file = unserialize(file_get_contents("../private/passwd"));
        $login = $_POST['login'];
        $oldpw = hash('whirlpool', $_POST['oldpw']);
        $newpw = hash('whirlpool', $_POST['newpw']);
        $pos = search_user($file, $login);
        if ($file[$pos]['passwd'] != $oldpw || $file[$pos]['passwd'] == $newpw)
        {
            echo "ERROR\n";
            exit (1);
        }
        $file[$pos]['passwd'] = $newpw;
        $file = serialize($file);
        file_put_contents("../private/passwd", $file, FILE_USE_INCLUDE_PATH);
        echo "OK\n";
    }
    else
        echo "ERROR\n";
?>