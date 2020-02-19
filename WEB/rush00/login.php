<?php
    include_once('lib.php');

    session_start();

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
    if ($_POST['submit'] === "Se connecter") {
        $login = $_POST['login'];
        $passwd = $_POST['passwd'];
        $auth = user_auth($login, $passwd);
        if ($auth === TRUE) {
            $_SESSION['loggued_on_user'] = $login;
            header("Location: index.php");
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
                <?php echo $auth; ?>
                <br />
                <input class="btn" type="submit" name="submit" value="Se connecter"/>
            </form>
            <a href="./create.php">Pas encore de compte ?</a>
            <a href="./modif.php">Envie de changer de mot de passe ?</a>
        </div>
    </div>
</body>
</html>
