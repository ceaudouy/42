<?php 
    include_once('lib.php');
    session_start();
    $_SESSION['id'] = "a";
    if (isset($_SESSION['loggued_on_user']) && !empty($_SESSION['loggued_on_user']))
    {
        $conn = sql_connect();
        $res = read_table($conn, "SELECT * FROM `Users` ORDER BY id DESC");
?>
<html>
    <head>
        <link rel="stylesheet" type="text/css" href="admin.css">
    </head>
    <body>
    <table>
            <tr>
                <td>nom</td>
                <td>prenom</td>
                <td>mail</td>
                <td>adresse</td>
                <td>droit admin</td>
                <td>action</td>
            </tr>
            <?php
            while ($user = mysqli_fetch_assoc($res))
            {
                ?>
                <tr>
                    <td><?= $user['name']; ?></td>
                    <td><?= $user['surname']; ?></td>
                    <td><?= $user['email']; ?></td>
                    <td><?= $user['address']; ?></td>
                    <td><?= $user['root_access']; ?></td>
                    <td><a href="suppr_user.php?login=<?= $user['id']; ?>">supprimer</a></td>
                </tr>
                <?php
                $i++;
            }
?>
</table>
</body>
</html>
<?php
    mysqli_close($conn);
}
else
    header("Location:index.php");
?>