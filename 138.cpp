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
 
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 40100 * 2 ;
int tt, n, i, k, l, r, lazy[5 * N], a[N], ans, vis[N>>1] ;
map<int, int> mp;
pair<int, int> p[N>>1] ;

void propagate(int id, int l, int r) {
	if( lazy[l] <= lazy[id] ) 
		lazy[l] = lazy[id] ;
	if( lazy[r] <= lazy[id] ) 
		lazy[r] = lazy[id] ;
	lazy[id] = 0 ;
}

void update(int id, int l, int r, int x, int y, int v) {
	if( l == x && r == y ) {
		lazy[id] = v ;
		return ;
	}
	int m, lft, rgt ;
	m = (l + r) >> 1;
	lft = id << 1, rgt = lft | 1 ;
	propagate(id, lft, rgt) ;
	if( y <= m ) 
		update( lft, l, m, x, y, v );
	else
	if( x > m ) 
		update( rgt, m + 1, r, x, y, v );
	else
		update( lft, l, m, x, m, v ), update( rgt, m + 1, r, m + 1, y, v ) ;
}

int query(int id, int l, int r, int p) {
	if( l == r && l == p ) 
		return lazy[id] ;
	int m, lft, rgt ;
	m = (l + r) >> 1;
	lft = id << 1, rgt = lft | 1 ;
	propagate(id, lft, rgt) ;
	if( p <= m )
		return query(lft, l, m, p );
	else
		return query( rgt, m + 1, r, p );
}

int main() {
	scanf("%d", &tt) ;
	while( tt-- ) {
		scanf("%d", &n);
		mp.clear() ;
		k = 1;
		for( i = 1; i <= n; ++i ) {
			scanf("%d %d", &l, &r );
			p[i].first = l ;
			p[i].second = r ;
			a[k++] = l ;
			a[k++] = r ;
			vis[i] = 0 ;
		}
		memset(lazy, 0, sizeof lazy ) ;
		sort( a + 1, a + k );
		k = 1;
		for( i = 1; i <= (n << 1) ; ++i ) {
			if( mp.count( a[i] ) == 0 ) {
				mp[ a[i] ] = k++ ;
			}
		}
		--k ;
		for( i = 1; i <= n; ++i ) {
			l = p[i].first ;
			r = p[i].second ;
			l = mp[l] ;
			r = mp[r] ;
			update( 1, 1, k, l, r, i ) ;
		}
		ans = 0 ;
		for( i = 1; i <= k; ++i ) {
			l = query( 1, 1, k, i ) ;
			if( !vis[l] ) {
				vis[l] = 1;
				++ans ;
			}
		}
		printf("%d\n", ans);
	}
	return 0 ;
}
