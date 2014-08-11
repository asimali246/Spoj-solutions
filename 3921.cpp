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
#include <stdint.h>
#include <unistd.h>
 
 using namespace std;
 
#define ll long long int
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;

int t, n, ans, i, tmp, j;
ii a[111];

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for( i = 1; i <= n; ++i )
			scanf("%d %d", &a[i].second, &a[i].first);
		sort( a + 1, a + n + 1 );
		ans = tmp = 0;
		for( i = 1; i <= n; ++i ){
			tmp = 0;
			for( j = 1; j <= n; ++j )
				if( a[j].second <= a[i].first )
					++tmp;
			ans = max( ans , tmp - i + 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}
