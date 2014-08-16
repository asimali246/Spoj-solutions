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
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1010;
int dp[N][N][2], n, a[N], i, cs = 1, sum, ans;

int solve(int l, int r, int c) {
	if( l > r )
		return 0;
	if( dp[l][r][c] != -1 )
		return dp[l][r][c];
	int ans;
	if(c) {
		ans = max( a[l] + solve(l + 1, r, 0), a[r] + solve(l, r-1, 0));
	}
	else {
		if( a[l] >= a[r] )
			ans = solve( l+1, r, 1);
		else
			ans = solve( l, r-1, 1);
	}
	return dp[l][r][c] = ans;
}

int main() {
	while(1){
		scanf("%d", &n);
		if(!n)
			break;
		sum = 0;
		for( i = 1; i <= n; ++i )
			scanf("%d", &a[i]), sum += a[i];
		memset(dp, -1, sizeof dp);
		ans = solve(1, n, 1);
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n", cs++, 2 * ans - sum);
	}
	return 0;
}
