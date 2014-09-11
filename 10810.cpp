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

const ll N = 1000010;
ll tt, n, i, v;
ll ans, t[N];

void update(ll v) {
	ll p = v;
	while( p < N ) {
		t[p] += (ll)v;
		p += (p & (-p)); 
	}
}

ll query(ll v) {
	ll sum = 0;
	while( v > 0 ) {
		sum += t[v];
		v -= (v & (-v));
	}
	return sum;
}
int main() {
	scanf("%lld", &tt);
	while( tt-- ) {
		scanf("%lld", &n);
		for( i = 1; i < N; ++i )
			t[i] = 0;
		ans = 0;
		for( i = 1; i <= n; ++i ) {
			scanf("%lld", &v);
			if(v == 0 )
				continue;
			ans += query(v-1);
			update(v);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
