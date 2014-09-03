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

int i, dp[33][250], cs = 1, l;
char s[33];

int solve(int pos, int p) {
	if( pos >= l )
		return 1;
	if( dp[pos][p] != -1 )
		return dp[pos][p];
	int ans = 0, sum = 0;
	for( int x = pos; x < l; ++x ) {
		sum += s[x] - '0';
		if( sum >= p )
			ans += solve(x + 1, sum);
	}
	return dp[pos][p] = ans;
}
int main() {
	while( 1 ) {
		scanf("%s", s);
		if( s[0] == 'b')
			break;
		l = (int) strlen( s );
		memset(dp, -1, sizeof dp);
		printf("%d. %d\n", cs++, solve(0, 0));
	}
	return 0;
}
