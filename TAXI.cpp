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


const int N = 1000 ;
const int M = 2 * (int) 1e6 + 10000 ;
int T, p, t, c, i, j, S;
ii P[N], Tx[N] ;

int e, to[M], f[M], C[M], Next[M], fin[N], temp[N] ;
int dist[N], q[M * 10] ;

int Time() {
	int dist = abs( Tx[i].first - P[j].first) + abs( Tx[i].second - P[j].second ) ;
	return dist ;
}

void add(int u, int v, int cap) {
	to[e] = v, f[e] = 0, C[e] = cap, Next[e] = fin[u], fin[u] = e++ ;
	to[e] = u, f[e] = 0, C[e] = 0, Next[e] = fin[v], fin[v] = e++ ;
}

bool BFS() {
	int b, en, u, v ;
	b = en = 0 ;
	for( i = 1; i <= p + t + 2; ++i ) 
		dist[i] = -1 ;	
	dist[1] = 0 ;
	q[en++] = 1 ;
	while( b < en ) {
		u = q[b++] ;
		for( j = fin[u]; j >= 0 ; j = Next[j] ) {
			v = to[j] ;
			if( f[j] < C[j] && dist[v] == -1 ) {
				dist[v] = dist[u] + 1 ;
				q[en++] = v ;
			}
		}
	}
	return dist[p + t + 2] != -1 ;
}
int DFS(int u, int fl) {
	if( u == p + t + 2 ) 
		return fl ;
	for( int &top = temp[u]; top >= 0; top = Next[top] ) {
		int v = to[top] ;
		if( f[top] < C[top] && dist[v] == dist[u] + 1 ) {
			int df = DFS( v, min( C[top] - f[top], fl ) ) ;
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
	while( BFS() ) {
		for( i = 1; i < N; ++i ) 
			temp[i] = fin[i] ;
		while( true ) {
			int fl = DFS( 1, INF ) ;
			if( fl ) 
				flow += fl ;
			else 
				break ;
		}
	}
	return flow ;
}
int main() {
	scanf("%d", &T) ;
	while( T-- ) {
		scanf("%d %d %d %d", &p, &t, &S, &c) ;
		for( i = 1; i <= p; ++i ) 
			scanf("%d %d", &P[i].first, &P[i].second) ;
		for( i = 1; i <= t; ++i ) 
			scanf("%d %d", &Tx[i].first, &Tx[i].second) ;
		e = 0 ;
		for( i = 1; i <= p + t + 2; ++i ) 
			fin[i] = -1 ;
		for( i = 1; i <= t; ++i ) {
			for( j = 1; j <= p; ++j ) {
				if( Time() <= (S * c) / 200 ) {
					add( i + 1, j + t + 1, 1) ;
				}
			}
		}
		for( i = 1; i <= t; ++i ) 
			add( 1, i + 1, 1 ) ;
		for( i = 1; i <= p; ++i ) 
			add( i + t + 1, t + p + 2, 1 ) ;
		printf("%d\n", Dinic() ) ;
	}
	return 0 ;
}
