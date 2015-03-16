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



const int N = 55 ;
const int M = 55 * 55 ;
int t, r, c, i, j, ans, V[N][N], num, pn[M], pm[M], NIL, n;
char s[N][N] ;
int q[M], dist[M] ;
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
	for( i = 1; i <= n; ++i )
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
		scanf("%d %d", &r, &c) ;
		getchar() ;
		for( i = 1; i <= r; ++i ) {
			for( j = 1; j <= c; ++j ) 
				s[i][j] = getchar() ;
			getchar() ;
		}
		num = 0 ;
		for( i = 1; i <= r * c; ++i ) 
			g[i].clear() ;
		for( i = 1; i <= c; ++i ) {
			for( j = 1; j <= r; ++j ) {
				if( s[j][i] == '*' )
					num++ ;
				while( j <= r && s[j][i] == '*' ) {
					V[j][i] = num ;
					++j ;
				}
			}
		}
		for( i = 1; i <= r; ++i ) {
			for( j = 1; j <= c; ++j ) {
				if( s[i][j] == '*' )
					num++ ;
				while( j <= c && s[i][j] == '*' ) {
					g[num].push_back( V[i][j] ) ;
					g[ V[i][j] ].push_back( num ) ;
					++j ;
				}
			}
		}
		n = num ;
		ans = 0 ;
		printf("%d\n", Hopcroft_Karp() / 2 );
	}
	return 0 ;
}
