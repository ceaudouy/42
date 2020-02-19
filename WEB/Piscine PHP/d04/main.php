#!/usr/bin/php
<?php

echo "\033[35m ---------------------------------------------------------------------------------------\033[0m\n";
echo "\033[35m ---------------------------------------------------------------------------------------\033[0m\n";
echo "\033[35m|                                CREATERD by ==> AGASPARO <==                          |\033[0m\n";
echo "\033[35m ---------------------------------------------------------------------------------------\033[0m\n";
echo "\033[35m|                           Testors: lpelissi ceaudouy mascorpi                        |\033[0m\n";
echo "\033[35m----------------------------------------nom_fichier------------------------------------\033[0m\n";


$i = 0;
$tab[0] = 'index.php';
$tab[1] = 'index.html|create.php';
$tab[2] = 'index.html|modif.php';
$tab[3] = 'auth.php|login.php|logout.php|whoami.php';
$tab[4] = 'index.html|create.html|modif.html|auth.php|create.php|modif.php|login.php|logout.php|speak.php|chat.php';

while ($i < 5) {
	$e = explode("|", $tab[$i]);
	$a = 0;
	echo "Ex ".$i." : \n";
	while (isset($e[$a])) {
		$commade = "ex0".$i."/".$e[$a];
		if (file_exists($commade)) {
			echo "\tFichier ".$e[$a]." : \033[32m[OK]\033[0m\n";
		} else {
			echo "\tFichier ".$e[$a]." : \033[31m[non trouve]\033[0m\n";
		}
		$a++;
	}
	$i++;
}
echo "Lancement du script de correction dans 3 secondes ...\n";
sleep(3);

echo "\033[35m-------------------------------------------ex00------------------------------------\033[0m\n";
echo "test 1 : ";
$req = shell_exec("curl -v -c cook.txt 'localhost:8100/ex00/index.php' 2>&1");
if (preg_match('#value=""#', $req) && preg_match('#value=""#', $req)) {
	echo "\033[32m[OK]\033[0m\n";
} else {
	echo 'Ta reponse : '.$req."\n".'La reponse attendue: value="" pour le login et value="" pour le mot de passe'."\n";
	echo "\033[31m[FAUX]\033[0m\n";
}
echo "test 2 : ";
$get_inf = shell_exec("curl -v -b cook.txt 'localhost:8100/ex00/index.php?login=sb&passwd=beeone&submit=OK' 2>&1");
if (preg_match('#value="beeone"#', $get_inf) && preg_match('#value="sb"#', $get_inf)) {
	echo "\033[32m[OK]\033[0m\n";
} else {
	echo 'Ta reponse : '.$get_inf."\n".'La reponse attendue: value="sb" pour le login et value="beeone" pour le mot de passe'."\n";
	echo "\033[31m[FAUX]\033[0m\n";
}
echo "test 3 : ";
$get_inf = shell_exec("curl -v -b cook.txt 'localhost:8100/ex00/index.php' 2>&1");
if (preg_match('#value="beeone"#', $get_inf) && preg_match('#value="sb"#', $get_inf)) {
	echo "\033[32m[OK]\033[0m\n";
} else {
	echo 'Ta reponse : '.$get_inf."\n".'La reponse attendue: value="sb" pour le login et value="beeone" pour le mot de passe'."\n";
	echo "\033[31m[FAUX]\033[0m\n";
}
echo "test 4 : ";
$suppr_inf = shell_exec("curl -v 'localhost:8100/ex00/index.php' 2>&1");
if (preg_match('#value=""#', $suppr_inf) && preg_match('#value=""#', $suppr_inf)) {
	echo "\033[32m[OK]\033[0m\n";
} else {
	echo 'Ta reponse : '.$suppr_inf."\n".'La reponse attendue: value="" pour le login et value="" pour le mot de passe'."\n";
	echo "\033[31m[FAUX]\033[0m\n";
}
shell_exec("rm -rf cook.txt");
echo "\033[35m-------------------------------------------ex01------------------------------------\033[0m\n";
shell_exec('rm -rf private/passwd');
echo "test 1 : ";
$req = shell_exec("curl -d login=toto1 -d passwd=titi1 -d submit=OK 'localhost:8100/ex01/create.php' 2>&1");
if (preg_match("#OK\n#", $req)) {
	echo "\033[32m[OK]\033[0m\n";
} else {
	echo 'Ta reponse : '.$req."\n".'La reponse attendue: OK\n'."\n";
	echo "\033[31m[FAUX]\033[0m\n";
}

echo "test 2 : ";
$req = shell_exec("more ex01/private/passwd 2>&1");
if (preg_match("#titi1\n#", $req)) {
	echo 'le mdp doit etre "hashés" (algorithme de hashage)'."\n";
	echo "\033[31m[FAUX]\033[0m\n";
} else {
	echo "\033[32m[OK]\033[0m\n";
}

echo "test 3 : ";
$req = shell_exec("curl -d login=toto1 -d passwd=titi1 -d submit=OK 'localhost:8100/ex01/create.php' 2>&1");
if (preg_match("#ERROR\n#", $req)) {
	echo "\033[32m[OK]\033[0m\n";
} else {
	echo 'Ta reponse : '.$req."\n".'La reponse attendue: ERROR\n'."\n";
	echo "\033[31m[FAUX]\033[0m\n";
}

echo "test 4 : ";
$req = shell_exec("curl -d login=toto2 -d passwd= -d submit=OK 'localhost:8100/ex01/create.php' 2>&1");
if (preg_match("#ERROR\n#", $req)) {
	echo "\033[32m[OK]\033[0m\n";
} else {
	echo 'Ta reponse : '.$req."\n".'La reponse attendue: ERROR\n'."\n";
	echo "\033[31m[FAUX]\033[0m\n";
}

echo "\033[35m-------------------------------------------ex02------------------------------------\033[0m\n";

shell_exec('rm -rf private/passwd');
echo "test 1 : ";
$req = shell_exec("curl -d login=x -d passwd=21 -d submit=OK 'localhost:8100/ex01/create.php' 2>&1");
if (preg_match("#OK\n#", $req)) {
	echo "\033[32m[OK]\033[0m\n";
} else {
	echo 'Ta reponse : '.$req."\n".'La reponse attendue: OK\n'."\n";
	echo "\033[31m[FAUX]\033[0m\n";
}

echo "test 2 : ";
$req = shell_exec("curl -d login=x -d oldpw=21 -d newpw=42 -d submit=OK 'localhost:8100/ex02/modif.php' 2>&1");
$re = explode("\n", $req);
if (in_array("OK", $re)) {
	echo "\033[32m[OK]\033[0m\n";
} else {
	echo 'Ta reponse : '.$req."\n".'La reponse attendue: OK\n'."\n";
	echo "\033[31m[FAUX]\033[0m\n";
}

echo "test 3 : ";
$req = shell_exec("curl -d login=x -d oldpw=21  -d newpw=42 -d submit=OK  'localhost:8100/ex02/modif.php' 2>&1");
if (preg_match("#ERROR\n#", $req)) {
	echo "\033[32m[OK]\033[0m\n";
} else {
	echo 'Ta reponse : '.$req."\n".'La reponse attendue: ERROR\n'."\n";
	echo "\033[31m[FAUX]\033[0m\n";
}

echo "test 4 : ";
$req = shell_exec("curl -d login=x -d oldpw=42  -d newpw= -d submit=OK  'localhost:8100/ex02/modif.php' 2>&1");
if (preg_match("#ERROR\n#", $req)) {
	echo "\033[32m[OK]\033[0m\n";
} else {
	echo 'Ta reponse : '.$req."\n".'La reponse attendue: ERROR\n'."\n";
	echo "\033[31m[FAUX]\033[0m\n";
}

echo "\033[35m-------------------------------------------ex03------------------------------------\033[0m\n";

shell_exec('rm -rf private/passwd');

echo "test 1 : ";
$req = shell_exec("curl -d login=toto -d passwd=titi -d submit=OK 'localhost:8100/ex01/create.php' 2>&1");
if (preg_match("#OK\n#", $req)) {
	echo "\033[32m[OK]\033[0m\n";
} else {
	echo 'Ta reponse : '.$req."\n".'La reponse attendue: OK\n'."\n";
	echo "\033[31m[FAUX]\033[0m\n";
}

echo "test 2 : ";
$req = shell_exec("curl 'localhost:8100/ex03/login.php?login=toto&passwd=titi' 2>&1");
if (preg_match("#OK\n#", $req)) {
	echo "\033[32m[OK]\033[0m\n";
} else {
	echo 'Ta reponse : '.$req."\n".'La reponse attendue: OK\n'."\n";
	echo "\033[31m[FAUX]\033[0m\n";
}

shell_exec('rm -rf private/passwd');

echo "test 3 : ";
$req = shell_exec("curl -d login=toto -d passwd=titi -d submit=OK 'localhost:8100/ex01/create.php' 2>&1");
if (preg_match("#OK\n#", $req)) {
	echo "\033[32m[OK]\033[0m\n";
} else {
	echo 'Ta reponse : '.$req."\n".'La reponse attendue: OK\n'."\n";
	echo "\033[31m[FAUX]\033[0m\n";
}

echo "test 4 : ";
$req = shell_exec("curl -c cook.txt 'localhost:8100/ex03/login.php?login=toto&passwd=titi' 2>&1");
if (preg_match("#OK\n#", $req)) {
	echo "\033[32m[OK]\033[0m\n";
} else {
	echo 'Ta reponse : '.$req."\n".'La reponse attendue: OK\n'."\n";
	echo "\033[31m[FAUX]\033[0m\n";
}

echo "test 5 : ";
$req = shell_exec("curl -b cook.txt 'localhost:8100/ex03/whoami.php' 2>&1");
if (preg_match("#toto\n#", $req)) {
	echo "\033[32m[OK]\033[0m\n";
} else {
	echo 'Ta reponse : '.$req."\n".'La reponse attendue: toto\n'."\n";
	echo "\033[31m[FAUX]\033[0m\n";
}

echo "test 5 : ";
shell_exec("curl -b cook.txt 'localhost:8100/ex03/logout.php' 2>&1");
$req = shell_exec("curl -b cook.txt 'localhost:8100/ex03/whoami.php' 2>&1");
if (preg_match("#ERROR\n#", $req)) {
	echo "\033[32m[OK]\033[0m\n";
} else {
	echo 'Ta reponse : '.$req."\n".'La reponse attendue: ERROR\n'."\n";
	echo "\033[31m[FAUX]\033[0m\n";
}

shell_exec('rm -rf cook.txt');

echo "\033[35m-------------------------------------------ex04------------------------------------\033[0m\n";

shell_exec('rm -rf /ex04/private/chat');

echo "test 1 : ";
$req = shell_exec("curl -d login=user1 -d passwd=pass1 -d submit=OK 'localhost:8100/ex04/create.php' 2>&1");
if (preg_match("#OK\n#", $req)) {
	echo "\033[32m[OK]\033[0m\n";
} else {
	echo 'Ta reponse : '.$req."\n".'La reponse attendue: OK\n'."\n";
	echo "\033[31m[FAUX]\033[0m\n";
}

echo "test 2 : ";
$req = shell_exec("curl -d login=user2 -d passwd=pass2 -d submit=OK 'localhost:8100/ex04/create.php' 2>&1");
if (preg_match("#OK\n#", $req)) {
	echo "\033[32m[OK]\033[0m\n";
} else {
	echo 'Ta reponse : '.$req."\n".'La reponse attendue: OK\n'."\n";
	echo "\033[31m[FAUX]\033[0m\n";
}

echo "test 3 : ";
$req = shell_exec("curl -c user1.txt -d login=user1 -d passwd=pass1 'localhost:8100/ex04/login.php' 2>&1");
$a = '<iframe name="chat" src="chat.php" width="100%" height="550px"></iframe>';
$b = '<iframe name="speak" src="speak.php" width="100%" height="50px"></iframe>';
if (preg_match("#".$a."#", $req) && preg_match("#".$b."#", $req)) {
	echo "\033[32m[OK]\033[0m\n";
} else {
	echo 'Ta reponse : '.$req."\n".'La reponse attendue: '.$a."\n".$b."\n";
	echo "\033[31m[FAUX]\033[0m\n";
}


echo "test 4 : ";
shell_exec("curl -b user1.txt -d submit=OK -d msg=Bonjours 'localhost:8100/ex04/speak.php' 2>&1");
shell_exec("curl -b user1.txt -c user1.txt 'localhost:8100/ex04/logout.php' 2>&1");
$req = shell_exec("curl -b user1.txt -d submit=OK -d msg=Bonjours 'localhost:8100/ex04/speak.php' 2>&1");
if (preg_match("#ERROR\n#", $req)) {
	echo "\033[32m[OK]\033[0m\n";
} else {
	echo 'Ta reponse : '.$req."\n".'La reponse attendue: ERROR\n'."\n";
	echo "\033[31m[FAUX]\033[0m\n";
}

shell_exec("curl -c user2.txt -d login=user2 -d passwd=pass2 'localhost:8100/ex04/login.php' 2>&1");
shell_exec("curl -b user2.txt -d submit=OK -d msg=Hello 'localhost:8100/ex04/speak.php' 2>&1");

echo "test 5 : ";
$req = shell_exec("curl -b user2.txt 'localhost:8100/ex04/chat.php' 2>&1");
if (preg_match("#<b>user1</b>: Bonjours<br />#", $req) && preg_match("#<b>user2</b>: Hello<br />#", $req)) {
	echo "\033[32m[OK]\033[0m\n";
} else {
	echo 'Ta reponse : '.$req."\n".'La reponse attendue: <b>user1</b>: Bonjours<br />'."\n"."<b>user2</b>: Hello<br />\n";
	echo "\033[31m[FAUX]\033[0m\n";
}

shell_exec('rm -rf user1.txt');
shell_exec('rm -rf user2.txt');