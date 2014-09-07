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

char s[255];
int i, l, sum, n, sgn, cnt, v, x, d[10], ans;

int main() {
	while( scanf("%s", s) != EOF ) {
		l = (int) strlen(s);
		memset(d, 0, sizeof d);
		sum = n = 0;
		for( i = 0; i < l; ++i )
			d[s[i] - '0']++;
		if(l % 3 == 1 ) {
			sum += s[0] - '0';
			n = s[0] - '0';
		}
		if(l % 3 == 2 ) {
			sum += s[0] + s[1] - 96;
			n = (s[0] - '0') * 10 + s[1] - 48;
		}
		x = cnt = 0;
		sgn = -1;
		for(i = l%3; i < l; ++i ) {
			v = s[i] - '0';
			x = x*10 + v, ++cnt;
			if( cnt == 3 ) {
				cnt = 0;
				n += x * sgn;
				sgn *= -1;
				x = 0;
			}
			sum += v;
		}
		ans = d[1];
		v = s[l-1] - 48;
		ans += ( v & 1) ? 0 : d[2];
		ans += ( sum % 3 ) ? 0 : d[3];
		v = 0;
		if(l - 2 >= 0 )
			v = s[l-2] - 48;
		v = v*10 + s[l-1] - 48;
		ans += (v % 4 ) ? 0 : d[4];
		if( s[l-1] == '0' || s[l-1] == '5')
			ans += d[5];
		v = s[l-1] - 48;
		if( (!(v%2)) && (!(sum%3)) ) 
			ans += d[6];
		if(n%7 == 0 )
			ans += d[7];
		v = 0;
		if( l - 3 >= 0 )
			v = s[l-3] - 48;
		if( l -2 >= 0 )
			v = v*10 + s[l-2] - 48;
		v = v*10 + s[l-1] - 48;
		if( v % 8 == 0 )
			ans += d[8];
		if( sum % 9 == 0 )
			ans += d[9];
		printf("%d\n", ans);
	}
	return 0;
}
