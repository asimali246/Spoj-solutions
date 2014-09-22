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

const int N = 111;
int T, m, n, i, j, dist[N * N], s, d, x, y, t, a[N][N], node = 1, k;
priority_queue<ii, vector<ii>, greater<ii> > pq;
vector<ii> g[N*N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


bool valid(int x, int y) {
	if( x < 1 || x > m || y < 1 || y > n )
		return false;
	return true;
}

int main() {
	scanf("%d", &T);
	while( T-- ) {
		pq = priority_queue<ii, vector<ii>, greater<ii> >();
		
		scanf("%d %d", &m, &n);

		for( i = 1; i <= m * n; ++i )
			g[i].clear(), dist[i] = INF;

		for( i = 1; i <= m; ++i )
			for( j = 1; j <= n; ++j )
				scanf("%d", &a[i][j]);

		node = 1;
		scanf("%d %d %d", &x, &y, &t);
		
		for( i = 1; i <= m; ++i ) {
			for( j = 1; j <= n; ++j ) {
				if( i == x && j == y )
					d = node;
				for( k = 0; k < 4; ++k )
					if( valid(i + dx[k], j + dy[k]) ) {
						g[node].push_back( ii( a[i + dx[k]][j + dy[k]], (node + ( (k == 0) ? -n : ( (k == 1) ? 1 : ( ( k == 2) ? n : -1 ) ) ) ) ) );
					} 
				node++;
			}
		}
		
		--node;
		
		dist[1] = a[1][1];
		pq.push(ii(a[1][1], 1));
		
		while( !pq.empty() ) {
			ii v = pq.top(); pq.pop();
			if( dist[v.second] == v.first ) 
				for( j = 0; j < (int) g[v.second].size(); ++j ) {
					if( dist[ g[v.second][j].second ] > dist[v.second] + g[v.second][j].first ) {
						dist[ g[v.second][j].second ] = dist[v.second] + g[v.second][j].first ;
						pq.push( ii ( dist[ g[v.second][j].second ] , g[v.second][j].second ) );
					}
				}
		}
		
		if( dist[d] > t )
			puts("NO");
		else
			printf("YES\n%d\n", t - dist[d]);

	}
	return 0;
}
