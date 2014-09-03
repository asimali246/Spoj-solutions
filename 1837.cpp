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

const int N = 1 << 14;
int t, n, f, a[N], i, mx, res;
double l, h, m, ans;

int check(double v) {
	int ans = 0;
	for(int i = 1; i <= n; ++i )
		ans += (int)( (double) a[i] * PI * a[i] / v );
	if( ans >= f)
		return 1;
	return 0;
}

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d %d", &n, &f);
		mx = -INF;
		for( i = 1; i <= n; ++i )
			scanf("%d", &a[i]), mx = max( mx, a[i] );
		++f;
		l = 0.0;
		h = (double) PI * mx * mx;
		for( i = 1; i <= 50; ++i ) {
			m = ( l + h ) / 2.0;
			res = check(m);
			if( res )
				l = m, ans = m;
			else
				h = m;
		}
		printf("%.4lf\n", ans);
	}
	return 0;
}
