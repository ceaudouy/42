<?php 
    include_once('lib.php');
    session_start();
    $_SESSION['loggued_on_user'] = "a";
    if (isset($_SESSION['loggued_on_user']) && !empty($_SESSION['loggued_on_user']))
    {
        $conn = sql_connect();
        $res = read_table($conn, "SELECT * FROM `Product` ORDER BY id DESC");
?>
<html>
    <head>
        <link rel="stylesheet" type="text/css" href="admin.css">
    </head>
    <body>
    <table>
            <tr>
                <td>Produit</td>
                <td>Description</td>
                <td>Prix</td>
                <td>notes_full</td>
                <td>notes_nb</td>
                <td>catégorie</td>
            </tr>
            <?php
            while ($product = mysqli_fetch_assoc($res))
            {
                ?>
                <tr>
                    <td><?= $product['name']; ?></td>
                    <td><?= $product['description']; ?></td>
                    <td><?= $product['price']; ?></td>
                    <td><?= $product['notes_full']; ?></td>
                    <td><?= $product['notes_nb']; ?></td>
                    <?php if ($product['mic'] == 1)
                        ?><td><?= $product['mic']; ?></td>
                    <?php if ($product['kid'] == 1)
                        ?><td><?= $product['kid']; ?></td>
                    <?php if ($product['gaming'] == 1)
                        ?><td><?= $product['gaming']; ?></td>
                    <?php if ($product['in-ear'] == 1)
                        ?><td><?= $product['in-ear']; ?></td>
                    <?php if ($product['over-ear'] == 1)
                        ?><td><?= $product['over-ear']; ?></td>
                    <?php if ($product['around-ear'] == 1)
                        ?><td><?= $product['around-ear']; ?></td>
                    <td><a href="suppr.php?id=<?= $product['id']; ?>">supprimer</a></td>
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