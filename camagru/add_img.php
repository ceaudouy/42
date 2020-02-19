<?php
    include ('header.php');
    include ('conn.php');
	$bdd = sql_conn();
	
	if (isset($_POST['base64']) AND $_POST['base64'])
		{
			$img = htmlspecialchars($_POST['base64']);
			$img = str_replace('data:image/png;base64,', '', $img);
         	$img = str_replace(' ', '+', $img);
			$data = base64_decode($img);
			$name = $_SESSION['id']."_";
            for ($i = 0; $i < 12; $i++)
            {
                $name.= mt_rand(0, 9);
            }
			$name.= ".png";
			$base = htmlspecialchars($_POST['base64']);
          	$base_to_php = explode(',', $base);
			$data = base64_decode($base_to_php[1]);
			$chemin = "membres/photo/".$name;
          	file_put_contents($chemin,$data);
			$date = date('dmYHis');
			$id = $_SESSION['id'];
			$insertphotos = $bdd->prepare("INSERT INTO `photos`(`nom`, `path`, `id_user`, `date`) VALUES(?, ?, ?, ?)");
			$insertphotos->execute(array($name, $chemin, $id, $date));
			$file = "";
          	$data = "";
          	$img = "";
          	$_POST['base64'] = "";
		}

    if (isset($_SESSION['id']) AND !empty($_SESSION['id']))
    {
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
	<link rel="stylesheet" type="text/css" media="screen" href="css/style.css">
    <title>Camagru</title>
</head>
<body>
	<div>
	<div class="cam">
		<video autoplay="true" id="video" width="400" height="300"></video>
		<input type="file" id="image" name="image"/>
		<a href="#" id="capture" class="capture-button">Prendre la photo</a>
		<canvas id="canvas" width="400" height="300"></canvas>
		<form method="POST" name="form" id="form">
            <textarea class="hid" name="base64" id="base64"></textarea>
			<button type="submit" id="submit" class="capture-button">Publier la photo !</button>
		</form>
	</div>
	<div class="superpos">
		<img class="cadre" onClick="reply_click(this.id)" id="cadre" src="membres/cadres/cadre.png">
		<img class="cadre" onClick="reply_click(this.id)" id="feu" src="membres/cadres/feu.png">
		<img class="cadre" onClick="reply_click(this.id)" id="ascii" src="membres/cadres/ascii.png">
	</div>
	<canvas hidden="hidden" id="filtre" widht="400" height="300"></canvas>
	<script src="cam.js"></script>
	<div align="right">
		<table style="position: absolute; left: 75%; top: 15%;">
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
                	    <img style="width: 100px; height: 100px;" src="<?php echo $img['path'];?>">
                	</td>
				</tr>
			<?php
					}
				}
			?>
		</table>
	</div>
	</div>
	<br><br><br>
		<footer>
			<p class="p-footer">CAMAGRU BY CEAUDOUY</p>
		</footer>
</body>
</html>
<?php
    }
    else
        header('Location: index.php')
?>