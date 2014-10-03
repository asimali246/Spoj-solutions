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
#define INF 1000000000 + 100
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 5050;
const int M = 61000;
int n, m, i, s, t, fin[N], next[M], temp[N], c[M], to[M], e, a, b, cap, f[M]; 
int q[M], dist[N];

void add(int u, int v, int cap) {
	to[e] = v, c[e] = cap, f[e] = 0, next[e] = fin[u], fin[u] = e++;
	to[e] = u, c[e] = cap, f[e] = 0, next[e] = fin[v], fin[v] = e++;
}

bool expath() {
	memset( dist, -1, sizeof dist ) ;
	dist[s] = 0;
	int b, en, u, v ; 
	b = 0 , en = 0;
	q[en++] = s ; 
	while( b < en ) {
		u = q[b++];
		for( i = fin[u] ; i >= 0 ; i = next[i] ) {
			v = to[i] ; 
			if( f[i] < c[i] && dist[v] == -1 ) {
				dist[v] = dist[u] + 1;
				q[en++] = v;
			}
		}
	}
	return dist[t] != -1;
}

int dfs(int u, int fl) {
	if( u == t )
		return fl;
	int v;
	for( int &top = temp[u] ; top >= 0 ; top = next[top] ) {
		v = to[top] ;
		if( f[top] < c[top] && dist[v] == dist[u] + 1 ) {
			int df = dfs( v, min( fl, c[top] - f[top] ) );
			if( df > 0 ) {
				f[top] += df;
				f[top ^ 1] -= df;
				return df;
			}
		}
	}	
	return 0;
}


ll Dinic() {
	ll flow = 0;
	while( expath() ) {
		for( i = 1; i <= n; ++i )
			temp[i] = fin[i];
		while( true ) {
			int extra = dfs( s, INF );
			if( extra )
				flow += (ll) extra;
			else
				break;
		}
	}
	return flow;
}

int main() {
	scanf("%d %d", &n, &m);
	s = 1;
	t = n;
	memset(fin, -1, sizeof fin) ;
	while( m-- ) {
		scanf("%d %d %d", &a, &b, &cap);
		if( a != b )
			add(a, b, cap);
	}
	printf("%lld\n", Dinic() );
	return 0 ;
}
