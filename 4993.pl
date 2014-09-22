#!usr/bin/perl
use strict ;
use 5.010 ;
use 5.012 ;
use utf8 ;
my ( $input, $ans, $x, $y, $px, $py ) ;
$ans = 0.0 ;
chomp( $input = <STDIN> );
if( $input =~ m#.*\(([-]?[0-9]*\.?[0-9]*), ([-]?[0-9]*\.?[0-9]*)\)\.# ) {
	$px = $1;
	$py = $2;
}
while( 1 ) {
	chomp( $input = <STDIN> );
	last unless defined $input;
	if( $input =~ m#.*\(([-]?[0-9]*\.?[0-9]*), ([-]?[0-9]*\.?[0-9]*)\)\.# ) {
		$x = $1;
		$y = $2;
		$ans += sqrt( ($x - $px) * ($x - $px) + ($y - $py) * ($y - $py) );
	}
	$px = $x ;
	$py = $y ;
	printf "The salesman has traveled a total of %.3lf kilometers.\n", $ans;
}
