<?PHP

function gplus_count($url) {
    /* get source for custom +1 button */
    $contents = file_get_contents('https://plusone.google.com/_/+1/fastbutton?url=' .  $url);
 
    /* pull out count variable with regex */
    preg_match('/window\.__SSR = {c: ([\d]+)/', $contents, $matches);
 
    /* if matched, return count, else zed */
    if (isset($matches[0])) {
        return (int)str_replace('window.__SSR = {c: ', '', $matches[0]);
    }
    return 0;
}

/**
 * @param $url
 * @return int
 */
function gshare_count($url) {
    $shares_url = 'https://plus.google.com/ripple/details?url=' . $url . '&hl=en';
    $response = file_get_contents($shares_url);
    $shares_match = preg_match('@([0-9]+) public shares@', $response, $matches);
    if (isset($matches[1])) {
        return $matches[1];
    }
    return 0;
}
