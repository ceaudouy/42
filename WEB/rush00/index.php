<?php include_once('lib.php'); ?>
<html>
    <head>
        <?php include('head.php') ?>
    </head>

    <body>
        <?php include('nav.php') ?>
        <h2>Nouveautés</h2>
        <section class="products_view">
			<?php products_view(array()); ?>
		</section>
    </body>
</html>