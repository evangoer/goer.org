<div id="page" class="hfeed site pure-g-r">
<div class="pure-u sidebar" role="banner">
<header id="masthead" class="site-header">
<?php
    if (!isset($site_title)) {
        $site_title = 'goer.org';
        $site_title_url = '/';
    }

    if (!isset($site_description)) {
        $site_description = 'Writing, code, etc.';
    }
?>
<div class="site-branding">
    <h1 class="site-title"><a href="<?php echo $site_title_url ?>"
    rel="home"><?php echo $site_title ?></a></h1>
    <h2 class="site-description"><?php echo $site_description ?></h2>
</div>
<nav class="main-navigation" role="navigation">
<?php
    if (!isset($menu)) {
        $menu = array(
           array('path' => '/Journal/', 'text' => 'Journal'),
           array('path' => '/YUI/', 'text' => 'YUI 3 Cookbook'),
           array('path' => '/HTML/', 'text' => 'Pocket HTML Tutorial'),
           array('path' => '/About/', 'text'  => 'About')
        );
    }
?>
<ul class="menu">
<?php foreach ($menu as $page ) { ?>
    <li><a href="<?php echo $page['path'] ?>"><?php echo $page['text'] ?></a></li>
<?php } ?>
</ul>
</nav>
</header>
</div>
<div id="content" class="site-content pure-u">
<div id="primary" class="content-area">
