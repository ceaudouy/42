#!/usr/bin/php
<?php
    if ($argc != 4)
    {
        echo "Incorrect Parameters\n";
        exit (1);
    }
    if ((is_numeric($argv[1]) == FALSE) || (is_numeric($argv[3]) == FALSE))
        exit (1);
    if (preg_match("#[+-/*%]#", $argv[2]) == FALSE)
        exit (1);
    $argv[2] = trim($argv[2]);
    if ($argv[2] == "+")
        echo intval($argv[1]) + intval($argv[3])."\n";
    if ($argv[2] == "-")
        echo intval($argv[1]) - intval($argv[3])."\n";
    if ($argv[2] == "/") {
        if ($argv[3] == 0)
            exit (1);        
        echo intval($argv[1]) / intval($argv[3])."\n";
    }
    if ($argv[2] == "*")
        echo intval($argv[1]) * intval($argv[3])."\n";
    if ($argv[2] == "%") {
        if ($argv[3] == 0)
            exit (1);        
        echo intval($argv[1]) % intval($argv[3])."\n";
    }
?>