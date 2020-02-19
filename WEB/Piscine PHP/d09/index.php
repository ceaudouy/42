<html>
<head>
	<title>Fichier de corection</title>
	<meta charset="utf-8">
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
</head>
<body>
<h1>Exercice 00</h1>
<div id="ex00">
	<?php include('ex00/balloon.html'); ?>
	<font id="Err" color="red"></font>
	<font id="suc" color="green"></font>
</div>
<h1>Exercice 01</h1>
<div id="ex01">
	<?php //include('ex01/calc.html'); ?>
	<font id="Err1" color="red"></font>
	<font id="suc1" color="green"></font>
</div>
</body>
<script type="text/javascript">
window.onload = function() {

	//********************************************************ex00******************************************************\\

	let ex00 = document.getElementById('ex00');
	let ball = ex00.querySelector('div');
	let suc = ex00.querySelector('#suc');
	let err = ex00.querySelector('#Err');
	ball.style.display = "none";
	let width_base = 200;
	let height_base = 200;
	let color_base = new Array();
	color_base[0] = "red";
	color_base[1] = "green";
	color_base[2] = "blue";

	if (width_base+"px" != ball.style.width || height_base+"px" != ball.style.height || color_base[0] != ball.style.backgroundColor) {
		err.innerHTML = "Tests de base : [Faux]<br>";
	} else {
		suc.innerHTML = "Tests de base : [OK]<br>";
	}

	var i = 0;
	var s = 0;
	var e = 0;
	while (ball.style.width < 420+"px") {
		ball.click();
		height_base = height_base + 10;
		width_base = height_base;
		if (i == 0 || i == 1)
			i++;
		else if (i == 2)
			i = 0;
		if (color_base[i] != ball.style.backgroundColor) {
			e++;
		} else {
			s++;
		}
		if (width_base+"px" != ball.style.width || height_base+"px" != ball.style.height) {
			e++;
		} else {
			s++;
		}

	}
	if (e == 0) {
		suc.innerHTML = suc.innerHTML+"Test de taille grandissement : [OK]<br>";
	} else {
		err.innerHTML = err.innerHTML+"Test de taille grandissement : [Faux]<br>";
	}
	height_base = 200;
	width_base = height_base;
	ball.click();
	if (width_base+"px" != ball.style.width || height_base+"px" != ball.style.height) {
		err.innerHTML = err.innerHTML+"Test de taille fin : [Faux]<br>";
	} else {
		suc.innerHTML = suc.innerHTML+"Test de taille fin : [OK]<br>";
	}

	while (ball.style.width < 420+"px") {
		ball.click();
		height_base = height_base + 10;
		width_base = height_base;
	}

	let ball_jq = $("#ex00").find("div");
	i = 0;
	var s = 0;
	var e = 0;
	while (ball.style.width > 205+"px") {
		ball_jq.mouseover();
		ball_jq.mouseout();

		if (i == 0)
			i = 2;
		else if (i == 2)
			i = 1;
		else if (i == 1)
			i = 0;
		height_base = height_base - 5;
		width_base = height_base;

		if (color_base[i] != ball.style.backgroundColor) {
			console.log('faux');
			e++;
		} else {
			s++;
		}

		if (width_base+"px" != ball.style.width || height_base+"px" != ball.style.height) {
			e++;
		} else {
			s++;
		}
	}
	if (e == 0) {
		suc.innerHTML = suc.innerHTML+"Test de taille retrecissement : [OK]<br>";
	} else {
		err.innerHTML = err.innerHTML+"Test de taille retrecissement : [Faux]<br>";
	}

	//********************************************************ex01******************************************************\\

	console.log(window.event);
};
</script>
</html>