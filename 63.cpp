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

int t, n, k, dp[55][55], vis[44], i, x;

int solve(int id, int b){
	if(id==2*n+1){
		if(b==0)
			return 1;
		return 0;
	}
	if(dp[id][b]!=-1)
		return dp[id][b];
	dp[id][b]=solve(id+1, b+1);
	if(!vis[id] && b)
		dp[id][b]+=solve(id+1, b-1);
	return dp[id][b];
}
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &k);
		for(i=1;i<44;++i)
			vis[i]=0;
		for(i=1;i<=k;++i)
			scanf("%d", &x), vis[x]=1;
		memset(dp, -1, sizeof dp);
		printf("%d\n", solve(1, 0));
	}
	return 0;
}
