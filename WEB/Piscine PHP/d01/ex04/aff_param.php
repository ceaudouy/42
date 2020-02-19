#!/usr/bin/php
<?php
    $i = 0;
    foreach($argv as $tab)
    {
        if ($i == 0)
            $i++;
        else
            echo "$tab\n";
    }
?>