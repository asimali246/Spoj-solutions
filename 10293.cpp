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

int t, i, l;
char s[55];
ll dp[55];

ll solve(int p) {
	if( p >= l )
		return 1;
	if(dp[p] != -1 )
		return dp[p];
	ll ans = 0;
	if( p + 1 < l && s[p] == s[p + 1])
		ans = solve(p + 1);
	ans += solve(p + 1);
	return dp[p] = ans;
}
int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%s", s);
		l = (int)strlen(s);
		memset(dp, -1, sizeof dp);
		printf("%lld\n", solve(0));
	}
	return 0;
}
