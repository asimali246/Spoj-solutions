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



const ll N = 1e5 + 10 ;
int t = 10;
ll a, b, c, d, i, p, q, x, y, ans;


inline void take() {
	if( x + y != 0 ) 
		ans = min( ans, x + y ) ;
}
int main() {
	while( t-- ) {
		ans = INF ;
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d) ;
		for( p = -N; p <= N; ++p ) {
			if( c == 0 ) 
				q = 0 ;
			else {
				double temp = (double) ( -p * a ) / (double) c ;
				if( (p * a) % c == 0 ) 
					temp += 1.0 ;
				q = (ll) ceil( temp ) ;
			}
			x = abs( p * a + q * c ) ;
			y = abs( p * b + q * d ) ;
			take() ;
			if( c == 0 ) 
				q = 0 ;
			else {
				double temp = (double) ( -p * a ) / (double) c ;
				if( (p * a) % c == 0 ) 
					temp -= 1.0 ;
				q = (ll) floor( temp ) ;
			}
			x = abs( p * a + q * c ) ;
			y = abs( p * b + q * d ) ;
			take() ;
		}
		for( p = -N; p <= N; ++p ) {
			if( d == 0 ) 
				q = 0 ;
			else {
				double temp = (double) ( -p * b ) / (double) d ;
				if( (p * b) % d == 0 ) 
					temp += 1.0 ;
				q = (ll) ceil( temp ) ;
			}
			x = abs( p * a + q * c ) ;
			y = abs( p * b + q * d ) ;
			take() ;
			if( d == 0 ) 
				q = 0 ;
			else{
				double temp = (double) ( -p * b ) / (double) d ;
				if( (p * b) % d == 0 ) 
					temp -= 1.0 ;
				q = (ll) floor( temp ) ;
			}
			x = abs( p * a + q * c ) ;
			y = abs( p * b + q * d ) ;
			take() ;
		}
		printf("%lld\n", ans);
	}
	return 0 ;
}
