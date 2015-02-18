#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <set>
#include <cstring>
#include <iomanip>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <vector>
#include <new>
#include <bitset>
#include <ctime>
#include <cassert>
#include <stdint.h>
#include <unistd.h>

using namespace std;

#define ll long long int
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9


template < typename X > X gcd( X a, X b ) { if( !b ) return a ; else return gcd(b, a%b) ; }

typedef vector<int> vi ;
typedef pair<int, int> ii ;



int t, a, b, x, y;
double p, q;
bool flag ;
double i ;

int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%d %d %d %d", &a, &b, &x, &y ) ;
		if( a > b ) 
			swap( a, b ) ;
		if( x > y ) 
			swap( x, y ) ;
		flag = true ;
		for( i = 0.0; i <= 90.0; i += 0.1 ) {
			p = (double) y * cos( (double) ((double) i * PI) / 180.0 ) + (double) x * cos( (double) ( (double) (90.0 - i ) * PI)/ 180) ;
			q = (double) y * sin( (double) ((double) i * PI) / 180.0 ) + (double) x * sin( (double) ( (double) (90.0 - i ) * PI)/ 180) ;
			if( ((double) b - p ) > EPS && ( (double)a - q ) > EPS ) {
				puts( "Escape is possible." ) ;
				flag = false ;
				break ;
			}
		}
		if( flag ) 
			puts("Box cannot be dropped." ) ;
	}
	return 0 ;
}

