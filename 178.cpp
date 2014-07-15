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

int t, n, g[222][222], i, j, k;
vector<ii> ans;
bool flag, space=false;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
				scanf("%d", &g[i][j]);
		ans.clear();
		for(i=1;i<=n;++i)
			for(j=i+1;j<=n;++j){
				if(i==j)
					continue;
				flag=true;
				for(k=1;k<=n;++k)
					if(k!=i && k!=j && g[i][k]+g[k][j]==g[i][j])
						flag=false;
				if(flag)
					ans.push_back(ii(i, j));
			}
		if(space)
			putchar('\n');
		space=true;
		for(i=0;i<ans.size();++i)
			printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}
