<!DOCTYPE html>
<html>
<head>
    <title>EverQuest I Simulator - goer.org</title>
    <?php include '/big/dom/xgoer/www/assets/inc/head_assets.inc'; ?>
</head>
<body>
    <div id="main">
        <?php include '/big/dom/xgoer/www/assets/inc/header.inc'; ?>
        <div id="text">
			<h1>EverQuest I Simulator</h1>
			<p>Do you miss the original EverQuest? Are you jonesing for a fix? Well, look no further, my friend. Just reload this page to generate ever-more magical adventures in the land of Norrath!</p>

<?php 
$path = "/big/dom/xgoer/cgi-bin/dada/bin";
$dada_cmd = "$path/dada -w 200 $path/eq.pb";
?>

<h2>LOADING, PLEASE WAIT...</h2>
<pre><?php echo system($dada_cmd); ?> </pre>

<?php include '/big/dom/xgoer/www/assets/inc/footer.inc'; ?>
        </div>
    </div>
</body>
</html>
