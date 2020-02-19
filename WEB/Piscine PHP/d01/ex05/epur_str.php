#!/usr/bin/php
<?php
    if ($argc < 2)
        exit (1);

    $i = 1;
    $tmp = explode(" ", $argv[1]);
    $tab = array_filter($tmp, 'strlen');
    $str = implode("\t", $tab);

    $tmp = explode("\t", $str);
    $tab = array_filter($tmp, 'strlen');
    $len = count($tab);
    
    foreach($tab as $elem)
    {
        trim($elem);
        echo "$elem";
        if ($i < $len)
            echo " ";
            $i++;
    }
    echo "\n";
?>