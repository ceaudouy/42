#!/usr/bin/php
<?php
    function    ft_moyenne($tab)
    {

        $i = 0;
        $j = 0;
        $result = 0;
        while ($tab[$i])
        {
            if (is_numeric($tab[$i][1]) && $tab[$i][2] !== "moulinette")
            {
                    $result = $result + $tab[$i][1];
                    $j++;
            }
            $i++;
        }
        $result = $result / $j;
        echo "$result\n";
    }

    function    ft_user($tab)
    {
        $i = 1;
        $result = 0;
        $j = 0;
        $name = $tab[1][0];
        while ($tab[$i])
        {
            
            if ($name !== $tab[$i][0])
            {
                $result = $result / $j;
                echo "$name:$result\n";
                $name = $tab[$i][0];
                $result = 0;
                $j = 0;
            }
            if (is_numeric($tab[$i][1]) && $tab[$i][2] !== "moulinette")
            {
                    $result = $result + $tab[$i][1];
                    $j++;
            }
            $i++;
        }
        $result = $result / $j;
        echo "$name:$result\n";
    }
    
    function    ft_mouli($tab)
    {
        $i = 1;
        $result = 0;
        $j = 0;
        $m = 0;
        $name = $tab[1][0];
        $mouli = array();
        $start = 0;
        while ($tab[$start])
        {
            if ($tab[$start][2] == "moulinette")
            {
                $mouli[] = $tab[$start][1];
            }
            $start++;
        }
        while ($tab[$i])
        {
            if ($name !== $tab[$i][0])
            {
                $result = $result / $j;
                echo "$name:$result\n";
                $name = $tab[$i][0];
                $result = 0;
                $j = 0;
                $m++;
            }
            if (is_numeric($tab[$i][1]) && $tab[$i][2] !== "moulinette")
            {
                    $result += $tab[$i][1] - $mouli[$m];
                    $j++;
            }
            $i++;
        }
        $result = $result / $j;
        echo "$name:$result\n";
    }

    if ($argc < 2)
        exit (1);
    while ($line = fgets(STDIN))
    {
        $tab[] = trim($line);
    }
    $i = 0;
    sort($tab);
    while ($tab[$i])
    {
        $tab[$i] = explode(";", $tab[$i]);
        $i++;
    }
    if ($argv[1] == "moyenne")
        ft_moyenne($tab);
    if ($argv[1] == "moyenne_user")
        ft_user($tab);
    if ($argv[1] == "ecart_moulinette")
        ft_mouli($tab);
?>