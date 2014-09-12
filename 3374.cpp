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

int t, n, i, cs = 1, num, vis[555];
map<int, string> rev;
map<string, int> mp;
vector<int> g[555];
char a[101000], b[101000];

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		getchar();
		num = 1;
		mp.clear(), rev.clear();
		for( i = 1; i <= n; ++i )
			g[i].clear();
		memset(vis, 0, sizeof vis);
		for( i = 1; i < n; ++i ) {
			scanf("%s %s", a, b);
			getchar();
			if(mp.count(a) == 0 )
				mp[a] = num++, rev[num - 1] = a;
			if(mp.count(b) == 0 )
				mp[b] = num++, rev[num - 1] = b;
			g[mp[a]].push_back(mp[b]);
			vis[mp[b]] = 1;
		}
		printf("Scenario #%d:\n", cs++);
		for( i = 1; i <= n; ++i )
			if(!vis[i]) {
				while(1) {
					printf("%s\n", rev[i].c_str());
					if(g[i].size() == 0 )
						break;
					i = g[i][0];
				}
				break;
			}
		putchar('\n');
	}
	return 0;
}
