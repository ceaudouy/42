<?php
	include ('conn.php');
	include "./header.php";

	if (isset($_SESSION['nolog']) AND !empty($_SESSION['nolog']))
	{
		echo $_SESSION['nolog'];
		$_SESSION['nolog'] = "";
	}

	if (isset($_SESSION['comptecree']) AND !empty($_SESSION['comptecree']))
	{
		echo $_SESSION['comptecree'];
		$_SESSION['comptecree'] = "";
		$login = $_SESSION['login'];
	}
	if (isset($_SESSION['reinitialisation']) AND !empty($_SESSION['reinitialisation']))
	{
		echo $_SESSION['reinitialisation'];
		$_SESSION['reinitialisation'] = "";
	}
    if (isset($_POST['submit']) AND !empty($_POST['submit']))
    {
		if (isset($_POST['login']) AND !empty($_POST['login']) AND isset($_POST['passwd']) AND !empty($_POST['passwd']))
        {
			$bdd = sql_conn();
			$login = htmlspecialchars($_POST['login']);
            $passwd = md5(htmlspecialchars($_POST['passwd']));
			
			$checklogin = $bdd->prepare("SELECT * FROM membres WHERE login = ? AND passwd = ?");
			$checklogin->execute(array($login, $passwd));
			$loginexist = $checklogin->rowcount();
			$checkmail = $bdd->prepare("SELECT * FROM membres WHERE mail = ? AND passwd = ?");
			$checkmail->execute(array($login, $passwd));
			$mailexist = $checkmail->rowcount();
			if ($loginexist == 1 || $mailexist == 1)
			{
				if ($mailexist == 1)
					$checklogin = $checkmail;
				$userinfo = $checklogin->fetch();
				if ($userinfo['confirme'] == 1)
				{
                	$_SESSION['id'] = $userinfo['id'];
					$_SESSION['login'] = $userinfo['login'];
					$_SESSION['mail'] = $userinfo['mail'];
					header('location: index.php');
				}
				else
					$error = "mail non confirmé !";
			}
			else
				$error_connection = "mauvais login ou mot de passe !";
        }
        else
			$error = "Tous les champs doivent être remplis";
    }
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
<div align="center" style="height: 80%">
		<br>
		Login !
		<br>
		<br>
        <form method="post" action="">
            <table>
                <tr>
                    <td align="right">
                        <label for="login">Login :</label>
                    </td>
                    <td align="right">
                        <input type="text" placeholder="Login ou email" id="login" name="login" value="<?php if(isset($login) AND !empty($login)) {echo $login;} ?>"><br>
                    </td>
                </tr>
                <tr>
                    <td align="right">
                        <label for="passwd">Password :</label>
                    </td>
                    <td align="right">
                        <input type="password" id="passwd" placeholder="password" name="passwd"><br>
                    </td>
                </tr>
            </table><br>
        <input type="submit" name="submit" value="Login !">
    </form><br>
    <?php
		if (isset ($error_connection))
		{
			echo $error_connection."<br>";
	?>
		<form method="post" action="send_newmdp.php">
			<table>
				<tr>
					<td align="right">
						<label for="email">Entrez votre email :</label>
					<td>
					<td>
						<input type="email" placeholder="Email"  name="email" id="email">
					</td>
					<td>
						<input type="submit" value="Réinitialiser mot de passe" name="submit">
					</td>
				</tr>
			</table>
		</form>
	<?php
		}
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