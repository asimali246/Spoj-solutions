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

const int N = 1<<10;
int n, i, j, mx, mn, v, ans[N], cs = 1;

int main() {
	while(1) {
		scanf("%d", &n);
		if(!n)
			break;
		for( i = 1; i <= n; ++i )
			ans[i] = 0;
		mx = mn = 0;
		for( i = 1; i <= n; ++i ){
			for( j = 1; j <= n; ++j ) {
				scanf("%d", &v);
				mx += v;
				ans[j] += v;
				ans[i] -= v;
			}
		}
		for( i = 1; i <= n; ++i )
			if(ans[i] > 0 )
				mn += ans[i];
		printf("%d. %d %d\n", cs++, mx, mn);
	}
	return 0;
}
