<?php header("HTTP/1.1 404 Not Found"); ?>
<!DOCTYPE html>
<html>
<head>
    <title>Page Not Found: A 404 Haiku - goer.org</title>
    <?php include $_SERVER['DOCUMENT_ROOT'].'/assets/inc/head_assets.inc'; ?>
	<style>
		div.haiku {
			margin: 1.0em;
		}
		div.haiku p {
			text-indent: 0em;
			font-size: 1.6em;
			text-align: center;
			font-style: italic;
			letter-spacing: 0.08em;
		}
	</style>
</head>
<body>
    <div id="main">
        <?php include $_SERVER['DOCUMENT_ROOT'].'/assets/inc/header.inc'; ?>
        <div id="text">
			<h1>Page Not Found: A 404 Haiku</h1>

			<?php 
			$haiku = array(
				"<p>A file that big?</p><p>It might be very useful.</p><p>But now it is gone.</p>",
				"<p>You step in the stream,</p><p>but the water has moved on.</p><p>This page is not here.</p>",
				"<p>The Web site you seek</p><p>cannot be located but</p><p>endless others exist</p>",
				"<p>Rather than a beep</p><p>Or a rude error message,</p><p>These words: &#8220;File not found&#8221;.</p>",
				"<p>To have no errors</p><p>Would be life without meaning</p><p>No struggle, no joy</p>",
				"<p>Hal, open the file</p><p>Hal, open the damn file, Hal</p><p>open the, please Hal</p>",
				"<p>There is a chasm</p><p>of carbon and silicon</p><p>the software can&#8217;t bridge</p>",
				"<p>With searching comes loss</p><p>and the presence of absence:</p><p>Your file not found.</p>",
				"<p>Errors have occurred.</p><p>We won&#8217;t tell you where or why</p><p>Lazy programmers.</p>"
			);
		?>

		<div class="haiku">
			<?php echo $haiku[array_rand($haiku)]; ?>
		</div>
		<p>
			My deepest apologies, but the page you are seeking does not exist.
			Please feel free to <a href="/About/#contact" title="Send me an Email">alert
			me to the problem</a>, and I'll try to help.
		</p>
		<p>
			Other than that, you can try visiting the <a href="/">home page</a>,
			the <a href="/Journal/">journal archive</a>, the 
			<a href="/HTML/">HTML tutorial</a>, or whereever strikes your fancy.
		</p>
		<?php 
			$seealsoLink['Journal/2006/06/bad_movie_classification_system_part_one.html'] = 'Bad Movie Classification System: Part One';
			$seealsoLink['/HTML/intermediate/margins_and_padding/'] = 'HTML Tutorial: Margins and Padding';
			$seealsoLink['/Journal/2008/07/decluttering_for_geeks_computer_components.html'] = 'Decluttering for Geeks: Computer Components';
			$seealsoLink['/Toys/EverQuest/'] = 'EverQuest I Simulator';
			$seealsoLink['/2006/08/literary_vs_genre_explained_using_pie.html'] = 'Literary vs. Genre, Explained Using Pie';
			$seealsoLink['/htmlhorror/htmlhorror1.html'] = 'The Page of the Damned [BEWARE!]';
			include $_SERVER['DOCUMENT_ROOT'].'/assets/inc/footer.inc'; 
		?>
        </div>
    </div>
</body>
</html>
