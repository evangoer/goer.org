<?php include $_SERVER['DOCUMENT_ROOT'].'/assets/inc/head_assets.inc'; ?>
<link href="/assets/js/syntaxhighlighter-1.x/styles/SyntaxHighlighter.css" type="text/css" rel="stylesheet">
<?php
function get_page($uri) {
    $url_path = parse_url($uri, PHP_URL_PATH);
    return preg_replace('/\/(index\.html)*$/', '', $url_path);
}

function get_parent($page) {
    if (substr_count($page, '/') < 2) {
        return null;
    }
    return preg_replace('/\/\w+$/', '', $page);
}

function get_description($site_map) {
    $page = get_page($_SERVER['REQUEST_URI']);
    $desc_key = not_a_leaf($page) ? $page : get_parent($page);
    foreach ($site_map as $p) {
        if ($p['path'] == $desc_key && isset($p['desc'])) {
            return $p['desc'];
        }
    }
    return '';
}

function chapter_menu($site_map, $path_to_match) {
    $menu = array();
    foreach ($site_map as $p) {
        if (strpos($p['path'], $path_to_match) === 0) {
            array_push($menu, $p);
        }
    }
    return $menu;
}

function not_a_leaf($p) {
    $path = is_array($p) ? $p['path'] : $p;
    return substr_count($path, '/') < 3;
}

function get_menu($site_map) {
    $page = get_page($_SERVER['REQUEST_URI']);
    $page_level = substr_count($page, '/');

    switch ($page_level) {
    case 1:
        return array_filter($site_map, 'not_a_leaf');
    case 2:
        return call_user_func('chapter_menu', $site_map, $page);
    case 3:
        return call_user_func('chapter_menu', $site_map, get_parent($page));
    default:
        return array();
    }
}

$site_map = array(
    array('path' => '/HTML', 'text' => 'Introduction', 'desc' => ''),
    array('path' => '/HTML/about', 'text' => 'About This Tutorial', 'desc' => ''),
    array('path' => '/HTML/introduction', 'text' => 'Getting Started', 'desc' => 'Chapter 1. Getting Started'),
    array('path' => '/HTML/introduction/diving_in', 'text' => 'Diving In'),
    array('path' => '/HTML/introduction/structure', 'text' => 'Structure'),
    array('path' => '/HTML/introduction/tinkering', 'text' => 'Tinkering'),
    array('path' => '/HTML/introduction/elements', 'text' => 'Elements'),
    array('path' => '/HTML/introduction/attributes', 'text' => 'Attributes'),
    array('path' => '/HTML/basic', 'text' => 'Markup Basics', 'desc' => 'Chapter 2. Markup Basics'),
    array('path' => '/HTML/basic/paragraph_breaks', 'text' => 'Paragraph Breaks'),
    array('path' => '/HTML/basic/headings', 'text' => 'Headings'),
    array('path' => '/HTML/basic/font_styles', 'text' => 'Font Styles'),
    array('path' => '/HTML/basic/colors', 'text' => 'Colors'),
    array('path' => '/HTML/basic/links', 'text' => 'Links'),
    array('path' => '/HTML/basic/images', 'text' => 'Images'),
    array('path' => '/HTML/basic/lists', 'text' => 'Lists'),
    array('path' => '/HTML/intermediate', 'text' => 'Styling Basics', 'desc' => 'Chapter 3. Styling Basics'),
    array('path' => '/HTML/intermediate/style_attribute', 'text' => 'The style Attribute'),
    array('path' => '/HTML/intermediate/style_sheets', 'text' => 'Style Sheets'),
    array('path' => '/HTML/intermediate/classes_and_ids', 'text' => 'Classes and IDs'),
    array('path' => '/HTML/intermediate/div_and_span', 'text' => 'Div and Span'),
    array('path' => '/HTML/intermediate/font_control', 'text' => 'Font Control'),
    array('path' => '/HTML/intermediate/borders', 'text' => 'Borders'),
    array('path' => '/HTML/intermediate/margins_and_padding', 'text' => 'Margins and Padding'),
    array('path' => '/HTML/intermediate/align_and_indent', 'text' => 'Align and Indent'),
    array('path' => '/HTML/tables', 'text' => 'Tables', 'desc' => 'Chapter 4. Tables'),
    array('path' => '/HTML/tables/table_structure', 'text' => 'Table Structure'),
    array('path' => '/HTML/tables/cellpadding_and_cellspacing', 'text' => 'Cellpadding and Cellspacing'),
    array('path' => '/HTML/tables/tables_and_css', 'text' => 'Tables and CSS')
);

$site_title_url = '/HTML/';
$site_title = 'The Pocket HTML Tutorial';

$site_description = get_description($site_map);
$menu = get_menu($site_map);
?>
