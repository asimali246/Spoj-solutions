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
const int M = N * N ;
int t, n, x, y, V[N][N], pn[N], pm[N], ans, NIL, i, num, m, j;
int q[M], dist[M] ;
bool P[N][N], R[N], C[N] ;
vector<int> g[M] ;

bool BFS() {
	int b , en, v, u ;
	b = en = 0;
	for( i = 1; i <= n; ++i ) {
		if( pn[i] == NIL ) {
			dist[i] = 0;
			q[en++] = i ;
		}
		else
			dist[i] = INF ;
	}
	dist[NIL] = INF ;
	while( b < en ) {
		v = q[b++] ;
		if( dist[v] < dist[NIL] ) {
			for( int j = 0; j < (int) g[v].size(); ++j ) {
				u = g[v][j] ;
				if( dist[pm[u]] == INF ) {
					dist[ pm[u] ] = dist[v] + 1;
					q[en++] = pm[u] ;
				}
			}
		}		
	}
	return dist[NIL] != INF ;
}
bool DFS(int v) {
	int u ;
	if( v != NIL ) {
		for( int j = 0; j < (int) g[v].size(); ++j ) {
			u = g[v][j] ;
			if( dist[ pm[u] ] == dist[v] + 1 ) {
				if( DFS( pm[u] ) ) {
					pm[u] = v ;
					pn[v] = u ;
					return true ;
				}
			}
		}
		dist[v] = INF ;
		return false; 
	}
	return true ;
}
int Hopcroft_Karp() {
	for( i = 1; i <= n + m + 2; ++i )
		pn[i] = pm[i] = NIL ;
	while( BFS() ) {
		for(i = 1; i <= n; ++i ) {
			if( pn[i] == NIL ) {
				if( DFS(i) ) {
					++ans;
				}
			}
		}
	}
	return ans;
}

int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%d", &n) ;
		memset( P, false, sizeof P ) ;
		memset( R, false, sizeof R ) ;
		memset( C, false, sizeof C ) ;
		while( n-- ) {
			scanf("%d %d", &x, &y) ;
			P[x][y] = true ;
			R[x] = true ;
			C[y] = true ;
		}
		memset( V, -1, sizeof V ) ;
		num = 1 ;
		for( j = 0; j < 120; ++j ) {
			if( C[j] ) {
				for( i = 0; i < 120; ++i ) 
					if( P[i][j] ) 
						V[i][j] = num ;
				++num ;
			}
		}
		n = num - 1 ;
		for( i = 0; i < M; ++i ) 
			g[i].clear() ;
		for( i = 0; i < 120; ++i ) {
			if( R[i] ) {
				for( j = 0; j < 120; ++j ) 
					if( P[i][j] ) 
						g[V[i][j]].push_back( num ) ;
				++num ;
			}
		}
		--num ;
		m = num - n ;
		ans = 0 ;
		printf("%d\n", Hopcroft_Karp() );
	}
	return 0 ;
}
