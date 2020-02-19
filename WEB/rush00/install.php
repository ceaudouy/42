<?php
	include('lib.php');

	$hints = "<br />Pleade add 'ErrorDocument 404 /rush00/error.php?err=404' to you vhost or .htaccess"
			."<br />Please comment 'skip-name-resolve=1' in your mysql config file";

	$params = get_sql_parameters();
	$conn = mysqli_connect($params['dburl'], $params['login'], $params['passwd']);
	if ($conn === FALSE)
		error('Could not connect: ('.mysqli_connect_errno().')'.mysqli_connect_error(). ', '.mysqli_error($conn).$hints);

	$query = "DROP DATABASE IF EXISTS `rush00`";
	if (mysqli_query($conn, $query) === FALSE)
		error("Error cleaning database: " . mysqli_error($conn).$hints);

	$query = "CREATE DATABASE IF NOT EXISTS `{$params['dbname']}`";
	if (mysqli_query($conn, $query) === FALSE)
		error("Error creating database: " . mysqli_error($conn).$hints);
	if (mysqli_select_db($conn, $params['dbname']) === FALSE)
		error("Error selecting database: " . mysqli_error($conn).$hints);

	$query = "CREATE TABLE `Products` (
		`id` INT NOT NULL AUTO_INCREMENT,
		`inventory` INT NULL DEFAULT NULL,
		`name` TINYTEXT NULL DEFAULT NULL,
		`description` TEXT NULL DEFAULT NULL,
		`pictures` TEXT NULL DEFAULT NULL,
		`price` FLOAT NULL DEFAULT NULL,
		`notes_full` INT NULL DEFAULT NULL,
		`notes_nb` INT NULL DEFAULT NULL,
		`cordless` BOOLEAN NULL DEFAULT NULL,
		`mic` BOOLEAN NULL DEFAULT NULL,
		`kids` BOOLEAN NULL DEFAULT NULL,
		`gaming` BOOLEAN NULL DEFAULT NULL,
		`in-ear` BOOLEAN NULL DEFAULT NULL,
		`over-ear` BOOLEAN NULL DEFAULT NULL,
		`around-ear` BOOLEAN NULL DEFAULT NULL,
		`color_id` BOOLEAN NULL DEFAULT NULL,
		PRIMARY KEY (`id`)
	  ) ENGINE = InnoDB;";
	if (mysqli_query($conn, $query) === FALSE)
		error("Error creating table: " . mysqli_error($conn).$hints);

	$query = "INSERT INTO `Products` (`id`,`inventory`,`name`,`description`,`pictures`,`price`,`notes_full`,`notes_nb`,`cordless`,`mic`,`kids`,`gaming`,`in-ear`,`over-ear`,`around-ear`,`color_id`)
				VALUES (NULL,'5','TEST: product 1','Description about product nb 1','a:1:{i:0;s:23:\"./imgs/test_pattern.svg\";}','0.50','25','6','0','0','0','1','0','0','0','1');";
	if (mysqli_query($conn, $query) === FALSE)
		error("Error while adding product to table: " . mysqli_error($conn).$hints);

	$passwd = hash("whirlpool", "root");
	$query = "CREATE TABLE `rush00`.`Users` (
		`id` INT NOT NULL AUTO_INCREMENT,
		`email` TINYTEXT NOT NULL,
		`password` VARCHAR(128) NOT NULL,
		`name` TINYTEXT NOT NULL,
		`surname` TINYTEXT NOT NULL,
		`address` TEXT NOT NULL,
		`root_access` BOOLEAN NOT NULL DEFAULT FALSE,
		PRIMARY KEY (`id`)
	  ) ENGINE = InnoDB;";
	if (mysqli_query($conn, $query) === FALSE)
		error("Failed to create Users table: " . mysqli_error($conn).$hints);
	$query = "INSERT INTO
		`Users` (`id`,`email`,`password`,`name`,`surname`,`address`,`root_access`)
  		VALUES(NULL,'root@root.root','$passwd','root','root','/','1');";
	if (mysqli_query($conn, $query) === FALSE)
		error("Failed to create root user: " . mysqli_error($conn).$hints);

	$query = "CREATE TABLE `rush00`.`Transactions` (
		`id` INT NOT NULL AUTO_INCREMENT,
		`item_id` INT NOT NULL,
		`user_id` INT NOT NULL,
		`date` TIMESTAMP NOT NULL,
		`shipping_company` SMALLINT NOT NULL,
		`delivery_address` TEXT NOT NULL,
		PRIMARY KEY (`id`)
	  ) ENGINE = InnoDB;";
	if (mysqli_query($conn, $query) === FALSE)
		error("Failed to create Transactions table: " . mysqli_error($conn).$hints);

	mysqli_close($conn);
	echo "All Good !\n";
?>