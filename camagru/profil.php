<?php
	include ('conn.php');
	include "./header.php";
	
	if (isset($_SESSION['modif_compte']) AND !empty(['modif_compte']))
	{
		echo $_SESSION['modif_compte'];
		$_SESSION['modif_compte'] = "";
	}

	if (isset($_SESSION['id']) AND !empty($_SESSION['id']))
	{
		$bdd = sql_conn();	
		$checklogin = $bdd->prepare("SELECT * FROM membres WHERE id = ?");
		$checklogin->execute(array($_SESSION['id']));
		$userinfo = $checklogin->fetch();

		if (isset($_POST['suppr_img']) AND !empty($_POST['suppr_img']))
		{
			$supprimg = $bdd->prepare("DELETE FROM photos WHERE nom = ?");
			$supprimg->execute(array(htmlspecialchars($_POST['img'])));
		}

    	if (isset($_POST['submit']) AND !empty($_POST['submit']))
    	{
    	    if (isset($_POST['commentaire']) AND !empty($_POST['commentaire']))
    	    {
				$text = htmlspecialchars($_POST['commentaire']);
				$nom = htmlspecialchars($_POST['img']);
				$id = htmlspecialchars($_POST['id']);
    	    	    $reqsend = $bdd->prepare("INSERT INTO `commentaire`(`id_user`, `login`, `photo`, `commentaire`, `id_user_photo`) VALUES (?, ?, ?, ?, ?)");
				$reqsend->execute(array($_SESSION['id'], $_SESSION['login'], $nom, $text, $id));
    		}
		}
		
		if (isset($_POST['notif']) AND !empty($_POST['notif']))
		{
			$reqnotif = $bdd->prepare("SELECT * FROM membres WHERE id = ?");
			$reqnotif->execute(array($_SESSION['id']));
			$notif = $reqnotif->fetch();
			if ($notif['notif'] == 1)
			{
				$switch = $bdd->prepare("UPDATE membres SET notif = ? WHERE id = ?");
				$switch->execute(array("0", $_SESSION['id']));
				$userinfo['notif'] = 0;
			}
			else 
			{
				$switch = $bdd->prepare("UPDATE membres SET notif = ? WHERE id = ?");
				$switch->execute(array("1", $_SESSION['id']));
				$userinfo['notif'] = 1;
			}
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
    <div align="center">
		<br>
		<h2>profil de <?php echo $userinfo['login']?></h2>
		<br><br>
		<?php
			if (!empty($userinfo['avatar']))
			{
		?>
			<img src="membres/avatar/<?php echo $userinfo['avatar']?>" width="150"><br>
		<?php
			}
		?>
		Login : <?php echo $userinfo['login']?>
		<br>
		mail : <?php echo $userinfo['mail']?>
		<br><br>
		<a href="edit_profil.php">Editer mon profil</a>
		<br><br>
		<form method="post" action="">
			<input type="submit" name="notif" value="<?php if ($userinfo['notif'] == 1) { echo "Désactiver notification";} else { echo "Activer notification";}?>">
		</form>
	</div>
	<br>
	<div align="right">
		<a href="delete_compte.php">Supprimer mon compte !</a>
	</div>
	<div align="center">
		<table>
			<?php
				$reqimg = $bdd->prepare("SELECT * FROM photos WHERE id_user = ? ORDER BY id DESC");
				$reqimg->execute(array($_SESSION['id']));
				while ($img = $reqimg->fetch())
				{
					if (file_exists($img['path']))
					{
			?>
				<tr>
                	<td>
                	    <img src="<?php echo $img['path'];?>">
                	</td>
                	<td>
                	    Commentaire :<br>
                	    <?php
							$reqcomment = $bdd->prepare("SELECT * FROM commentaire WHERE photo = ?");
							$reqcomment->execute(array($img['nom']));
                	        while ($comment = $reqcomment->fetch())
                	        {
								echo $comment['login']." : ".$comment['commentaire']."<br>";
                	        }
                	    ?>
                	    <form method="post" action="">
						<input type="hidden" name="img" value="<?php echo $img['nom'];?>">
						<input type="hidden" name="id" value="<?php echo $img['id_user'];?>">
                	    <input type="text" name="commentaire" placeholder="Votre commentaire ...">
                	    <input type="submit" name="submit" value="Commenter !">
                	</td>
				</tr><br>
				<tr>
					<td>
						<input type="submit" name="suppr_img" value="supprimer la photo !">
					</td>
				</tr>
						</form>
				<tr>
					<td>
					</td>
				</tr>
			
			<?php
					}
				}
			?>
			<tr>
				
			</tr>
		</table>
		<footer>
			<p class="p-footer">CAMAGRU BY CEAUDOUY</p>
		</footer>
	</div>
</body>
</html>
<?php
	}
	else
		header('location: login.php');

?>