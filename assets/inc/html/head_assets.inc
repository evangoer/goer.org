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
    $page_info = $site_map[$desc_key];
    if (isset($page_info['desc'])) {
        return $page_info['desc'];
    }
    return '';
}

function path_matches($path, $path_to_match) {
    return strpos($path, $path_to_match) === 0;
}

function not_a_leaf($path) {
    return substr_count($path, '/') < 3;
}

function menu_items($site_map, $condition, $path_to_match) {
    $menu = array();
    foreach ($site_map as $path => $page_info) {
        if (call_user_func($condition, $path, $path_to_match)) {
            $link = array('path' => $path, 'text' => $page_info['text']);
            array_push($menu, $link);
        }
    }
    return $menu;
}

function get_menu($site_map) {
    $page = get_page($_SERVER['REQUEST_URI']);
    $page_level = substr_count($page, '/');

    switch ($page_level) {
    case 1:
        return menu_items($site_map, 'not_a_leaf', null);
    case 2:
        return menu_items($site_map, 'path_matches', $page);
    case 3:
        return menu_items($site_map, 'path_matches', get_parent($page));
    default:
        return array();
    }
}

$site_map = array(
    '/HTML' => array('text' => 'Introduction', 'desc' => ''),
    '/HTML/about' => array('text' => 'About This Tutorial', 'desc' => ''),
    '/HTML/introduction' => array('text' => 'Getting Started', 'desc' => 'Chapter 1. Getting Started'),
    '/HTML/introduction/diving_in' => array('text' => 'Diving In'),
    '/HTML/introduction/structure' => array('text' => 'Structure'),
    '/HTML/introduction/tinkering' => array('text' => 'Tinkering'),
    '/HTML/introduction/elements' => array('text' => 'Elements'),
    '/HTML/introduction/attributes' => array('text' => 'Attributes'),
    '/HTML/basic' => array('text' => 'Markup Basics', 'desc' => 'Chapter 2. Markup Basics'),
    '/HTML/basic/paragraph_breaks' => array('text' => 'Paragraph Breaks'),
    '/HTML/basic/headings' => array('text' => 'Headings'),
    '/HTML/basic/font_styles' => array('text' => 'Font Styles'),
    '/HTML/basic/colors' => array('text' => 'Colors'),
    '/HTML/basic/links' => array('text' => 'Links'),
    '/HTML/basic/images' => array('text' => 'Images'),
    '/HTML/basic/lists' => array('text' => 'Lists'),
    '/HTML/intermediate' => array('text' => 'Styling Basics', 'desc' => 'Chapter 3. Styling Basics'),
    '/HTML/intermediate/style_attribute' => array('text' => 'The style Attribute'),
    '/HTML/intermediate/style_sheets' => array('text' => 'Style Sheets'),
    '/HTML/intermediate/classes_and_ids' => array('text' => 'Classes and IDs'),
    '/HTML/intermediate/div_and_span' => array('text' => 'Div and Span'),
    '/HTML/intermediate/font_control' => array('text' => 'Font Control'),
    '/HTML/intermediate/borders' => array('text' => 'Borders'),
    '/HTML/intermediate/margins_and_padding' => array('text' => 'Margins and Padding'),
    '/HTML/intermediate/align_and_indent' => array('text' => 'Align and Indent'),
    '/HTML/tables' => array('text' => 'Tables', 'desc' => 'Chapter 4. Tables'),
    '/HTML/tables/table_structure' => array('text' => 'Table Structure'),
    '/HTML/tables/cellpadding_and_cellspacing' => array('text' => 'Cellpadding and Cellspacing'),
    '/HTML/tables/tables_and_css' => array('text' => 'Tables and CSS')
);

$site_title_url = '/HTML/';
$site_title = 'The Pocket HTML Tutorial';

$site_description = get_description($site_map);
$menu = get_menu($site_map);
?>
