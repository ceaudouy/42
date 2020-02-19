<html>
<head>
	<meta charset="utf-8">
	<title>ERROR :(</title>
</head>

<style>
html {
	font-family: Montserrat, "Helvetica Neue", "Lucida Grande", Arial, Verdana, sans-serif;
	width: 100%;
	height: 100%;
	margin: 0;
	background-color: #FF1D4D;
	overflow: hidden;
}
#container {
	background-color: #20232d;
	position: absolute;
	left: 30px;
	top: 30px;
	bottom: 30px;
	right: 30px;
	text-align: center;
}
#oh_no {
	position: relative;
	height: 50vmin;
	width: auto;
	margin-top: 3vh;
}
#err_msg {
	color: white;
	font-size: 5.5vmin;
	font-weight: bold;
}
#err_msg>#msg {
	color: white;
	font-size: 2vmin;
	font-weight: bold;
}
#link {
	transition: all 0.2s;
	color: rgba(255, 30, 80, 0.6);
	font-size: 3vmin;
	text-decoration: none !important;
}
	#link:hover {
		color: rgb(255, 30, 80);
		outline: none;
	}
	#link:active, #link:focus {
		outline: none;
		text-decoration: none;
		color: rgba(255, 29, 77, 0.6);
	}
</style>

<body>

	<div id="container">
		<img id="oh_no" src="./imgs/oh_no.png" />

		<?php
			if ($_GET['err'])
				echo "<h1 id='err_msg'>An error occurred:<p id='msg'>{$_GET['err']}</p></h1>";
			else
				echo "<h1 id='err_msg'>An unknown error occured</h1>";
		?>
		<a id="link" href="./index.php"><h2>GO BACK TO SAFETY</h2></a>
	</div>
</body>
</html>