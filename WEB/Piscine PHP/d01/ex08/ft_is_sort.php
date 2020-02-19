<?php
    function    ft_is_sort($tab)
    {
        $cmp = $tab;
        $cmp2 = $tab;
        $i = 0;
        rsort($cmp2);
        sort($cmp);
        while (isset($tab[$i]) AND $tab[$i] == $tab[$i + 1])
            $i++;
        if ($i + 1 == count($tab))
            return (1);
        if ($tab[$i] > $tab[$i + 1])
        {
            while ($tab[$i])
            {
                if ($tab[$i] != $cmp2[$i])
                    return (0);
                $i++;
            }
            return (1);
        }
        if ($tab[$i] < $tab[$i + 1])
        {
            while ($tab[$i])
            {
                if ($tab[$i] != $cmp[$i])
                    return (0);
                $i++;
            }
            return (1);
        }
    }
?>