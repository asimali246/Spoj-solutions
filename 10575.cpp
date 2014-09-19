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

const int N = 1010;
int n, H[N], W[N], D[N], h, w, d, i;
ll ans;

int main() {
	while(1) {
		scanf("%d", &n);
		if(!n)
			break;
		for( i = 1; i <= n; ++i ) {
			scanf("%d %d %d", &H[i], &W[i], &D[i]);
			if( i == 1 ) 
				h = H[i], w = W[i], d = D[i];
			else 
				h = gcd(h, H[i]), w = gcd(w, W[i]), d = gcd(d, D[i]);
		}
		if( h <= w && h <= d )
			w = d = h;
		else
		if( w <= h && w <= d )
			h = d = w;
		else
			h = w = d;
		ans = 0;
		for( i = 1; i <= n; ++i ) 
			ans += (ll)(H[i] * W[i] * D[i]) / ( h * w * d);
		printf("%lld\n", ans);
	}
	return 0;
}
