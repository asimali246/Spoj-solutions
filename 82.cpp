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


template < typename X > X gcd( X a, X b ) { if( !b ) return a ; else return gcd(b, a%b) ; }

typedef vector<int> vi ;
typedef pair<int, int> ii ;


int n, i, s[10], T, t[10], st, S[10], ts[100][10], N;
map<string, int> mp ;
map<string, int> num ;
char str[10], p, r ;
double a, b ;

int main() {
	scanf("%d", &T) ;
	while( T-- ) {
		mp.clear() ;
		num.clear() ;
		N = 1 ;
		scanf("%d", &n) ;
		getchar() ;
		for( i = 0; i < 10 ; ++i ) 
			s[i] = t[i] = S[i] = 0;
		memset(ts, 0, sizeof ts ) ;
		for( i = 1; i <= n; ++i ) {
			scanf("%d %s %c %c", &st, str, &p, &r) ;
			getchar() ;
			if( mp.count(str) == 0 )
				mp[str] = 0, num[str] = N++;
			if( r == 'R' ) {
				ts[num[str]][p - 'A']++ ;
			}
			else {
				if( !( mp[str] & ( 1 << ( p - 'A' ) ) ) ) {
					mp[str] = ( mp[str] | ( 1 << ( p - 'A' ) ) ) ;
					s[p - 'A'] += ts[ num[str] ][p - 'A'] + 1 ;
					t[p - 'A'] += st ;
					S[p - 'A']++ ;
				}
			}
		}
		for( i = 0; i < 9; ++i ) {
			putchar(i + 65) ;
			printf(" %d", S[i] ) ;
			if( S[i] == 0 ) {
				putchar('\n') ;
				continue ;
			}
			a = (double) s[i] / S[i] ;
			b = (double) t[i] / S[i] ;
			printf(" %.2lf %.2lf\n", a, b);
		}
	}
	return 0 ; 
}
