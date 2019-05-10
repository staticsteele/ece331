#!/usr/bin/perl
# Steele Muchemore-Allen ECE 331 
# Perl script that grabs dat from serial port
# and imports it into an sqlite database table

use Device::SerialPort;
use DBI;
use strict;

#Opens the serial device for communication
my $port = new Device::SerialPort("/dev/ttyACM0")
	or die "Can't open /dev/ttyACM0: $!\n";

#Sends a character to recieve data from device
$port->write('a');

#Looks for device being sent by device
my $data = $port->lookfor();

#Removes newlines and parses data 
chomp($data);
my @list = split(/[ |]+/, $data);

#Removes data for clear run next time 
$port->lookclear;

#opens the database for manipulation
my $driver = "SQLite";
my $database = "boarddata.db";
my $dsn = "DBI:$driver:dbname=$database";
my $userid = "";
my $password = "";
my $dbh = DBI->connect($dsn, $userid, $password, { RaiseError => 1  }) 
   or die $DBI::errstr;
print "Opened database successfully\n";

#Sends parsed data to the pre-created table, with the current time included
my $stmt = qq(INSERT INTO data (TEMP1,IR,FULL,VIS,LUX,TEMP2,PRESSURE,HUMID, dt)
			VALUES ($list[0], $list[1], $list[2], $list[3], $list[4], $list[5],
			$list[6], $list[7], datetime('now','localtime')));
my $rv = $dbh->do($stmt) or die $DBI::errstr;

print "Records created successfully\n";

#Gets all columns from specified table 
$stmt = qq(SELECT TEMP1, IR, FULL, VIS, LUX, TEMP2, PRESSURE, HUMID, dt from data;);
my $sth = $dbh->prepare($stmt);
 $rv = $sth->execute() or die $DBI::errstr;

if($rv < 0) {
	   print $DBI::errstr;
}

#Releases the database and serial port
$sth->finish();
$dbh->disconnect();
$port->close or warn "close failed";
print "Closed database successfully\n";
