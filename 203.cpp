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

const int N = 222;
int t, n, m, v, res[N][N], mf, f, i, p[N], j;
vector<int> g[N];
bitset<N> bs;
queue<int> q;

void augment(int v, int minCost) {
	if( v == 1 ) {
		f = minCost;
		return;		
	}
	if(p[v] != -1) {
		augment(p[v], min(minCost, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		for( i = 1; i <= n; ++i )
			g[i].clear();
		for(i = 1; i <= n; ++i )
			for( j = 1; j <= n; ++j )
				res[i][j] = 0;
		for( i = 1; i < n; ++i ) {
			scanf("%d", &m);
			while( m-- ) {
				scanf("%d", &v);
				g[i].push_back(v);
				g[v].push_back(i);
				res[i][v] = INF;
				if( i == 1 )
					res[i][v] = 1;
				if(v == n)
					res[i][v] = 1;
			}
		}
		mf = 0;
		while(1) {
			q = queue<int>();
			f = 0;
			for( i = 1; i <= n; ++i )
				p[i] = -1;
			bs.reset();
			q.push(1);
			bs[1] = 1;
			while( !q.empty() ) {
				int u = q.front(); q.pop();
				if(u == n)
					break;
				for(j = 0; j < (int)g[u].size(); ++j ) {
					v = g[u][j];
					if(res[u][v] && !bs[v]) {
						bs[v] = 1;
						p[v] = u;
						q.push(v);
					}
				}
			}
			augment(n, INF);
			if( f == 0 )
				break;
			mf += f;
		}
		printf("%d\n", mf);
	}
	return 0;
}
