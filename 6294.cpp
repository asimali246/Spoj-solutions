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

const int N = 30100;
int tt, i, t[N], n;
char s[22];
map<string, int> r;
map<int, string> pos;
ll ans;

int sum(int id) {
	int sum = 0;
	while( id > 0 ) {
		sum += t[id];
		id -= (id & (-id));
	}
	return sum;
}
void update(int p, int v) {
	while( p <= n ) {
		t[p] += v;
		p += (p & (-p));
	}
}
int main() {
	scanf("%d", &tt);
	while( tt-- ) {
		scanf("%d", &n);
		getchar();
		pos.clear(), r.clear();
		for( i = 1; i <= n; ++i )
			scanf("%s", s), pos[i] = s, t[i] = 0;
		for( i = 1; i <= n; ++i )
			scanf("%s", s), r[s] = i;
		ans = 0;
		for( i = 1; i <= n; ++i ) {
			ans += (ll)(i - sum(r[pos[i]]) - 1);
			update(r[pos[i]], 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
