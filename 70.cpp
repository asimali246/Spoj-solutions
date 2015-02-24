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


const int N = 1111 ;
int t, n, m, i, j, G[N][N], u, v, r, ans, pv[N], de[N];
pair<int, ii> e[N * 10];
vector<int> g[N] ;
bool possible ;
int vis[N] ;

int Parent(int x) {
	if( pv[x] == x )
		return x ;
	else
		return pv[x] = Parent( pv[x] ) ;
}

bool sameSet(int u, int v) {
	return Parent(u) == Parent(v) ;
}

void Union(int u, int v) {
	if( !sameSet(u, v) ) {
		pv[v] = pv[u] ;
	}
}

void dfs(int u) {
	vis[u] = 1 ;
	for( int j = 0; j < (int) g[u].size(); ++j ) {
		int v = g[u][j] ;
		if( vis[v] == 1 ) {
			possible = false ;
			return;
		}
		if( vis[v] == 0 ) 
			dfs( v ) ;
		if( !possible ) 
			return ;
	}
	vis[u] = 2 ;
}

void depth(int u) {
	de[u] = 0 ;
	for( int j = 0; j < (int) g[u].size(); ++j ) {
		int v = g[u][j] ;
		if( de[v] == -1 ) 
			depth( v ) ;
		de[u] = max( de[u], 1 + de[v] ) ;
	}
}


int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%d %d", &n, &m ) ;
		for( i = 1; i <= m; ++i ) {
			scanf("%d %d %d", &u, &v, &r ) ;
			e[i].first = r ;
			e[i].second.first = u ;
			e[i].second.second = v ;
		}
		for( i = 1; i <= n; ++i ) 
			for( j = 1; j <= n; ++j ) 
				G[i][j] = 0 ;
		for( i = 1; i <= n; ++i )  {
			g[i].clear() ;
			pv[i] = i ;
			vis[i] = 0 ;
			de[i] = -1 ;
		}
		ans = -INF ;
		possible = true ;
		for( i = 1; i <= m; ++i ) {
			u = e[i].second.first ;
			v = e[i].second.second ;
			r = e[i].first ;
			if( r == 0 ) {
				u = Parent( u ) ;
				v = Parent( v ) ;
				Union( u, v ) ;
			}
		}
		for( i = 1; i <= m; ++i ) {
			u = e[i].second.first ;
			v = e[i].second.second ;
			r = e[i].first ;
			u = Parent( u ) ;
			v = Parent( v ) ;
			if( r == 0 ) 
				continue ;
			if( r == -1 ) 
				swap( u, v ) ;
			if( G[v][u] ) {
				possible = false ;
				break ;
			}
			if( !G[u][v] ) {
				G[u][v] = 1 ;
				g[u].push_back( v ) ;
			}
		}
		for( i = 1; i <= n; ++i ) {
			u = Parent( pv[i] ) ;
			if( !vis[ u ] ) {
				dfs( u ) ;
				if( !possible ) 
					break ;
			}
		}

		if( !possible ) {
			puts("NO") ;
			continue ;
		}

		for( i = 1; i <= n; ++i ) {
			u = Parent( pv[i] ) ;
			if( de[u] == -1 ) {
				depth(u) ;
			}
			ans = max( ans, de[u] ) ;
		}

		if( !possible ) 
			puts("NO") ;
		else
			printf("%d\n", ans);

	}
	return 0 ;
}
