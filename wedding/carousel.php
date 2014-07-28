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

// Call getResource to make the request.
$rsp = json_decode(getResource($url), true);

//var_dump($rsp);

$photos = $rsp['photos']['photo'];
shuffle($photos);

for ($i=0; $i < 5; $i++) { 
	$photo = $photos[$i];	
	echo "<img src='http://farm" . $photo['farm'] . ".static.flickr.com/" . $photo['server'] . "/" . $photo['id'] . "_" . $photo['secret'] . "_s.jpg'>";
}

?>