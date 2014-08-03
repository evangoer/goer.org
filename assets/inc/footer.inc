</div>
</div>
<footer id="colophon" class="site-footer" role="contentinfo">
Last updated <?php echo date ("F d, Y \a\\t g:i a.", getlastmod()); ?> 
&copy; 2001 &ndash; <?php echo date ("Y", time()); ?> by <a href="/">Evan Goer</a>
<a href="/Feeds/journal.atom"><img src="/assets/images/feed.png" class="feed"></a>
<?php if (isset($cc) && $cc !== false) { ?>
  <a rel="license" href="http://creativecommons.org/licenses/by/3.0/">Some Rights Reserved</a>.
<?php } ?>
</footer>
