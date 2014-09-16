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

const ll MOD = 1e9 + 7;
int t, n;

ll solve(int p) {
	ll res = 1;
	ll b = 2;
	while( p ) {
		if( p & 1 )
			res = (res * b) % MOD;
		b = ( b * b ) % MOD;
		p >>= 1;
	}
	return res;
}
int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		printf("%lld\n", solve(n-1));
	}
	return 0;
}
