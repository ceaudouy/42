<?php
    session_start();
    $login = $_GET['login'];
    $passwd = $_GET['passwd'];
    $submit = $_GET['submit'];
    if (isset($login) AND !empty($login) AND isset($passwd) AND !empty($passwd) AND isset($submit) AND !empty($submit)) {
        $_SESSION['login'] = $login;
        $_SESSION['passwd'] = $passwd;
    }
?>
<html><body>
<form method="get">
    Identifiant: <input placeholder="login" required name="login" value="<?php if(isset($_SESSION['login']) && !empty($_SESSION['login'])) {echo $_SESSION['login'];}?>" />
    <br />
    Mot de passe:  <input placeholder="passwd" required name="passwd" value="<?php if(isset($_SESSION['passwd']) && !empty($_SESSION['passwd'])) {echo $_SESSION['passwd'];}?>" />
   <input type="submit" name="submit" value="OK"/>
</form>
</body></html>