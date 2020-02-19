#!/usr/bin/php
<?php
    
    function    ft_split($str)
    {
        $tmp = explode(" ", $str);
        $tab = array_filter($tmp, 'strlen');
        sort($tab);
        return ($tab);
    }
    print_r(ft_split($argv[1]));
?>