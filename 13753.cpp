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

const int N = 10000100;
int i, j, vis[N], t, n;
bitset<3333> bs;
ll ans[N];
vi p;

int main() {
	bs.set(), p.clear();
	for( i = 1; i < N; ++i )
		vis[i] = INF;
	for(i = 2; i <= 3200; ++i ) 
		if( bs[i] ) {
			p.push_back(i);
			for( j = i + i; j <= 3200; j += i )
				bs[j] = 0;
		}
	for( i = 0; i < (int)p.size(); ++i ) {
		for( j = p[i]; j < N; j += p[i] )
			vis[j] = min( vis[j], p[i]);
	}
	for( i = 2; i < N; ++i ) 
		ans[i] = ans[i-1] + (ll)( (vis[i] == INF) ? i : vis[i] );
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		printf("%lld\n", ans[n]);
	}
	return 0;
}
