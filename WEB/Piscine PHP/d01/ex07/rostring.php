#!/usr/bin/php
<?php
    if ($argc < 2)
        exit (1);
    $tmp = explode(" ", $argv[1]);
    $tab = array_filter($tmp, 'strlen');
    $i = 1;
    while ($tab[$i])
    {
        echo "$tab[$i] ";
        $i++;
    }
    echo "$tab[0]\n";
?>