#!/usr/bin/php
<?php
    if ($argc < 3)
        exit (1);
    $i = 2;
    $yes = 0;
    while ($argv[$i])
    {
        $tab = explode (":", $argv[$i]);
        $key = array_search($argv[1], $tab);
        if (is_numeric($key))
        {
            if ($key == 0)
                $value = $tab[1];
            $yes = 1;
        }
        $i++;
    }
    if ($yes === 1)
        echo "$value\n";
?>