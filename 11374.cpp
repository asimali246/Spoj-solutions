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

const int N = 1e5 + 10;
int t, n, r, vis[N], s[N], i, cs = 1, id, c;
bool ans;
map<ii, int> mp;

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d %d", &n, &r);
		for( i = 1000; i <= 9999; ++i )
			vis[i] = s[i] = 0;
		ans = true;
		mp.clear();
		while( r-- ) {
			scanf("%d %d", &id, &c);
			if( !ans )
				continue;
			if( mp.count(ii(id, c)) == 0 ) {
				s[c]++;
				mp[ii(id, c)] = 1;
			}
			else {
				ans = false;
			}
		}
		printf("Scenario #%d:", cs++ );
		if( ans )
			printf(" possible\n");
		else
			printf(" impossible\n");
	}
	return 0;
}
