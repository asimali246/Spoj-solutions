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

const int N = 51000;
int t, n, i, a, b, c, vis[N], s, mx, dist[N];
vector<ii> g[N];

void dfs(int u) {
	vis[u] = 1;
	for(int j = 0; j < (int) g[u].size(); ++j ) {
		ii v = g[u][j];
		if(!vis[v.first]) {
			dist[v.first] = dist[u] + v.second;
			if( mx < dist[v.first] )
				mx = dist[v.first], s = v.first;
			dfs(v.first);
		}
	}
}
int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		for( i = 1; i <= n; ++i )
			g[i].clear(), vis[i] = 0;
		for( i = 1; i < n; ++i ) {
			scanf("%d %d %d", &a, &b, &c);
			g[a].push_back(ii(b, c));
			g[b].push_back(ii(a, c));
		}
		mx = -INF;
		dist[1] = 0;
		dfs(1);
		for( i = 1; i <= n; ++i )
			vis[i] = 0;
		mx = -INF;
		dist[s] = 0;
		dfs(s);
		printf("%d\n", mx);
	}
	return 0;
}
