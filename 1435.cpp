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
int n, i, u, v, dp[N][2], vis[N];
vector<int> g[N];

int MVC(int u, int flag) {
	if(dp[u][flag] != -1)
		return dp[u][flag];
	if((int)g[u].size() == 1 && u != 1)
		return flag;
	vis[u] = 1;
	int ans = flag;
	if( !flag ) {
		for( int j = 0; j < (int) g[u].size(); ++j )
			if( !vis[g[u][j]] )
				ans += MVC(g[u][j], 1);
	}
	else
		for( int j = 0; j < (int) g[u].size(); ++j )
			if( !vis[g[u][j]] )
				ans += min( MVC(g[u][j], 0), MVC(g[u][j], 1) );
	vis[u] = 0;
	return dp[u][flag] = ans;
}

int main() {
	scanf("%d", &n);
	for( i = 1; i <= n; ++i )
		g[i].clear(), dp[i][0] = dp[i][1] = -1;
	for( i = 1; i < n; ++i ) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if( n == 1 )
		printf("1\n");
	else
		printf("%d\n", min( MVC(1, 0), MVC(1, 1) ));
	return 0;
}
