#!/usr/bin/php
<?php
    function    convertion($date, $month)
    {
        $i = 0;
        while (isset($month[$i]))
        {
            if (strcmp($month[$i], strtolower($date[2])) == 0)
                break ;
            $i++;
        }
        $i++;
        echo mktime($date[4], $date[5], $date[6], $i, $date[1], $date[3]);
    }
    if ($argc == 1)
    {
        exit (1);
    }
    date_default_timezone_set('Europe/Paris');
    $day = array("lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi", "dimanche");
    $month = array("janvier", "fevrier", "mars", "avril", "mai", "juin", "juillet", "aout", "septembre", "octobre", "novembre", "decembre");
    $date = preg_split("#[\s:]#", $argv[1]);
    $ok = 2;
    $date[2] = str_replace('é', 'e', $date[2]);
    $date[2] = str_replace('û', 'u', $date[2]);
    if (in_array(strtolower($date[0]), $day))
    {
        if (preg_match("#^[0-9]+$#", $date[1]) && $date[1] < 30)
        {
            if (in_array(strtolower($date[2]), $month) )
            {
                if (preg_match("#\d{4}#", $date[3]) && $date[3] > 1970)
                {
                        if ((preg_match("#\d{2}#", $date[4]) && $date[4] < 24 && $date[4] >= 0) && (preg_match("#\d{2}#", $date[5]) && $date[5] < 60 && $date[5] >= 0) && (preg_match("#\d{2}#", $date[6]) && $date[6] < 60  && $date[6] >= 0))
                        {
                            $ok = 1;
                            convertion($date, $month);
                        }
                } 
            }
        }
    }
    if ($ok == 2)
        echo "Wrong Format";
    echo "\n";
?>