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
 
template < typename X > X gcd( X a, X b ) { if( !b ) return a ; else return gcd(b, a%b) ; }
 
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll MOD = 1e9 + 7 ;
ll n, l, ans, m ;

ll mul(ll a, ll b, ll m ) {
	ll res = 0;
	while( b ) {
		if( b & 1 ) 
			res = ( res + a ) % m ;
		b >>= 1;
		a <<= 1;
		a %= m ;
	}
	return res ;
}
ll solve(ll a, ll b, ll m) {
	ll res = 1; 
	while( b ) {
		if( b & 1 ) 
			res = mul( res, a, m ) ;
		b >>= 1;
		a = mul( a, a, m );
	}
	return res ;
}

int main() {
	while(1) {
		scanf("%lld %lld", &n, &l);
		if( !n )
			break;
		m = MOD * ( n - 1 ) ;
		ll ans = solve( n, l + 1, m );
		ans = ( ans - n + m ) % m ;
		ans /= ( n - 1 ) ;
		printf("%lld\n", ans);
	}
	return 0;
}
