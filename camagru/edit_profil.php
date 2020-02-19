<?php
	include ('conn.php');
	include "./header.php";
	$bdd = sql_conn();

    if (isset($_POST['submit']) AND !empty($_POST['submit']))
    {
		if (isset($_POST['oldpasswd']) AND !empty($_POST['oldpasswd']))
        {
			$modif = 0;
			if (isset($_POST['newlogin']) AND !empty($_POST['newlogin']))
				$newlogin = htmlspecialchars($_POST['newlogin']);
			if (isset($_POST['newemail']) AND !empty($_POST['newemail']))
	        	$newemail = htmlspecialchars($_POST['newemail']);
			if (isset($_POST['newpasswd']) AND !empty($_POST['newpasswd']))
				$newpasswd = md5(htmlspecialchars($_POST['newpasswd']));
			if (isset($_POST['newpasswd2']) AND !empty($_POST['newpasswd2']))
           		$newpasswd2 = md5(htmlspecialchars($_POST['newpasswd2']));
            $oldpasswd = md5(htmlspecialchars($_POST['oldpasswd']));
			
			$checklogin = $bdd->prepare("SELECT * FROM membres WHERE login = ? AND passwd = ?");
			$checklogin->execute(array($_SESSION['login'], $oldpasswd));
            $loginexist = $checklogin->rowcount();
            if ($loginexist == 1)
            {
                if (isset($newlogin) AND !empty($newlogin) AND $newlogin != $_SESSION['login'])
                {
                    $reqlogin = $bdd->prepare("SELECT * FROM membres WHERE login = ?");
                    $reqlogin->execute(array($newlogin));
                    $loginexist = $reqlogin->rowcount();
                    if ($loginexist == 0)
                    {
						$insertlogin = $bdd->prepare("UPDATE membres SET login = ? WHERE id = ?");
						$insertlogin->execute(array($newlogin, $_SESSION['id']));
						$_SESSION['login'] = $newlogin;
						$_SESSION['modif_compte'] = "Votre compte à bien été modifié !";
						$modif = 1;
					}
					else
						$error_login = "Login déjà utilisé !";
				}
				if (isset($newemail) AND !empty($newemail) AND filter_var($newemail, FILTER_VALIDATE_EMAIL))
				{
					$reqmail = $bdd->prepare("SELECT * FROM membres WHERE mail = ?");
                	$reqmail->execute(array($newemail));
					$mailexist = $reqmail->rowcount();
					if ($mailexist == 0 AND $newemail != $_SESSION['mail'])
					{
						$insertmail = $bdd->prepare("UPDATE membres SET mail = ? WHERE id = ?");
						$insertmail->execute(array($newemail, $_SESSION['id']));
						$_SESSION['mail'] = $newmail;
						$_SESSION['modif_compte'] = "Votre compte à bien été modifié !";
						$modif = 1;
					}
					else
						$error_mail = "Email déjà utilisé !";
				}
				if (isset($newpasswd) AND !empty($newpasswd) AND isset($newpasswd2) AND !empty($newpasswd2))
				{
					
					if (preg_match("~[a-z]~", htmlspecialchars($_POST['newpasswd'])) AND preg_match("~[A-Z]~", htmlspecialchars($_POST['newpasswd'])) AND preg_match("~[0-9]~", htmlspecialchars($_POST['newpasswd'])) AND strlen(htmlspecialchars($_POST['newpasswd'])))
					{
						if ($newpasswd == $newpasswd2)
						{
							$insertpasswd = $bdd->prepare("UPDATE membres SET passwd = ? WHERE id = ?");
							$insertpasswd->execute(array($newpasswd, $_SESSION['id']));
							$_SESSION['modif_compte'] = "Votre compte à bien été modifié !";
							$modif = 1;
						}
						else
							$error_passwd = "Les mots de passes ne sont pas identique !";
					}
					else
						$error_passwd = "Votre mot de passe doit avoir 8 carateres une majuscule, une minuscule et un chiffre";
				}
				if ($modif == 1)
					header('Location: profil.php');
			}
            else
                $error = "Mauvais mot de passe !";
        }
        else
            $error = "Vous devez entrer votre mot de passe !";
	}
	if (isset($_POST['submit_file']) AND !empty($_POST['submit_file']))
	{
		if (isset($_FILES['avatar']) AND !empty($_FILES['avatar']['name']))
		{
			$taillemax = 2097153;
			$extensionsValides = array('jpg', 'jpeg', 'gif', 'png');
			if ($_FILES['avatar']['size'] <= $taillemax)
			{
				$extansionUpload = strtolower(substr(strrchr($_FILES['avatar']['name'], '.'), 1));
				if (in_array($extansionUpload, $extensionsValides))
				{
					$chemin = "membres/avatar/".$_SESSION['id'].".".$extansionUpload;
					$resltat = move_uploaded_file($_FILES['avatar']['tmp_name'], $chemin);
					if ($resltat)
					{
						$updateAvatar = $bdd->prepare('UPDATE membres SET avatar = :avatar WHERE id = :id');
						$updateAvatar->execute(array(
							'avatar' => $_SESSION['id'].".".$extansionUpload,
							'id' => $_SESSION['id']
						));
						$error = "votre avatar à bien été changé !";
					}
					else
						$error = "Erreur durant l'importation de votre photo !";

				}
				else
					$error = "Le format de votre photo doit etre en format jpg, jpeg, gif ou png";

			} 
			else
				$error = "Votre image ne doit pas dépasser 2Mo !";
		}
		else
			$error = "Selectionnez un fichier !";
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
<div align="center">
		<h2>Editer mon profil</h2>
		<form method="post" enctype="multipart/form-data" action="">
		<table>
                <tr>
                    <td align="right">
                         <label for="login">Nouveau login :</label>
                    </td>
                    <td align="right">
                         <input type="text" placeholder="Nouveau login" id="login" name="newlogin" value="<?php if(isset($newlogin) AND !empty($newlogin)) {echo $newlogin;}?>"><br>
                    </td>
                </tr>
                <tr>
                    <td align="right">
                        <label for="email">Nouveau mail :</label>
                    </td>
                    <td align="right">
                        <input type="email" placeholder="Nouveau email" id="email" name="newemail" value="<?php if(isset($newemail) AND !empty($newemail)) {echo $newemail;}?>"><br>
                    </td>
                </tr>
                <tr>
                    <td align="right">
                        <label for="passwd">Nouveau mot de passe :</label>
                    </td>
                    <td align="right">
                        <input type="password" id="passwd" placeholder="Nouveau mot de passe" name="newpasswd"><br>
                    </td>
                </tr>
                <tr>
                    <td align="right">
                        <label for="passwd2">Confirmer nouveau mot de passe :</label>
                    </td>
                    <td align="right">
                        <input type="password" id="passwd2" placeholder="confirmer nouveau mot de passe"  name="newpasswd2"><br>
                    </td>
                </tr>
                <tr>
                    <td align="right">
                        <label for="oldpasswd">Entrer votre mot de passe :</label>
                    </td>
                    <td align="right">
                        <input type="password" id="oldpasswd" placeholder="Entrer votre mot de passe"  name="oldpasswd"><br>
                    </td>
				</tr>
            </table><br>
			<input type="submit" name="submit" value="Modifer mon profil !">
		<br><br>
			<div align="center">
				<label for="avatar">Avatar :</label>
				<input type="file" name="avatar" id="avatar">
			<div>
			<br>
			<input type="submit" name="submit_file" value="ajouter avatar">
		</form>
		<br><br>
		<a href="profil.php">Retourner à mon profil</a>
    	<br><br>
    	<?php
			if (isset($error))
			{
    	        echo $error."<br>";
			}
    	    if (isset($error_login))
    	    {
    	        echo $error_login."<br>";
			}
			if (isset($error_mail))
    	    {
    	        echo $error_mail."<br>";
			}
			if (isset($error_passwd))
    	    {
    	        echo $error_passwd."<br>";
    	    }
    	?>
	</div>
	<footer class="foot_login">
		<p class="p-footer_login">CAMAGRU BY CEAUDOUY</p>
	</footer>
    </body>
</html>