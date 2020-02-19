<?php
	include "./header.php";
	include ('conn.php');
	echo "<br><br><br><br><br>";
	if (isset($_GET['login'], $_GET['key']) AND !empty($_GET['login']) AND !empty(['key']))
	{

        $bdd = sql_conn();

		$login = htmlspecialchars(urldecode($_GET['login']));
		$key = htmlspecialchars($_GET['key']);

		$requser = $bdd->prepare("SELECT * FROM membres WHERE login = ? AND confirmkey = ?");
		$requser->execute(array($login, $key));
		$userexist = $requser->rowcount();
		if ($userexist == 1)
		{
			$user = $requser->fetch();
			if ($user['confirme'] == 0)
			{
				$updateuser = $bdd->prepare("UPDATE membres SET confirme = 1 WHERE login = ? AND confirmkey = ?");
				$updateuser->execute(array($login, $key));
				echo "votre compte a bien été confirmé ... <a href="."'index.php'".">retour a la page d'accueil</a>";
			}
			else
				echo "Email déjà confirmé ... <a href="."'index.php'".">retour a la page d'accueil</a>";

		}
		else
			echo "L'utilisateur n'existe pas !";
	}
	else
		echo "Erreur confirmation ... <a href="."'index.php'".">retour a la page d'accueil</a>";
?>
<html>
	<body>
<footer class="foot">
		<p class="p-footer">CAMAGRU BY CEAUDOUY</p>
</footer>
</body>
</html>