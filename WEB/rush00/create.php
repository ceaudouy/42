<?php
    include_once('lib.php');

    session_start();

    function user_create($login, $passwd) {
        $conn = sql_connect();
        $passwd = hash("whirlpool", $passwd);
        $res = read_table($conn, "SELECT * FROM `Users` WHERE `email` = '$login'");
        if (mysqli_fetch_assoc($res) !== NULL)
            return ("User already exists !");
        read_table($conn, "INSERT INTO `Users` (`id`,`email`,`password`,`name`,`surname`,`address`,`root_access`) VALUES(NULL,'$login','$passwd','toto','trotro','nazareth','0');");
        mysqli_close($conn);
        return (TRUE);
    }

    function user_auth($login, $passwd) {
        if (preg_match('/[^\'`]*@[^\'`]*\.[^\'`]*/', $_POST['login']) === 0)
            return ("This is not an email address");
        $conn = sql_connect();
        $passwd = hash("whirlpool", $passwd);
        $res = read_table($conn, "SELECT * FROM `Users` WHERE `email` = '$login'");
        $user = mysqli_fetch_assoc($res);
        mysqli_close($conn);
        if ($user['password'] === $passwd)
            return (TRUE);
        else if ($user == NULL)
            return ("User not found");
        else
            return ("Invalid password");
    }

    $auth = "";
    if ($_POST['submit'] === "Créer votre compte") {
        $login = $_POST['login'];
        $passwd = $_POST['passwd'];
        if (preg_match('/[^\'`]*@[^\'`]*\.[^\'`]*/', $_POST['login']) === 0)
            $auth = "Invalid email address";
        else if (trim($passwd) === "")
            $auth = "Invalid password";
        else {
            $auth = user_create($login, $passwd);
            if ($auth === TRUE) {
                $_SESSION['loggued_on_user'] = $login;
                header("Location: index.php");
            }
        }
    }
?>
<html>
<head>
    <?php include('head.php') ?>
    <title>Login</title>
    <meta charset="utf-8">
</head>
<body>
    <?php include('nav.php') ?>
    <div class="master_form">
        <div class="form">
            <h2>CONNECTION</h2>
            <hr>
            <br />
            <form method="post">
                <input required maxlength="64" name="login" placeholder="address email" />
                <br />
                <input required maxlength="64" name="passwd" placeholder="mot de passe" />
                <input required maxlength="64" name="passwd2" placeholder="mot de passe" />
                <?php echo $auth; ?>
                <br />
                <input class="btn" type="submit" name="submit" value="Créer votre compte"/>
            </form>
            <a href="./create.php">Pas encore de compte ?</a>
            <a href="./modif.php">Envie de changer de mot de passe ?</a>
        </div>
    </div>
</body>
</html>
