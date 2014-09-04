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

int t, ans;
ll n, v;

int main() {
	scanf("%d", &t);
	while ( t-- ) {
		scanf("%lld", &n);
		ans = 0;
		v = ((double)log(n)/log(2));
		if(pow(2, v) < n )
			++v;
		v = (ll) pow( 2, v);
		printf("%lld ", v);
		while( v != 0 ) {
			if( !n || v == n )
				break;
			++ans;
			v /= 2;
			if( n >= v )
				n -= v;
		}
		printf("%d\n", ans);
	}
	return 0;
}
