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

const ll MOD = 1e9;
struct Matrix {
	ll a[15][15];
}T;

int t, k, n, b[15], c[15], i, j, p;
ll ans;

Matrix multiply(Matrix a, Matrix b) {
	Matrix c;
	for( i = 1; i <= k; ++i ) {
		for( j = 1; j <= k; ++j ) {
			c.a[i][j] = 0;
			for( p = 1; p <= k; ++p )
				c.a[i][j] += (a.a[i][p] * b.a[p][j]) % MOD, c.a[i][j] %= MOD;
		}
	}
	return c;
}

Matrix solve(int p) {
	Matrix res;
	for( i = 1; i <= k; ++i )
		for( j = 1; j <= k; ++j )
			res.a[i][j] = ( (i == j) ? 1 : 0 );
	while(p) {
		if(p & 1) 
			res = multiply(res, T);
		T = multiply(T, T);
		p >>= 1;
	}
	return res;
}

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &k);
		for( i = 1; i <= k; ++i )
			scanf("%d", &b[i]);
		for( i = 1; i <= k; ++i )
			scanf("%d", &c[i]);
		scanf("%d", &n);
		for( i = 1; i < k; ++i ) {
			for( j = 1; j <= k; ++j )
				T.a[i][j] = 0;
			T.a[i][i+1] = 1;
		}	
		for(i = 1; i <= k; ++i )
			T.a[k][i] = (ll)c[k - i + 1];
		Matrix res = solve(n - 1);
		ans = 0;
		for( i = 1; i <= k; ++i )
			ans = (ll)(ans + res.a[1][i] * b[i]) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
