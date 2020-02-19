#!/usr/bin/php
<?php
    if ($argc < 1)
    {
        echo "\n";
        exit (1);
    }
    $lien = "/(<a.*>)(.*)(<\/a)/i";
    $lienimg = "/(<a.*>)(.*)(<img)/i";
    $title = "/(<.*title=\")(.*)(\">)/i";
    function    replace_link($matches)
    {
        print_r($matches);
        $new = $matches[1].mb_strtoupper($matches[2]).$matches[3];
        return ($new);
    }

    function replace_title($matches) {
        $tab = explode('"', $matches[2]);
        $tab[0] = mb_strtoupper($tab[0]);
        $matches[2] = implode('"', $tab);
        $new = $matches[1].$matches[2].$matches[3];
        return ($new);
    }
    $fd = fopen($argv[1], "r");
    while (!feof($fd))
    {
        $line .= fgets($fd);
    }
    fclose($fd);
    if (preg_match($lien, $line))
        $line = preg_replace_callback($lien, replace_link, $line);
    if (preg_match($title, $line)) 
        $line = preg_replace_callback($title, replace_title, $line);
    if (preg_match($lienimg, $line)) 
        $line = preg_replace_callback($lienimg, replace_title, $line);

      echo $line;
?>