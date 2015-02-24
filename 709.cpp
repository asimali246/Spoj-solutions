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



const int N = 1e5 + 10 ;
int t, T[N], i, ans, n, x, y;
pair<int, ii> a[N] ;

int query(int v) {
	int ans = INF ;
	while( v > 0 ) {
		ans = min( ans, T[v] ) ;
		v -= ( v & (-v) ) ;
	}
	return ans ;
}
void update(int v, int mn) {
	while( v <= n ) {
		T[v] = min( T[v], mn ) ;
		v += ( v & (-v) ) ;
	}
}
int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%d", &n ) ;
		for( i = 1; i <= n; ++i ) {
			scanf("%d %d %d", &a[i].first, &a[i].second.first, &a[i].second.second ) ;
			T[i] = INF ;
		}
		sort( a + 1, a + n + 1 ) ;
		ans = 0 ;
		for( i = 1; i <= n; ++i ) {
			x = a[i].second.first ;
			y = a[i].second.second ;
			if( query( x ) > y ) {
				ans++ ;
				update( x, y ) ;
			}
		}
		printf("%d\n", ans);
	}
	return 0 ;
}
