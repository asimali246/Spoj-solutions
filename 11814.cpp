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

const int N = 1e6 + 10;
int n, M, a[N], l, h, m, i, ans;

bool can(int h) {
	ll sum = 0;
	for( i = 1; i<= n; ++i )
		sum += ( ( h - a[i] ) >= 0 ) ? 0 : a[i] - h ;
	if( sum >= M ) 
		return true;
	return false;
}

int main() {
	scanf("%d %d", &n, &M);
	for( i = 1; i <= n; ++i )
		scanf("%d", &a[i]), h = max( h, a[i] );
	while( l <= h ) {
		m = ( l + h ) >> 1;
		if( can(m) )
			l = m + 1, ans = m;
		else
			h = m - 1;
	}
	printf("%d\n", ans);
	return 0;
}
