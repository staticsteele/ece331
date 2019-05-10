#!/usr/bin/perl
# Perl Script to see how it opens databases.
# Bad code, doesn't actually close  DB.


use DBI;
use strict;

my $driver = "SQLite";
my $database = "boarddata.db";
my $dsn = "DBI:$driver:dbname=$database";
my $userid = "";
my $password = "";
my $dbh = DBI->connect($dsn, $userid, $password, { RaiseError => 1  }) 
   or die $DBI::errstr;

print "Opened database successfully\n";
