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

ll a, b;

ll sum(ll x) {
	if( x/10 == 0 )
		return x*(x+1)/2;
	ll n = x;
	ll i = 0;
	while( n/10 != 0 )
		++i, n/=10;
	ll p = (ll) pow( 10, i );
	return n * (x%p + 1) + ( n*(n-1)*p / 2 ) + (45*n*i*p / 10) + sum(x % p);
}
int main() {
	while( 1 ) {
		scanf("%lld %lld", &a, &b);
		if( a == -1 )
			break;
		printf("%lld\n", sum(b) - sum( a - 1 ) );
	}
	return 0;
}
