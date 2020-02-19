<?php
    function compte() {
        if (file_exists("../private/passwd"))
            $file = unserialize(file_get_contents('../private/passwd'));
        $i = 0;
        while (isset($file[$i])) {
            $i++;
        }
        return ($i);
    }

    function    check_user($file, $content)
    {
        $i = 0;
        while (isset($file[$i]))
        {
            if ($file[$i]['login'] == $content['login'])
                return (0);
            $i++;
        }
        return (1);
    }

    if (isset($_POST['login']) AND !empty($_POST['login']) AND isset($_POST['passwd']) AND !empty($_POST['passwd']) AND isset($_POST['submit']) AND !empty($_POST['submit'])) {
        if (!file_exists("../private"))
            mkdir("../private");
        $content['login'] = $_POST['login'];
        $content['passwd'] = hash('whirlpool', $_POST['passwd']);
        if (file_exists("../private/passwd"))
            $file = unserialize(file_get_contents("../private/passwd"));
        if (check_user($file, $content) == 0)  {
            echo "ERROR\n";
            exit (0);
        }
        $file[compte()] = $content;
        $file = serialize($file);
        file_put_contents("../private/passwd", $file, FILE_USE_INCLUDE_PATH);
        echo "OK\n";
    }
    else
        echo "ERROR\n";
?>