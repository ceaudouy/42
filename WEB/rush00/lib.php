<?php

// product defintion : (table name == category)
//		-ID					<- INT
//		-name				<- TINYTEXT (0-255 chars)
//		-imgs  				<- serrialized array (TEXT => ~65000 chars)
// 		-price				<- FLOAT
// 		-notes_full			<- INT
// 		-notes_nb			<- INT
// 		-description		<- TEXT (~65000 chars)

// CREATE TABLE `rush00`. ( `id` INT NOT NULL AUTO_INCREMENT , `stock` INT NULL DEFAULT NULL , `name` TINYTEXT NULL DEFAULT NULL , `description` TEXT NULL DEFAULT NULL , `pictures` TEXT NULL DEFAULT NULL , `price` FLOAT NULL DEFAULT NULL , `notes_full` INT NULL DEFAULT NULL , `notes_nb` INT NULL DEFAULT NULL , `cordless` BOOLEAN NULL DEFAULT NULL , `mic` BOOLEAN NULL DEFAULT NULL , `kids` BOOLEAN NULL DEFAULT NULL , `gaming` BOOLEAN NULL DEFAULT NULL , `in-ear` BOOLEAN NULL DEFAULT NULL , `over-ear` BOOLEAN NULL DEFAULT NULL , `around-ear` BOOLEAN NULL DEFAULT NULL , `color_id` BOOLEAN NULL DEFAULT NULL , PRIMARY KEY (`id`)) ENGINE = InnoDB;

// INSERT INTO `Product` (`id`, `name`, `description`, `pictures`, `price`, `notes_full`, `notes_nb`, `cordless`, `mic`, `kids`, `gaming`, `in-ear`, `over-ear`, `around-ear`, `color_id`) VALUES (NULL, 'TEST: product 1', 'Description about product nb 1', 'a:1:{i:0;s:23:\"./imgs/test_pattern.svg\";}', '0.50', '25', '6', '0', '0', '0', '1', '0', '0', '0', '1');

	function error($err_msg) {
		header("Location: error.php?err=$err_msg");
	}

	function get_sql_parameters() {
		$dburl = "localhost:3306";
		$login = "root";
		$passwd = "qwerty";
		$dbname = "rush00";
		return (compact('dburl', 'login', 'passwd', 'dbname'));
	}

	function sql_connect() {
		$params = get_sql_parameters();
		$dbname = $params['dbname'];
		$conn = mysqli_connect($params['dburl'], $params['login'], $params['passwd']);
		if (!$conn)
			error('Could not connect: ('.mysqli_connect_errno().')'.mysqli_connect_error(). ', '.mysqli_error($conn));
		if (!mysqli_select_db($conn, $dbname))
			error("Error selecting database: " . mysqli_error($conn));
		return ($conn);
	}

	function read_table($conn, $query) {
		$result = mysqli_query($conn, $query);
		if (!$result)
			error("Error within database table: " . mysqli_error($conn));
		return ($result);
	}

	function products_view($categories) {
		function __print_product($product, $category) { //product[brand] doesnt exist (yet)
			$average_note = number_format($product['notes_full'] / $product['notes_nb'], 2);
			$picture = array_values(unserialize($product['pictures']))[0];
			// echo $product['imgs'], "\n";
			echo "<a class='product_frame' href='./single.php?id={$product['id']}'>"
					."<img class='brand_logo' src='{$product['brand']}'>"
					."<div class='item-block'>"
						."<img class='item-img' src='{$picture}'>"
						."<div class='item-info'>"
							."<p class='item-desc'>{$product['name']}</p>"
							."<i class='item-note'>{$average_note} out of 5\t({$product['notes_nb']} notes)</i>"
							."<p class='item-price'>{$product['price']}€</p>"
						."</div>"
					."</div>"
				."</a>";
		}
		$query = "SELECT * FROM `products` WHERE id != 0";
		foreach ($categories as $category=>$value) {
			$query .= " AND WHERE $category = $value";
		}
		$query .= " ORDER BY id DESC";

		$sql_conn = sql_connect();
		$products_data = read_table($sql_conn, $query);
		while (($product = mysqli_fetch_assoc($products_data))) {
			__print_product($product, $categories);
		}
	}

?>