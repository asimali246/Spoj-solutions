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


const int N = 555 ;
const int M = 5555 ;
int T, n, m, i, j, u, g[N][N] ;
char S[11111] ;
int e, Next[M], f[M], c[M], fin[N], to[M] ;
int s, t, ans, temp[N], q[M * 5], dist[N] ;

void add(int u, int v, int cap) {
	to[e] = v, f[e] = 0, c[e] = cap, Next[e] = fin[u], fin[u] = e++ ;
	to[e] = u, f[e] = 0, c[e] = 0, Next[e] = fin[v], fin[v] = e++ ;
}

bool expath() {
	int b , en ;
	b = en = 0 ;
	q[en++] = s ;
	for( i = 1; i <= n * 2 + 1; ++i ) 
		dist[i] = -1 ;
	dist[s] = 0 ;
	while( b < en ) {
		int u = q[b++] ;
		for( int j = fin[u]; j >= 0; j = Next[j] ) {
			int v = to[j] ;
			if( f[j] < c[j] && dist[v] == -1 ) {
				dist[v] = dist[u] + 1 ;
				q[en++] = v ;
			}
		}
	}
	return dist[t] != -1 ;
}

int dfs(int u, int fl) {
	if( u == t ) 
		return fl ;
	for( int &top = temp[u]; top >= 0; top = Next[top] ) {
		int v = to[top] ;
		if( f[top] < c[top] && dist[v] == dist[u] + 1 ) {
			int df = dfs(v, min(fl, c[top] - f[top]) ) ;
			if( df ) {
				f[top] += df ;
				f[top ^ 1] -= df ;
				return df ;
			}
		}
	}
	return 0 ;
}

int Dinic() {
	int flow = 0 ;
	while( expath() ) {
		for( i = 1; i <= n * 2 + 10 ; ++i ) 
			temp[i] = fin[i] ;
		while( true ) {
			int f = dfs(s, INF ) ;
			if( f ) 
				flow += f ;
			else
				break ;
		}
	}
	return flow ;
}

int main() {
	scanf("%d", &T) ;
	while( T-- ) {
		scanf("%d %d", &n, &m) ;
		for( i = 1; i <= n; ++i ) 
			for( j = 1; j <= n; ++j ) 
				g[i][j] = 0 ;
		if( m == 0 ) {
			ans = 0 ;
			if( n == 1 ) 
				ans = 1 ;
			printf("%d\n", ans);
			continue ;
		}
		while( m-- ) {
			scanf("%s", S) ;
			int v ;
			sscanf(S, "(%d,%d)", &u, &v) ;
			++u ;
			++v ;
			g[u][v] = 1 ;
			g[v][u] = 1 ;
		}
		e = 0 ;
		s = 1 ;
		ans = INF ;
		for( int x = 2; x <= n; ++x ) {
			e = 0 ;
			for( i = 1; i <= n * 2; ++i ) 
				fin[i] = -1 ;
			for( j = 1; j <= n; ++j ) 
				add( 2 * j - 1, 2 * j , 1 ) ;
			for( i = 1; i <= n; ++i ) 
				for( j = 1; j <= n; ++j ) 
					if( g[i][j] ) {
						add( 2 * i , 2 * j - 1, 1 ) ;
					}
			s = 2 ;
			t = 2 * x - 1 ;
			ans = min( ans, Dinic() ) ;
		}
		if( n - ans == 1 ) 
			++ans ;
		printf("%d\n", ans);
	}
	return 0 ;
}
