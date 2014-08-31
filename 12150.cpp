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

const int N = 1<<20;
int t, n, a[N], i, d[11], j;

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		for( i = 1; i <= n; ++i )
			scanf("%d", &a[i]);
		memset(d, -1, sizeof d);
		d[a[n]] = n;
		for( i = n - 1; i >= 1; --i ) {
			if( a[i] < a[i + 1] ){
				for( j = a[i] + 1; j <= 9; ++j )
					if( d[j] != -1 )
						break;
				swap(a[d[j]], a[i]);
				++i;
				for( j = i; j <= ( n - i ) / 2 + i; ++j )
					swap( a[j], a[n - j + i]);
				break;
			}
			else
				d[a[i]] = max( d[a[i]], i);
		}
		if( i == 0 )
			printf("-1");
		else
			for( i = 1; i <= n; ++i )
				printf("%d", a[i]);
		putchar('\n');
	}
	return 0;
}
