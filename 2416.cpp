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

const int N = 1<<17;
const int MOD = 1e9+7;
int t, n, dp[N], sum[N], last[100], i;
char s[N];

int main() {
	scanf("%d", &t);
	getchar();
	while( t-- ) {
		scanf("%s", s);
		n = (int) strlen(s);
		dp[0] = sum[0] = 1;
		for( i = 65; i <= 90; ++i )
			last[i] = -1;
		for( i = 1; i <= n; ++i ) {
			dp[i] = sum[i - 1] - ((last[s[i - 1]] != -1) ? sum[last[s[i - 1]] - 1]: 0);
			dp[i] = (dp[i] + MOD) % MOD;
			sum[i] = sum[i - 1] + dp[i];
			sum[i] %= MOD;
			last[s[i - 1]] = i;
		}
		printf("%d\n", sum[n]);
	}
	return 0;
}
