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
const ll MOD = 1e9 + 3;
int t, n, i;
ll p[N], sum[N], v;

int main() {
	p[1] = sum[1] = 1;
	for( i = 2; i < N; ++i ) {
		v = (ll)i * i * i;
		p[i] = (p[i-1] + v) % MOD;
		sum[i] = (sum[i-1] + p[i]) % MOD;
	}
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		printf("%lld\n", sum[n]);
	}
	return 0;
}
