#!/usr/bin/php
<?php
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
    sort($tab);
    foreach ($tab as $elem)
    {
        echo "$elem\n";
    }
?>