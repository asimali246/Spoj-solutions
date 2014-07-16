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

int t, n, dp[2020][2020], i, j, x, m;
int a[2020], b[2020], ans;

int main(){
	scanf("%d", &t);
	while(t--){
		i=0;
		ans=-INF;
		while(1){
			scanf("%d", &x);
			if(!x)
				break;
			b[++i]=x;
		}
		n=i;
		while(1){
			i=0;
			while(1){
				scanf("%d", &x);
				if(!x)
					break;
				a[++i]=x;
			}
			m=i;
			if(i==0)
				break;
			for(i=1;i<=n;++i)
				dp[0][i]=0;
			for(i=1;i<=m;++i)
				dp[i][0]=0;
			dp[0][0]=0;
			for(i=1;i<=m;++i){
				for(j=1;j<=n;++j){
					dp[i][j]=dp[i-1][j-1]+((a[i]==b[j])?1:0);
					dp[i][j]=max(dp[i-1][j], dp[i][j]);
					dp[i][j]=max(dp[i][j-1], dp[i][j]);
				}
			}
			ans=max(ans, dp[m][n]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
