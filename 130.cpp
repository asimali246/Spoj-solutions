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

const int N = 2010000;
int t, i, j, n, s, e, p, v[N], l, h, m, lim, ind[N];
pair<ii, int> a[1<<14];

bool cmp(pair<ii, int> a, pair<ii, int> b) {
	return a.first.second <= b.first.second;
}
int solve( int v ) {
	l = 1, h = lim;
	int ans;
	while( l <= h ) {
		m = ( l + h ) >> 1;
		if( ind[m] > v ) 
			h = m - 1;
		if( ind[m] < v ) 
			ans = m, l = m + 1;
		if( ind[m] == v ) {
			ans = m;
			break;
		}
	}
	return ::v[ ind[ans] ];
}
int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		for( i = 1; i <= n; ++i ) {
			scanf("%d %d %d", &s, &e, &p);
			e += s;
			a[i].first.first = s, a[i].first.second = e;
			a[i].second = p;
		}
		sort( a + 1, a + n + 1, cmp);
		p = 0;
		lim = 1;
		ind[1] = 0;
		for( i  = 1; i <= n; ++i ) {
			v[a[i].first.second] = max( p, a[i].second + solve(a[i].first.first) );
			p = v[a[i].first.second];
			ind[ ++lim ] = a[i].first.second; 
		}
		printf("%d\n", p);
	}
	return 0;
}
