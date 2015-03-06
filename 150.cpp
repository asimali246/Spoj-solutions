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



const int N = 1e4 + 10 ;
int t, n, x, y, i, ans, sx[N], sy[N], smx[N], smy[N] ;
ii a[N], b[N];

int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%d", &n) ;
		for( i = 1; i <= n; ++i ) {
			scanf("%d %d", &x, &y) ;
			a[i].second = i ;
			b[i].second = i ;
			a[i].first = x ;
			b[i].first = y ;
		}
		sort( a + 1, a + n + 1 ) ;
		sort( b + 1, b + n + 1 ) ;
		for( i = 1; i <= n; ++i ) {
			smx[i] = smx[i - 1] + a[i].first ;
			smy[i] = smy[i - 1] + b[i].first ;
		}
		for( i = 1; i <= n; ++i ) {
			sx[ a[i].second ] = smx[n] - smx[i - 1] - (n - i + 1) * a[i].first ;
			sx[ a[i].second ] += (i - 1) * a[i].first - smx[i - 1] ;

			sy[ b[i].second ] = smy[n] - smy[i - 1] - (n - i + 1) * b[i].first ;
			sy[ b[i].second ] += (i - 1) * b[i].first - smy[i - 1] ;
		}
		ans = INF ;
		for( i = 1; i <= n; ++i )
			ans = min( ans , sx[i] + sy[i] ) ;
		printf("%d\n", ans); 
	}
	return 0 ;
}
