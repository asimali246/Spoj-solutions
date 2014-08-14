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
#include <stdint.h>
#include <unistd.h>
 
 using namespace std;
 
#define ll long long int
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1<<17;
int t, n, m, u, v, i, dist[N], s, d, c;
vector<ii> g[N];
priority_queue<ii, vector<ii>, greater<ii> > pq;

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d %d %d %d", &n, &m, &s, &d);
		for( i = 1; i <= n; ++i )
			g[i].clear(), dist[i] = INF;
		pq = priority_queue<ii, vector<ii>, greater<ii> >();
		while( m-- ) {
			scanf("%d %d %d", &u, &v, &c);
			g[u].push_back(ii(v, c));
			g[v].push_back(ii(u, c));
		}
		pq.push(ii(0, s));
		dist[s] = 0;
		while(!pq.empty()) {
			ii temp = pq.top(); pq.pop();
			u = temp.second;
			c = temp.first;
			if( dist[u] == c )
				for( i = 0; i < (int) g[u].size(); ++i )
					if( dist[u] + g[u][i].second < dist[g[u][i].first] ){
						dist[g[u][i].first] = dist[u] + g[u][i].second;
						pq.push( ii (dist[g[u][i].first], g[u][i].first));
					}
		}
		if( dist[d] == INF )
			printf("NONE\n");
		else
			printf("%d\n", dist[d]);
	}
	return 0;
}
