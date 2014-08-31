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

int n, m, k, x, y, p, q, r, s, i, j, a, b, c, ans;

int main() {
	scanf("%d %d", &n, &m);
	scanf("%d", &k);
	while( k-- ) {
		scanf("%d %d %d %d %d %d", &x, &y, &p, &q, &r, &s);
		ans = 0;
		for( j = 1;j <= m; ++j ) {
			a = abs(p - 1) + abs(q - j);
			b = abs(r - 1) + abs(s - j);
			c = abs(x - 1) + abs(y - j);
			if( c < a && c < b )
				ans = 1;
			a = abs(p - n) + abs(q - j);
			b = abs(r - n) + abs(s - j);
			c = abs(x - n) + abs(y - j);
			if( c < a && c < b )
				ans = 1;
		}
		for( i = 1; i <= n; ++i ) {
			a = abs(p - i) + abs(q - 1);
			b = abs(r - i) + abs(s - 1);
			c = abs(x - i) + abs(y - 1);
			if( c < a && c < b )
				ans = 1;
			a = abs(p - i) + abs(q - m);
			b = abs(r - i) + abs(s - m);
			c = abs(x - i) + abs(y - m);
			if( c < a && c < b )
				ans = 1;
		}
		if(ans)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
