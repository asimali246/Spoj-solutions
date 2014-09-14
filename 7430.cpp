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

int t, n, i;
ll ans[44];

int main() {
	ans[1] = 2;
	for( i = 2; i <= 35; ++i )
		ans[i] = 2 + ans[i-1] * 3;
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		printf("%lld\n", ans[n]);
	}
	return 0;
}
