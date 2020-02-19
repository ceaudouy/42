#!/usr/bin/php
<?php
    if ($argc != 2)
    {
        echo "Incorrect Parameters\n";
        exit (1);
    }
    $nbr = trim($argv[1]);
    
    if (preg_match("#/#", $nbr))
    {
        $tab = explode("/", $nbr);
        if ($tab[1] == 0) {
            exit (1);
        }
        if (is_numeric(trim($tab[0])) && is_numeric(trim($tab[1])))
            $result = intval($tab[0]) / intval($tab[1]);
        else
            echo "Syntax Error";
    }
    else if (preg_match("#\*#", $nbr))
    {
        $tab = explode("*", $nbr);
        if (is_numeric(trim($tab[0])) && is_numeric(trim($tab[1])))
            $result = intval($tab[0]) * intval($tab[1]);
        else
            echo "Syntax Error";
    }
    else if (preg_match("#%#", $nbr))
    {
        $tab = explode("%", $nbr);
        if ($tab[1] == 0) {
            exit (1);
        }
        if (is_numeric(trim($tab[0])) && is_numeric(trim($tab[1])))
            $result = intval($tab[0]) % intval($tab[1]);
        else
            echo "Syntax Error";
    }
    else if (preg_match("'\+'", $nbr))
    {
        $tab = explode("+", $nbr);
        if (is_numeric(trim($tab[0])) && is_numeric(trim($tab[1])))
            $result = intval($tab[0]) + intval($tab[1]);
        else
            echo "Syntax Error";
    }
    else if (preg_match("#-#", $nbr))
    {
        $tab = explode("-", $nbr);
        $i = 0;
        while ($tab[$i])
        {
            $tab[$i] = trim($tab[$i]);
            $i++;
        }
        $i = count($tab);
        if ($tab[0] == "")
            $nb1 = -$tab[1];
        else
            $nb1 = $tab[0];
        if (preg_match("# #", $tab[$i - 2]) || $tab[$i - 2] == "")
            $nb2 = -$tab[$i - 1];
        else
            $nb2 = $tab[$i - 1];
        $nb1 = trim($nb1);
        $nb2 = trim($nb2);
        if (is_numeric(trim($nb1)) && is_numeric(trim($nb2)))
            $result = intval($nb1) - intval($nb2);
        else
            echo "Syntax Error";
    }
    else
        echo "Syntax Error";
    echo "$result\n";
?>