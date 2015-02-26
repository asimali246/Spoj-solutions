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



const int N = 2222;
const int B = 22 ;
const int M = 220000 ;
int n, b, p[N][B], i, j, C[B], ans;
int l, h, m ;
int e, f[M], c[M], Next[M], to[M], s, t, fin[N], temp[N] ;
int q[M], dist[N] ;

void add(int u, int v, int cap ) {
	to[e] = v, c[e] = cap, f[e] = 0, Next[e] = fin[u], fin[u] = e++ ;
	to[e] = u, c[e] = cap, f[e] = 0, Next[e] = fin[v], fin[v] = e++ ;
}

bool expath() {
	for( i = 1; i <= n + b + 2; ++i ) 
		dist[i] = -1 ;
	dist[s] = 0 ;
	int b, en, u, v ;
	b = en = 0 ;
	q[en++] = s ;
	while( b < en ) {
		u = q[b++] ;
		for( int i = fin[u] ; i >= 0 ; i = Next[i] ) {
			v = to[i] ;
			if( f[i] < c[i] && dist[v] == -1 ) {
				dist[v] = dist[u] + 1 ;
				q[en++] = v ;
			}
		}	
	} 
	return dist[t] != -1 ;
}

int dfs(int u, int fl ) {
	if( u == t ) 
		return fl ;
	int v ;
	for( int &top = temp[u] ; top >= 0 ; top = Next[top] ) {
		v = to[top] ;
		if( f[top] < c[top] && dist[v] == dist[u] + 1 ) {
			int df = dfs( v, min( fl, c[top] - f[top] ) ) ;
			if( df > 0 ) {
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
		for( i = 1; i <= n + b + 2; ++i ) 
			temp[i] = fin[i] ;
		while( true ) {
			int extra = dfs( s, INF ) ;
			if( extra ) 
				flow += extra ;
			else
				break ;
		}
	}
	return flow ;
}


bool possible(int r) {
	for( int i = 1; i <= b - r + 1; ++i ) {
		e = 0 ;
		s = 1 ;
		t = n + b + 2 ;
		memset( fin, -1, sizeof fin ) ;
		for( int cow = 1; cow <= n; ++cow ) {
			for( int barn = i; barn <= i + r - 1; ++barn ) {
				int P = p[cow][barn] ;
				add( cow + 1, n + P + 1, 1) ;
			}
		}
		for( j = 1; j <= b; ++j ) {
			add( n + j + 1, t, C[j] ) ;
		}
		for( j = 1; j <= n; ++j ) {
			add( s, j + 1, 1 ) ;
		}
		int flow = Dinic() ;
		if( flow == n ) 
			return true ;
	}
	return false ;
}


int main() {
	scanf("%d %d", &n, &b) ;
	for( i = 1; i <= n; ++i ) 
		for( j = 1; j <= b; ++j ) 
			scanf("%d", &p[i][j] ) ;
	for( i = 1; i <= b; ++i ) 
		scanf("%d", &C[i] ) ;
	l = 1, h = b ;
	while( l <= h ) {
		m = ( l + h ) >> 1 ;
		if( possible(m) ) 
			h = m - 1, ans = m ;
		else
			l = m + 1 ;
	}
	printf("%d\n", ans);
	return 0 ;
}
