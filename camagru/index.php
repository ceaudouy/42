<?php
	include "./header.php";
    include ('conn.php');
	$bdd = sql_conn();
	$i = 0;
	if (!isset($load) AND empty($load))
	{
		$load = 5;
	}
	
	if (isset($_POST['submit']) AND !empty($_POST['submit']) AND $_POST['submit']!== 'null')
    {
		if (isset($_SESSION['id']) AND !empty($_SESSION['id']))
		{
            if (isset($_POST['commentaire']) AND !empty($_POST['commentaire']))
            {
				$text = htmlspecialchars($_POST['commentaire']);
				$nom = htmlspecialchars($_POST['img']);
				$id = htmlspecialchars($_POST['id']);
                $reqsend = $bdd->prepare("INSERT INTO `commentaire`(`id_user`, `login`, `photo`, `commentaire`, `id_user_photo`) VALUES (?, ?, ?, ?, ?)");
				$reqsend->execute(array($_SESSION['id'], $_SESSION['login'], $nom, $text, $id));
				$reqemail = $bdd->prepare("SELECT * FROM membres WHERE id = ?");
				$reqemail->execute(array($id));
				
				$mail = $reqemail->fetch();
				if ($mail['notif'] == 1)
				{
					$header="MIME-Version: 1.0\r\n";
                    $header.='From:"Camagru.com"<noreply@camagru.com>'."\n";
                    $header.='Conten-Type:text/html; charset="utf-8"'."\n";
                    $header.='Content-Transfert-Encoding: 8bit';
                    $message = "Vous avez un nouveau commentaire";
                    mail($mail['mail'], "Nouveau commentaire", $message, $header);
				}
				header ('Location: index.php');
			}
		}
		else
		{
			$_SESSION['nolog'] = "Vous devez vous connecter pour commenter !";
			header ('Location: login.php');
		}
	}
	if (isset($_POST['like']) AND !empty ($_POST['like']))
	{
		if (isset($_SESSION['id']) AND !empty($_SESSION['id']))
		{
			$nom = htmlspecialchars($_POST['img']);
			$reqlike = $bdd->prepare("SELECT * FROM likes WHERE photo = ? AND id_user = ?");
			$reqlike->execute(array($nom, $_SESSION['id']));
			$alr_like = $reqlike->rowcount();
			if ($alr_like == 0)
			{
				$insertlike = $bdd->prepare("INSERT INTO `likes`(`photo`, `id_user`) VALUES (?, ?)");
				$insertlike->execute(array($nom, $_SESSION['id']));
			}
			else
			{
				$insertlike = $bdd->prepare("DELETE FROM likes WHERE photo = ? AND id_user = ?");
				$insertlike->execute(array($nom, $_SESSION['id']));
			}
		}
		else
		{
			$_SESSION['nolog'] = "Vous devez vous connecter pour liker !";
			header ('Location: login.php');
		}
	}
	if (isset($_POST['load']) AND !empty($_POST['load']))
	{
		$load = htmlspecialchars($_POST['value_load']) + 5;
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
<br><br>
    <div align="center">
        <table>
            <?php
				$reqphoto = $bdd->prepare("SELECT * FROM photos ORDER BY id DESC LIMIT $load");
				$reqphoto->execute();
                while ($photo = $reqphoto->fetch())
                {
					if (file_exists($photo['path']))
					{
            ?>
                <tr>
					<td>
						<img src="<?php
						$reqavatar = $bdd->prepare("SELECT * FROM membres WHERE id = ?");
						$reqavatar->execute(array($photo['id_user']));
						$avatar = $reqavatar->fetch();
						echo "membres/avatar/".$avatar['avatar'];
						?>" width="50px" height="50px">
						<?php echo $avatar['login'];?>
					</td>
				</tr>
					<tr>
                    	<td>
                    	    <img src="<?php echo $photo['path'];?>">
                    	</td>
                    	<td>
                    	    Commentaire :<br>
                    	    <?php
								$reqcomment = $bdd->prepare("SELECT * FROM commentaire WHERE photo = ?");
								$reqcomment->execute(array($photo['nom']));
                    	        while ($comment = $reqcomment->fetch())
                    	        {
                    	            echo $comment['login']." : ".$comment['commentaire']."<br>";
                    	        }
                    	    ?>
                    	    <form method="post" action="">
								<input type="hidden" name="img" value="<?php echo $photo['nom'];?>">
								<input type="hidden" name="id" value="<?php echo $photo['id_user'];?>">
                    	        <input type="text" name="commentaire" placeholder="Votre commentaire ...">
                    	        <input type="submit" name="submit" value="Commenter !">
							</form>
                    	</td>
                	</tr>
					<tr>
						<td>
						</td>
						<td>
							<form method="post" action="">
								<input type="hidden" name="img" value="<?php echo $photo['nom'];?>">
								<input type="submit" name="like" value="<?php
								if (isset($_SESSION['id']) AND !empty($_SESSION['id']))
								{
									$checklike = $bdd->prepare("SELECT * FROM likes WHERE photo = ? AND id_user = ?");
									$checklike->execute(array($photo['nom'], $_SESSION['id']));
									$like = $checklike->rowcount();
									if ($like == 0)
									{
										echo "like";
									}
									else
									{
										echo "Dislike";
									}
								}
								else
									echo "Like";
							 ?>">
								<?php
									$findlike = $bdd->prepare("SELECT * FROM likes WHERE photo = ?");
									$findlike->execute(array($photo['nom']));
									$nbr_like = $findlike->rowcount();
									if ($nbr_like > 1)
										echo $nbr_like." likes";
									else
										echo $nbr_like." like";
								?>
						</td>
					</tr>
					</form>                            
				<?php
					}
                }
            	?>
		  </table>
		  <form method="post" action="">
		 		<input type="hidden" name="value_load" value="<?php echo $load;?>">
				<input type="submit" name="load" value="Plus d'image">
			</form>
		</div>
<br><br><br>
		<footer>
			<p class="p-footer">CAMAGRU BY CEAUDOUY</p>
		</footer>
</body>
</html>