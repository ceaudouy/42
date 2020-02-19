<?php
	
	if (isset($_POST['email']) AND !empty($_POST['email']))
	{
		$email = htmlspecialchars($_POST['email']);
		$header="MIME-Version: 1.0\r\n";
		$header.='From:"Camagru.com"<noreply@camagru.com>'."\n";
		$header.='Conten-Type:text/html; charset="utf-8"'."\n";
		$header.='Content-Transfert-Encoding: 8bit';
		$message = "Réinitialisez votre mot de passe : "."http://localhost:8888/camagru/reinitialisation.php?login=".urlencode($_POST['email']);
		mail($email, "REINITIALISATION MOT DE PASSE", $message, $header);
		header('Location: login.php');
	}
	else
		header ('Location: index.php');
?>