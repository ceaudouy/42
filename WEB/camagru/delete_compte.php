<?php
	include ('conn.php');
	include "./header.php";

	if (isset($_POST['non']) AND !empty($_POST['non']))
		header ('Location: profil.php');
	if (isset($_POST['oui']) AND !empty($_POST['oui']))
	{
		$bdd = sql_conn();

		if (isset($_POST['passwd']) AND !empty($_POST['passwd']))
		{
			$passwd = md5(htmlspecialchars($_POST['passwd']));
			$checklogin = $bdd->prepare("SELECT * FROM membres WHERE login = ? AND passwd = ?");
			$checklogin->execute(array($_SESSION['login'], $passwd));
			$loginexist = $checklogin->rowcount();
			if ($loginexist == 1)
			{
				$reqlogin = $bdd->prepare("DELETE FROM membres WHERE id = ?");
				$reqlogin->execute(array($_SESSION['id']));
				$reqphoto = $bdd->prepare("DELETE FROM photos WHERE id_user = ?");
				$reqphoto->execute(array($_SESSION['id']));
				$_SESSION = array();
				session_destroy();
				header('Location: index.php');
			}
			else
				$error = "Mauvais mot de passe !";
		}
		else
			$error = "Vous devez rentrer votre mot de passe !";
	}
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Camagru</title>
	<link rel="stylesheet" type="text/css" media="screen" href="css/style.css">
</head>
<br><br><br>
<div align="center">
		<br>
		Voulez vous vraiment supprimer votre compte ?
		<br><br>
		<form method="post" action="">
			<table>
    	            <tr>
    	                <td align="right">
    	                     <label for="passwd">mot de passe :</label>
    	                </td>
    	                <td align="right">
    	                     <input type="password" placeholder="mot de passe" id="passwd" name="passwd"><br>
						</td>
    	            </tr>
					<tr>
						<td align="center">
							<input type="submit" name="oui" value="oui">
						</td>
						<td align="center">
							<input type="submit" name="non" value="non">
						</td>
					</tr>
			</table>
		</form><br>
	<?php
		if (isset($error))
		{
			echo $error;
		}
	?>
	</div>
	<footer class="foot_login">
		<p class="p-footer_login">CAMAGRU BY CEAUDOUY</p>
	</footer>
</body>
</html>