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

const int N = 1 << 18;
int n, a, b, A[N], B[N], i, j, x[55], p, q, l1, l2, sum, v;
ll ans;

inline int upper() {
	int l = 1, h = q, m, ans = INF;
	while(l <= h) {
		m = (l + h) >> 1;
		if(B[m] > v ) 
			ans = m, h = m - 1;
		if( B[m] <= v )
			l = m + 1;
	}
	if(ans == INF)
		return q;
	return ans - 1;
}

inline int lower() {
	int l = 1, h = q, m, ans = INF;
	while( l <= h ) {
		m = (l + h) >> 1;
		if(B[m] >= v)
			h = m - 1;
		if( B[m] < v )
			l = m + 1, ans = m;
	}
	if(ans == INF)
		return 1;
	return ans + 1;
}

int main() {
	scanf("%d %d %d", &n, &a, &b);
	for( i = 0; i < n; ++i )
		scanf("%d", &x[i]);
	p = q = 1;
	l1 = (int)pow(2, n>>1);
	l2 = (int)pow(2, n - (n >> 1));
	for( j = 0; j < l1; ++j ){
		sum = 0;
		for(i = 0; i < n/2; ++i )
			if(j & ( 1 << i ))
				sum += x[i];
		A[p++] = sum;
	}
	for( j = 0; j < l2; ++j ) {
		sum = 0;
		for( i = n/2 ; i < n; ++i )
			if(j & ( 1 << (i - n/2)))
				sum += x[i];
		B[q++] = sum;
	}
	sort(A + 1, A + p);
	sort(B + 1, B + q);
	--p, --q;
	for( i = 1; i <= p; ++i ) {
		v = b - A[i];
		l1 = upper();
		v = a - A[i];
		l2 = lower();
		ans += (ll)(l1 - l2 + 1);
	}
	printf("%lld\n", ans);
	return 0;
}
