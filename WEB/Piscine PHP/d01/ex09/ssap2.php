#!/usr/bin/php
<?php
    function    my_sort($s1, $s2)
    {
        $cmp = "abcdefghijklmnopqrstuvwxyz0123456789!\"#$%&'()*+,-./:;<=>?@[\]^_`{|}~";
        $c1 = strtolower($s1);
        $c2 = strtolower($s2);
        $i = 0;
        while (($i < strlen($s1)) || ($i < strlen($s2)))
        {
            if (empty($c1[$i]))
                return (-1);
            if (empty($c2[$i]))
                return (1);
            $sc1 = strpos($cmp, $c1[$i]);
            $sc2 = strpos($cmp, $c2[$i]);
            if ($sc1 < $sc2)
                return (-1);
            else if ($sc1 > $sc2)
                return (1);
            else
                $i++;
        }
        return (0);
    }
    if ($argc < 2)
    {
        exit (1);
    }
    $i = 2;
    $tmp = explode (" ", $argv[1]);
    $tab = array_filter($tmp, 'strlen');
    while ($argv[$i])
    {
        $tmp = explode (" ", $argv[$i]);
        $temp = array_filter($tmp, 'strlen');
        $tab = array_merge($temp, $tab);
        $i++;
    }
    usort($tab, "my_sort");
    foreach ($tab as $elem)
    {
        echo "$elem\n";
    }
?>