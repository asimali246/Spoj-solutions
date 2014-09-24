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

const int N = 1010;
int t, i, l, a[50], mx, cnt, d;
char s[N], ch;

int main() {
	scanf("%d", &t);
	getchar();
	while( t-- ) {
		gets(s);

		l = (int) strlen(s);

		memset(a, 0, sizeof a);

		for( i = 0; i < l; ++i )
			if( s[i] != ' ' ) 
				a[s[i] - 'A']++;

		mx = -9, cnt = 0;

		for( i = 0; i < 26; ++i )
			mx = max( mx, a[i] );

		for( i = 0; i < 26; ++i )
			if(a[i] == mx)
				cnt++, ch = i + 'A';

		if(cnt > 1 )
			puts("NOT POSSIBLE");
		else {

			d = ch - 'E';
			d += ( d < 0 ) ? 26 : 0;
			printf("%d ", d );
			for( i = 0; i < l; ++i ){
				if( s[i] == ' ') {
					putchar(' ');
					continue;
				}
				ch = s[i] - d;
				ch += ( ch < 65 ) ? 26 : 0;
				putchar(ch);
			}
			putchar('\n');
		}
	}
	return 0;
}
