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

const int N = 1111;
int T, n, m, k, i, c[N], bit[N], cs = 1;
ii p[N * N];
ll ans = 0;

void update(int id ) {
	while( id < N ) {
		bit[id] += 1;
		id += ( id & (-id) );
	}
}
int query(int id) {
	int sum = 0;
	while( id > 0 ) {
		sum += bit[id];
		id -= ( id & (-id) );
	}
	return sum;
}

bool cmp( ii a, ii b ) {
	if( a.first != b.first )
		return a.first < b.first;
	return b.second < a.second;
}

int main() {
	scanf("%d", &T);
	while( T-- ) {
		scanf("%d %d %d", &n, &m, &k);
		for( i = 1; i <= k; ++i )
			scanf("%d %d", &p[i].first, &p[i].second);
		sort( p + 1, p + k + 1, cmp);
		for( i = 1; i < N; ++i )
			bit[i] = c[i] = 0;
		ans = 0;
		for( i = 1; i <= k ; ++i ) {
			ans += (ll) ( query(1000) - query(p[i].second) ) ;
			ans -= (ll) ( c[p[i].first] ) ;
			c[ p[i].first ]++;
			update( p[i].second ) ;
		}
		printf("Test case %d: %lld\n", cs++, ans);
	}
	return 0;
}
