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

int n, k, i;
ll ans, f[15];

int main() {
	f[1] = f[0] = 1; 
	for( i = 2; i <= 13; ++i )
		f[i] = f[i-1] * i;
	while(scanf("%d %d", &n, &k) != EOF) {
		ans = f[n];
		for( i = 1; i <= k; ++i )
			scanf("%d", &n), ans /= f[n];
		printf("%lld\n", ans);
	}
	return 0;
}
