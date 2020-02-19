
<?php
    if(session_status() == PHP_SESSION_NONE){
        session_start();
    }
    if ($_SESSION['loggued_on_user'] == "") {
        echo "<nav id=\"page-head\">
                <div id=\"toolsbar\">
                    <a href=\"create.php\">Créer un compte</a>
                    <a href=\"login.php\">Se connecter</a>";
    }
    else {
        echo "<nav id=\"page-head\">
                <div id=\"toolsbar\">
                <a>{$_SESSION['loggued_on_user']}</a>
                <a href='./logout.php'>logout</a>";
    }
?>
        <a id="cart" href="panier.php">Panier</a>
        <a id="site-logo" href="index.php">Acceuil</a>
    </div>
    <div id="navbar">
        <a href="multimedia.php">Casques</a>
        <a href="electro.php">Ecouteurs</a>
        <a href="livre.php">Sans fil</a>
        <a href="voiture.php">Avec fil</a>
    </div>
</nav>