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
 
#define ll unsigned long long int
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;

typedef pair<ll, ll> lli;
int t, i, a[111], l, flag, p;
lli dp[111][111];
char s[111], op[111];

lli solve(int l, int r) {
	if( l == r - 1 ) {
		if( op[l] == '+' )
			return lli(a[l] + a[r], a[l] + a[r]);
		return lli(a[l] * a[r], a[l] * a[r]);
	}
	if( l == r )
		return lli(a[l], a[r]);
	if( l > r )
		return lli(0, 0);
	if( dp[l][r].first != -1 )
		return dp[l][r];
	lli temp;
	temp.first = 0;
	temp.second = (ll)INF * INF;
	for( int j = l; j < r; ++j ) {
		lli a = solve(l, j);
		lli b = solve(j + 1, r);
		if(op[j] == '+') {
			temp.first = max(temp.first , a.first + b.first);
			temp.second = min(temp.second, a.second + b.second);
		}
		else {
			temp.first = max(temp.first, a.first * b.first);
			temp.second = min(temp.second , a.second * b.second);
		}
	}
	return dp[l][r] = temp;
}
int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%s", s);
		l = (int) strlen(s);
		flag = p = 1;
		for( i = 0; i < l ; i++ ) {
			if( flag )
				a[p] = s[i] - '0', flag = 0;
			else
				op[p++] = s[i], flag = 1;
		}
		op[p] = '+';
		memset(dp, -1, sizeof dp);
		lli temp = solve(1, p);
		printf("%llu %llu\n", temp.first, temp.second);
	}
	return 0;
}
