<?php
// Tells what type of data needed on output
header('Content-type: application/json');
chdir("/home/pi/www/boarddata/");

$db = new SQLite3('boarddata.db');

// Selects all data points from board within the last 24 hours.
$statement = $db->prepare("SELECT * FROM data WHERE dt >= datetime('now','-1 day','localtime')");
//AND dt < datetime('now','localtime')");
$results = $statement->execute();

$data = array();

// Fetches each row of data matching column name with data point
while ($row = $results->fetchArray(SQLITE3_ASSOC)) {
	// Puts row array into a array of all rows
	$data[] = $row;
}

// Outputs our array of data called 'sensor' to stdout for JS
print json_encode(array('sensor' => $data));
?>
