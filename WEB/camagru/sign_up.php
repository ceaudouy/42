<?php
	include ('conn.php');
	include "./header.php";
	
	if(isset($_SESSION['id']) AND !empty($_SESSION['id']))
		header ('Location: index.php');
	if (isset($_POST['submit']) AND !empty($_POST['submit']))
    {
        $bdd = sql_conn();
        $login = htmlspecialchars($_POST['login']);
        $email = htmlspecialchars($_POST['email']);
        

        if (isset($_POST['login']) AND !empty($_POST['login']) AND isset($_POST['passwd']) AND !empty($_POST['passwd']) AND isset($_POST['passwd2']) AND !empty($_POST['passwd2']))
        {
			if (preg_match("~[a-z]~", htmlspecialchars($_POST['passwd'])) AND preg_match("~[A-Z]~", htmlspecialchars($_POST['passwd'])) AND preg_match("~[0-9]~", htmlspecialchars($_POST['passwd'])) AND strlen(htmlspecialchars($_POST['passwd'])))
			{
            	$passwd = md5(htmlspecialchars($_POST['passwd']));
            	$passwd2 = md5(htmlspecialchars($_POST['passwd2']));
            	$loginlength = strlen($login);
           		 if (filter_var($email, FILTER_VALIDATE_EMAIL))
           		 {
           		     if ($loginlength < 255)
           		     {
           		         $reqmail = $bdd->prepare("SELECT * FROM membres WHERE mail = ?");
           		         $reqmail->execute(array($email));
           		         $mailexist = $reqmail->rowcount();
           		         if ($mailexist == 0)
           		         {
           		         	$reqlogin = $bdd->prepare("SELECT * FROM membres WHERE login = ?");
           		             $reqlogin->execute(array($login));
           		             $loginexist = $reqlogin->rowcount();
           		             if ($loginexist == 0)
           		             {
           		                 if ($passwd == $passwd2)
           		                 {
												$keylenght = 12;
												$key = "";
												for ($i = 1; $i < $keylenght; $i++)
												{
													$key .= mt_rand(0,9);
												}
												$insertmbr = $bdd->prepare("INSERT INTO `membres`(`login`, `mail`, `passwd`, `avatar`, `notif`, `confirmkey`, `confirme`) VALUES(?, ?, ?, ?, ?, ?, ?)");
	       		                         	$insertmbr->execute(array($login, $email, $passwd, "default.jpeg", '1', $key, '0'));
	       		                         	$_SESSION['comptecree'] = "compte créé !";
	       		                         	$_SESSION['login'] = $login;
												$_SESSION['mail'] = $email;
	       		                         	//send mail
	       		                     		$header="MIME-Version: 1.0\r\n";
	       		                     		$header.='From:"Camagru.com"<noreply@camagru.com>'."\n";
	       		                     		$header.='Conten-Type:text/html; charset="utf-8"'."\n";
	       		                     		$header.='Content-Transfert-Encoding: 8bit';
	       		                         	$message = "confirmer votre mail : "."http://localhost:8888/camagru/confirmation.php?login=".urlencode($login)."&key=".$key;
	       		                         	mail($email, "CONFIMATION DE COMPTE", $message, $header);
												header('location: login.php');
           		                 }
           		                 else
           		                     $error = "Password non identique !";
           		             }
           		             else
           		                 $error = "Login déjà utilisé !";
           		         }
           		         else
           		             $error = "adresse mail déjà utilisé !";
           		     }
           		     else
           		         $error = "Login trop long !";
           		 }
           		 else
						$error = "Email non valide !";
			}
			else
				$error = "Votre mot de passe doit avoir 8 carateres une majuscule, une minuscule et un chiffre";
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
    <div align="center">
        <br>
        sign up !
        <br>
        <form method="post" action="">
            <table>
                <tr>
                    <td align="right">
                         <label for="login">Login :</label>
                    </td>
                    <td align="right">
                         <input type="text" placeholder="Login" id="login" name="login" value="<?php if(isset($login)) {echo $login;} ?>"><br>
                    </td>
                </tr>
                <tr>
                    <td align="right">
                        <label for="email">Email :</label>
                    </td>
                    <td align="right">
                        <input type="email" placeholder="email" id="email" name="email" value="<?php if(isset($email)) {echo $email;}?>"><br>
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
                <tr>
                    <td align="right">
                        <label for="passwd2">Confirm password :</label>
                    </td>
                    <td align="right">
                        <input type="password" id="passwd2" placeholder="confirm password"  name="passwd2"><br>
                    </td>
                </tr>
                <tr>
                </tr>
            </table><br>
            <input type="submit" name="submit" value="sign up">
        </form>
        <br>
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
<?php

?>
