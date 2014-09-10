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

const int N = 1<<20;
ll t, n, i, a[N], num;
char s[1111];
ll ans;

int main() {
	scanf("%lld", &t);
	while( t-- ) {
		scanf("%lld", &n);
		for( i = 1; i <= n; ++i )
			scanf("%s %lld", s, &a[i]);
		sort(a + 1, a + n + 1);
		ans = 0, num = 1;
		for( i = 1; i <= n; ++i ) {
			ans += abs(num - a[i]);
			++num;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
