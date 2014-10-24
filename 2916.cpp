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
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 10010 ;

struct Node {
	int s, bl, br, bs ;
}t[5 * N];

int tt, n, a[N], i, q, xo, yo, xt, yt, l, m, r, sum[N], ans;

Node combine( Node a, Node b ) {
	Node ans ;
	ans.s = a.s + b.s ;
	ans.bl = max( a.bl, a.s + b.bl ) ;
	ans.br = max( b.br, b.s + a.br ) ;
	ans.bs = max( a.br + b.bl , max( a.bl, b.br ) ) ;
	ans.bs = max( ans.bs, max( a.bs, b.bs ) ) ;
	return ans ;
}

void build(int id, int l, int r) {
	if( l == r ) {
		t[id].s = t[id].bl = t[id].br = t[id].bs = a[l];
		return;
	}
	int m, lft, rgt;
	m = ( l + r ) >> 1;
	lft = id << 1, rgt = lft | 1;
	build( lft, l, m );
	build( rgt, m + 1, r );
	t[id] = combine(t[lft], t[rgt]) ;
}

Node query(int id, int l, int r, int x, int y) {
	if( l == x && r == y ) {
		return t[id];
	}
	int m, lft, rgt ;
	m = ( l + r ) >> 1;
	lft = id << 1 , rgt = lft | 1;
	if( y <= m ) 
		return query(lft, l, m, x, y );
	else
	if( x > m ) 
		return query( rgt, m + 1, r, x, y ) ;
	else {
		Node a = query(lft, l, m, x, m );
		Node b = query(rgt, m + 1, r, m + 1, y ) ;
		return combine(a, b );
	}
}

int main() {
	scanf("%d", &tt);
	while( tt-- ) {
		scanf("%d", &n);
		for( i = 1; i <= n; ++i )
			scanf("%d", &a[i] ), sum[i] = a[i] + sum[i-1];
		build(1, 1, n);
		scanf("%d", &q) ;
		while( q-- ) {
			scanf("%d %d %d %d", &xo, &yo, &xt, &yt );
			l = query(1, 1, n, xo, min( yo, xt ) ).br ;
			if( xt > yo ) {
				m = sum[xt - 1] - sum[yo] ;
				r = query( 1, 1, n, xt, yt).bl ;
				ans = l + m + r ;
			}
			else {
				l = query( 1, 1, n, xo, yo).br ;
				m = xt ;
				xt = yo + 1;
				if( xt > n || xt > yt )
					r = 0;
				else
					r = query( 1, 1, n, xt, yt ).bl ;
				ans = max( l, l + r ) ;
				xt = m ;
				r = query( 1, 1, n, xt, yt ).bl;
				m = yo ;
				yo = xt - 1;
				if( yo == 0 || yo < xo)
					l = 0;
				else
					l = query( 1, 1, n, xo, yo ).br ;
				yo = m ;
				ans = max( ans, max( r , r + l ) ) ;
				m = query( 1, 1, n, xt, yo ).bs;
				ans = max( ans, m ) ;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
