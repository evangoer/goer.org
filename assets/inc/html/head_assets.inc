<?php include $_SERVER['DOCUMENT_ROOT'].'/assets/inc/head_assets.inc'; ?>
<link href="/assets/js/syntaxhighlighter-1.x/styles/SyntaxHighlighter.css" type="text/css" rel="stylesheet">
<?php
$site_title_url = '/HTML/';
$site_title = 'The Pocket HTML Tutorial';

function get_page($uri) {
    $url_path = parse_url($uri, PHP_URL_PATH);
    return preg_replace('/\/(index\.html)*$/', '', $url_path);
}

function get_parent_page($page) {
    if (substr_count($page, '/') < 2) {
        return null;
    }
    return preg_replace('/\/\w+$/', '', $page);
}

function get_menu($site_map) {
    $page = get_page($_SERVER['REQUEST_URI']);
    $page_level = substr_count($page, '/');
    $parent_page = get_parent_page($page);
    $menu = array();

    if ($page_level == 1) {
        foreach ($site_map as $p) {
            if (substr_count($p['path'], '/') < 3) {
                array_push($menu, $p);
            } 
        }
    } elseif ($page_level == 2) {
        foreach ($site_map as $p) {
            if (strpos($p['path'], $page) === 0) {
                array_push($menu, $p);
            } 
        }
    } elseif ($page_level == 3) {
        foreach ($site_map as $p) {
            if (strpos($p['path'], $parent_page) === 0) {
                array_push($menu, $p);
            } 
        }
    }

    return $menu;
}

$site_map = array(
    array('path' => '/HTML', 'text' => 'Introduction'),
    array('path' => '/HTML/about', 'text' => 'About This Tutorial'),
    array('path' => '/HTML/introduction', 'text' => 'Getting Started'),
    array('path' => '/HTML/introduction/diving_in', 'text' => 'Diving In'),
    array('path' => '/HTML/introduction/structure', 'text' => 'Structure'),
    array('path' => '/HTML/introduction/tinkering', 'text' => 'Tinkering'),
    array('path' => '/HTML/introduction/elements', 'text' => 'Elements'),
    array('path' => '/HTML/introduction/attributes', 'text' => 'Attributes'),
    array('path' => '/HTML/basic', 'text' => 'Markup Basics'),
    array('path' => '/HTML/basic/paragraph_breaks', 'text' => 'Paragraph Breaks'),
    array('path' => '/HTML/basic/headings', 'text' => 'Headings'),
    array('path' => '/HTML/basic/font_styles', 'text' => 'Font Styles'),
    array('path' => '/HTML/basic/colors', 'text' => 'Colors'),
    array('path' => '/HTML/basic/links', 'text' => 'Links'),
    array('path' => '/HTML/basic/images', 'text' => 'Images'),
    array('path' => '/HTML/basic/lists', 'text' => 'Lists'),
    array('path' => '/HTML/intermediate', 'text' => 'Styling Basics'),
    array('path' => '/HTML/intermediate/style_attribute', 'text' => 'The style Attribute'),
    array('path' => '/HTML/intermediate/style_sheets', 'text' => 'Style Sheets'),
    array('path' => '/HTML/intermediate/classes_and_ids', 'text' => 'Classes and IDs'),
    array('path' => '/HTML/intermediate/div_and_span', 'text' => 'Div and Span'),
    array('path' => '/HTML/intermediate/font_control', 'text' => 'Font Control'),
    array('path' => '/HTML/intermediate/borders', 'text' => 'Borders'),
    array('path' => '/HTML/intermediate/margins_and_padding', 'text' => 'Margins and Padding'),
    array('path' => '/HTML/intermediate/align_and_indent', 'text' => 'Align and Indent'),
    array('path' => '/HTML/tables', 'text' => 'Tables'),
    array('path' => '/HTML/tables/table_structure', 'text' => 'Table Structure'),
    array('path' => '/HTML/tables/cellpadding_and_cellspacing', 'text' => 'Cellpadding and Cellspacing'),
    array('path' => '/HTML/tables/tables_and_css', 'text' => 'Tables and CSS')
);

$menu = get_menu($site_map);
?>
