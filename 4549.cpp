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

char a[1010], s[10101];
int i, l, ans, x, y, pos, flag;
int c[] = {63, 10, 93, 79, 106, 103, 119, 11, 127, 107};
map<string, int> mp;

int main() {
	mp.clear();
	mp["063"] = 0, mp["010"] = 1, mp["093"] = 2, mp["079"] = 3, mp["106"] = 4;
	mp["103"] = 5, mp["119"] = 6, mp["011"] = 7, mp["127"] = 8, mp["107"] = 9;
	while(1) {
		scanf("%s", s);
		if( s[0] == 'B' )
			break;
		l = (int) strlen( s );
		pos = 0;
		x = y = 0;
		flag = 0;
		a[3] = '\0';
		for( i = 0 ; i < l ; ++i ) {
			if( s[i] ==  '+' ){
				flag = 1, pos = 0;
				continue;
			}
			a[pos++] = s[i];
			if( pos == 3 ) {
				(!flag) ? (x = x*10 + mp[a]) : (y = y*10 + mp[a]);
				pos = 0;
			}
		}
		x += y;
		printf("%s", s);
		pos = 0;
		if( x == 0 )
			printf("063");
		while( x != 0 ) 
			a[pos++] = x%10 + 48, x /= 10;
		for( i = pos - 1; i >= 0; --i )
			printf("%03d", c[a[i] - 48]); 
		putchar('\n');
	}
	return 0;
}
