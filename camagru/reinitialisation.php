<?php
	include ('conn.php');
	include "./header.php";
	
	if (isset($_GET['login']) AND !empty($_GET['login']))
	{
		$bdd = sql_conn();

		$mail = htmlspecialchars($_GET['login']);
		$requser = $bdd->prepare("SELECT * FROM membres WHERE mail = ?");
		$requser->execute(array($mail));
		$userexist = $requser->rowcount();
		if ($userexist == 1)
		{
			if (isset($_POST['submit']) AND !empty($_POST['submit']))
			{
				if (isset($_POST['passwd'], $_POST['passwd2']) AND !empty($_POST['submit']) AND !empty($_POST['passwd']) AND !empty(['passwd2']))
				{
					$passwd = md5(htmlspecialchars($_POST['passwd']));
					$passwd2 = md5(htmlspecialchars($_POST['passwd2']));
					if ($passwd == $passwd2)
					{
						$insertpasswd = $bdd->prepare("UPDATE membres SET passwd = ? WHERE mail = ?");
						$insertpasswd->execute(array($passwd, $mail));
						$_SESSION['reinitialisation'] = "votre mot de passe a bien été réinitialisé !<br>";
						header ('Location: login.php');
					}
					else
						$error = "Les mots de passe ne sont pas identiques !";
				}
				else
					$error = "tous les champs doivent etre rempli !";
			}
		}
		else
			header ('Location: index.php');
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Camagru</title>
	<link rel="stylesheet" type="text/css" media="screen" href="css/style.css">
</head>
<body>
	<br><br><br>
	<br><br><br>
		<div align="center">
			<form method="post" action="">
				<table>
				<tr>
                    <td align="right">
                        <label for="passwd">nouveau mot de passe :</label>
                    </td>
                    <td align="right">
                        <input type="password" id="passwd" placeholder="password" name="passwd"><br>
                    </td>
                </tr>
                <tr>
                    <td align="right">
                        <label for="passwd2">Confirme nouveau mot de passe :</label>
                    </td>
                    <td align="right">
                        <input type="password" id="passwd2" placeholder="confirm password"  name="passwd2"><br>
                    </td>
                </tr>
				</table>
					<input type="submit" name="submit" value="Changer de mot de passe">
			</form><br>
			<?php
				if (isset($error))
				{
					echo $error;
				}
			?>
		</div>
	<footer class="foot">
		<p class="p-footer">CAMAGRU BY CEAUDOUY</p>
	</footer>
</body>
</html>
<?php
	}
	else
		header ('location: index.php');
?>
