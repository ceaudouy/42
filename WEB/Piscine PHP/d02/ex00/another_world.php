#!/usr/bin/php
<?php
    if ($argc == 1)
    {
        exit (1);
    }
    $j = 0;
    $str = preg_split("/[\t\s]+/", $argv[1]);
    $str = array_filter($str, 'strlen');
    $i = count($str);
    foreach ($str as $elem)
    {
        echo "$elem";
        if ($j < $i - 1)
            echo " ";
        $j++;
    }
    echo "\n";
?>