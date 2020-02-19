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
        return (-1);
    }

    function    auth($login, $passwd)
    {
        $file = unserialize(file_get_contents("../private/passwd"));
        $hash = hash('whirlpool', $passwd);
        $pos = search_user($file, $login);
        if ($pos == -1)
            return (FALSE);
        if ($hash != $file[$pos]['passwd'])
            return (FALSE);
        return (TRUE);
    }
?>