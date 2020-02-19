#!/usr/bin/php
<?php
$handle = fopen ("php://stdin","r");
    while ($line != EOF)
    {
        echo "Entrez un nombre: ";
        $handle = fopen ("php://stdin","r");
        $line = fgets(STDIN);
        $line = trim($line);

        if (is_numeric(trim($line)))
        {
            if ($line[strlen($line) - 1] % 2 == 0)
                echo ("Le chiffre $line est Pair\n");
            else
                echo ("Le chiffre $line est Impair\n");
        }
        else
        {
            if (feof(STDIN))
            {
                echo "\n";
                exit (0);
            }
            echo ("'$line' n'est pas un chiffre\n");
        }
    }
?>