<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html>
<head> 
	<link rel="stylesheet" type="text/css" href="http://yui.yahooapis.com/combo?2.7.0/build/reset-fonts-grids/reset-fonts-grids.css&amp;2.7.0/build/base/base-min.css"> 
	<style>
		#img {font-family: Helvetica; text-align: center;}
		body {background: #E2DDB5; margin: 0px; padding: 1em; font-family: verdana;}
		h1, h2, h3 {font-family: helvetica;}
		h2 {margin-top: 2em;}
	</style>
</head>

<body>
	<div id="doc2" class="yui-t3">
		<div id="hd">
			<h1>Sarah and Evan's Wedding</h1>
		</div> 
		<div id="yui-main">
			<div class="yui-b">
				<div class="photostrip">
					<a href="http://www.flickr.com/photos/tags/goerwedding/">
				<?php

				$url = 'http://www.flickr.com/services/rest/?method=flickr.photos.search&per_page=32&tags=goerwedding&format=json&nojsoncallback=1&api_key=577c1e58091075500266da13577c2605';

				function getResource($url){
				        $ch = curl_init();
				        curl_setopt($ch, CURLOPT_URL, $url);
				        curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
				        $result = curl_exec($ch);
				        curl_close($ch);

				        return $result;
				}

				$rsp = json_decode(getResource($url), true);

				$photos = $rsp['photos']['photo'];
				shuffle($photos);

				for ($i=0; $i < 8; $i++) { 
					$photo = $photos[$i];	
					echo "<img src='http://farm" . $photo['farm'] . ".static.flickr.com/" . $photo['server'] . "/" . $photo['id'] . "_" . $photo['secret'] . "_s.jpg'>";
				}

				?>
					</a>
					<p><small><a href=" http://www.flickr.com/photos/rar77/sets/72157617652529053/">Engagement photos</a> by <a href="http://dagnall.net/">Jud Dagnall Photography</a>. Reload this page for more (randomly selected) photos. To add your own photos, upload them to <a href="http://flickr.com">Flickr</a> and <a href="http://www.flickr.com/photos/tags/goerwedding/">tag them as "goerwedding"</a>.</p>
					<p></p>
				</div>
				
				<h2 id="sarahandevan">Sarah &amp; Evan</h2>
				<ul>
					<li>Met: Saturday, June 23, 2007</li>
					<li>First Date: Monday, June 25, 2007</li>
					<li>Engaged: Monday, February 16, 2009</li>
					<li>Wedding: Sunday, July 12, 2009</li>
				</ul>


				<h3>Schedule</h3>
				<ul>
					<li>4:30 pm: Ceremony</li>
					<li>5:00 pm: Cocktail Hour</li>
					<li>6:30 pm: Dinner, followed by dancing</li>
				</ul>

				<p>Dress is business casual to semi-formal.

				<h2 id="weddingparty">The Wedding Party</h2>
				<ul>
					<li>Maid of Honor: Jennifer McNeil - Sarah's sister</li>
					<li>Matron of Honor: Amber Schnaider - Sarah's closest friend from college</li>
					<li>Bridesmaid: Cindy McCullough - Sarah's friend from teaching</li>
					<li>Bridesmaid: Tatiana Ortega - Sarah's friend through Creative Memories</li>
					<li>Bridesmaid: Elana Zelony - Evan's sister</li>
					<li>Bridesmaid: Sarah Goer - Evan's sister</li>
				</ul>
				<ul>
					<li>Best Man: Eric Stenberg - Evan's friend from grade school</li>
					<li>Ring Bearer: Beckett Lee-Messer - Evan's next door neighbor</li>
					<li>Groomsman: Michael Holy - Evan's friend from grade school</li>
					<li>Groomsman: Patrick Becker - Evan's friend from grade school</li>
					<li>Groomsman: Samuel Becker - Evan's friend from grade school</li>
					<li>Groomsman: Christopher McNeil - Sarah's brother</li>
				</ul>

				<h2 id="registry">Registry Information</h2>
				<p>We are registered at <a href="http://www.crateandbarrel.com/Gift-Registry/Guest/ViewRegistry.aspx?grid=4294446">Crate and Barrel</a> and <a href="http://www.rei.com/GiftRegistryDetails/GR1911732">REI</a>.

				<h2 id="hotel">Hotel Recommendations</h2>

				<p>There are many hotel options on El Camino Real. After checking out a number of places, here are a couple we found:</p>
				
				<h3><a href="http://www.paloaltocountryinn.com">Country Inn Motel</a></h3>
				<p>4245 El Camino Real<br>Palo Alto, CA 94306<br>Phone: 650-948-9154</p>

				<p>Rates are $76 and up for 1-2 persons per room (additional persons are $10 each per night)</p>
								
				<h3><a href="http://www.cppaloalto.crowneplaza.com">Crowne Plaza Cabana &mdash; Palo Alto</a></h3>
				<p>4290 El Camino Real<br>Palo Alto, CA 94306<br>Phone: 650-857-0787</p>
				
				<p>The regular rate is $129 per night for 1 king or two full beds.</p>
				
			</div>
		</div>
		<div class="yui-b">
			<img src="/images/wedding/sarah_evan_rarr_300.jpg" alt="Sarah and Evan" title="Sarah says, 'Nooo, Evan! Don't eat the guests!'">
			<p><small>Evan says, "RARRR! Come to our wedding!"</small></p>
			<h2>Venue Details</h2>
			<p>July 12, 2009 at <a href="http://www.etzchayim.org">Congregation Etz Chayim</a></p>
			<p>4161 Alma Street, Palo Alto, CA, 94306</p>

			<h3>Directions from 280 via 85 Northbound</h3>

			<p>From 280 take 85 northbound.  Take exit number 23, Evelyn Avenue.  Turn left on E. Evelyn Ave.  Turn right onto Castro Street.  Turn left on Central Expressway.  Continue on Alma Street.  Congregation Etz Chayim will be on your right at 4161 Alma Street.</p>

			<h3>Directions from 101</h3>

			<p>From 101 take exit number 400C, San Antonio Road Southbound, toward Los Altos.  Turn right onto Alma Street.  Congregation Etz Chayim will be on your right at 4161 Alma Street.</p>

			<h3>Parking</h3>

			<p>Once you arrive at the synagogue you will find that their parking is shared with the neighboring church.  You may park anywhere in the connected lots.</p>

			<h2 id="eventdetails">Event Details</h2>

			<p>Date &amp; Time: Sunday, July 12, 2009 @ 4:30pm</p>

			<p>The ceremony and reception will be held at the same venue.</p>
			
			<p>Feel free to <a href="mailto:goerwedding@me.com">send us music recommendations</a>.</p>
		</div>
		</div>
		<div id="ft"><!-- footer --></div> 
	</div>
</body>
</html>
