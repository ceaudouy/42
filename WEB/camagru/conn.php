<?php
	function sql_conn() {
		$bdd = new PDO('mysql:host=127.0.0.1;dbname=user_space', 'root', 'qwerty');
		return ($bdd);
	}		
?>