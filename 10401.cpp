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

const int N = 1<<17;
int t, n, m, ans, c, i, j, a[N], sum[N], pc;

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d %d", &n, &m);
		c = 0;
		ans = INF;
		for( i = 1; i <= n; ++i ) {
			scanf("%d", &a[i]);
			sum[i] = a[i] + sum[i-1];
			pc = c;
			for( j = i - c - 1; j >= 0; --j )
				if(sum[i] - sum[j] <= m)
					++c;
				else
					break;
			if(pc == c)
				ans = min(ans, sum[i] - sum[i - c]);
			else
				ans = sum[i] - sum[i - c];
		}
		printf("%d %d\n", ans, c);
	}
	return 0;
}
