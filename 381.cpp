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

int n, m, a, b, c, i, j, k;
double dp[111][111];

int main(){
	while(1){
		scanf("%d", &n);
		if(!n)
			break;
		scanf("%d", &m);
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
				dp[i][j]=((i==j)?1.0:0.0);
		while(m--)
			scanf("%d %d %d", &a, &b, &c), dp[a][b]=dp[b][a]=(double)c/100.0;
		for(k=1;k<=n;++k)
			for(i=1;i<=n;++i)
				for(j=1;j<=n;++j)
					dp[i][j]=max(dp[i][j], dp[i][k]*dp[k][j]);
		printf("%.6lf percent\n", dp[1][n]*100.0);
	}
	return 0;
}
