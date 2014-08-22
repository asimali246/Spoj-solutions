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
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;

int t, n, s, e, ans, i;
vector<ii> v;

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		v.clear();
		for( i = 1 ; i <= n; ++i )
			scanf("%d %d", &s, &e), v.push_back(ii(e, s));
		sort(v.begin(), v.end());
		e = -1;
		ans = 0;
		for( i = 0; i < n; ++i ) {
			if( v[i].second >= e ){
				e = v[i].first;
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
