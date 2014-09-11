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

int t, n, k, a[555], l, h, m, i, ans, p[555], sum, c;

bool check(int v) {
	sum = c = 0;
	p[n] = p[0] = 0;
	for(i = n; i >= 1; --i ) {
		sum += a[i];
		if(sum > v) {
			sum = a[i], p[i] = 1, ++c;
			if(sum > v)
				return false;
		}
	}
	if(sum > v)
		p[0] = 1;
	if(p[n] || p[0])
		return false;
	if(c > k - 1)
		return false;
	return true;
}

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d %d", &n, &k);
		l = 1, h = 0;
		for( i = 1; i <= n; ++i )
			scanf("%d", &a[i]), h += a[i];
		while( l <= h ) {
			m = (l + h) >> 1;
			if(check(m))
				h = m - 1, ans = m;
			else
				l = m + 1;
		}
		for(i = 1; i <= n; ++i )
			p[i] = 0;
		check(ans);
		c = k - c - 1;
		for( i = 1; i <= n; ++i )
			if(!p[i] && c > 0)
				p[i] = 1, --c;
		for(i = 1; i <= n; ++i ) {
			if(i > 1)
				putchar(' ');
			printf("%d", a[i]);
			if( p[i])
				printf(" /");
		}
		putchar('\n');
	}
	return 0;
}
