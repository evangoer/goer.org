<div id="page" class="hfeed site pure-g-r">
<div class="pure-u sidebar" role="banner">
<header id="masthead" class="site-header">
<?php
    if (!isset($siteTitle)) {
        $siteTitle = 'goer.org';
        $siteTitleURL = '/';
    }

    if (!isset($siteDescription)) {
        $siteDescription = 'Writing, code, etc.';
    }
?>
<div class="site-branding">
    <h1 class="site-title"><a href="<?php echo $siteTitleURL ?>" rel="home"><?php echo $siteTitle ?></a></h1>
    <h2 class="site-description"><?php echo $siteDescription ?></h2>
</div>
<nav class="main-navigation" role="navigation">
<?php
    if (!isset($menu)) {
        $menu = array(
           '/Journal/' => 'Journal',
           '/YUI/' => 'YUI 3 Cookbook',
           '/HTML/' => 'Pocket HTML Tutorial',
           '/About/' => 'About'
        );
    }
?>
<ul class="menu">
<?php foreach ($menu as $url => $text) { ?>
    <li><a href="<?php echo $url ?>"><?php echo $text ?></a></li>
<?php } ?>
</ul>
</nav>
</header>
</div>
<div id="content" class="site-content pure-u">
<div id="primary" class="content-area">
