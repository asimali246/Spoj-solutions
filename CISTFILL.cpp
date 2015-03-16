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



const int N = 50100 ;
ll t, n, b, h, w, d, i, v, pos, T, ph;
pair<int, ii> p[N*2] ;
double ans ;

int main() {
	scanf("%lld", &t) ;
	while( t-- ) {
		scanf("%lld", &n) ;
		pos = 1 ;
		for( i = 1; i <= n; ++i ) {
			scanf("%lld %lld %lld %lld", &b, &h, &w, &d) ;
			p[pos].first = b ;
			p[pos].second.first = 0 ;
			p[pos].second.second = w * d ;
			++pos ;
			p[pos].first = b + h ;
			p[pos].second.first = 1 ;
			p[pos].second.second = w * d ;
			++pos ;
		}
		--pos ;
		sort( p + 1, p + pos + 1 ) ;
		ans = (double) INF ;
		ph = T = 0 ;
		scanf("%lld", &v) ;
		for( i = 1; i <= pos; ++i ) {
			pair<int, ii> temp = p[i] ;
			h = temp.first ;
			b = temp.second.first ;
			w = temp.second.second ;
			if( b == 0 ) {
				int H = h - ph ;
				if( T * H <= v ) {
					v -= T * H ;
					T += w ;
					ph = h ;
				} else {
					ans = ph + (double) v / (double) T ;
					break ;
				}
			}
			else {
				int H = h - ph ;
				if( T * H <= v ) {
					v -= T * H ;
					T -= w ;
					ph = h ;
				} else {
					ans = ph + (double) v / (double) T ;
				}
			}
			if( v == 0 ) 
				break ;
		}
		if( v == 0 ) 
			ans = (double) ph ;
		if( ans == (double) INF )
			puts( "OVERFLOW" ) ;
		else
			printf("%.2lf\n", ans);
	}
	return 0 ;
}
