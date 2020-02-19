<!DOCTYPE html>
<?php
	session_start();
?>
<html>
<head>
	<meta charset="utf-8">
	<title>Camagru</title>
	<link rel="stylesheet" type="text/css" media="screen" href="css/style.css">
	<link rel="stylesheet" type="text/css" media="screen" href="css/header.css">
</head>
<body>
	<header role="header">
		<nav class="menu" role="navigation">
			<div class="inner">
				<div class="m-left">
					<a href="index.php" class="logo">CAMAGRU</h1>
				</div>
				<div class="m-right">
	<?php
		if (isset($_SESSION['id']) AND !empty($_SESSION['id']))
		{
	?>
					<a href="add_img.php" class="m-link">Ajouter une photo</a>	
					<a href="profil.php" class="m-link">profil</a>	
					<a href="log_out.php" class="m-link">log out</a>	

	<?php
		}
			else
			{
	?>
					<a href="login.php" class="m-link">login</a>	
					<a href="sign_up.php" class="m-link">sign up</a>	
	<?php
			}
	?>
				</div>
			</div>
		</nav>
	</header>
</body>
</html>