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



const int N = 30100 ;
int t, n, i, p;
char s[N], ans[N] ;
bool side ;

int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%s", s ) ;
		n = (int) strlen( s ) ;
		side = false ;
		p = 0 ;
		for( i = 0; i < n; ++i ) {
			if( side ) {
				side = false ;
				if( s[i] == '0' ) {
					ans[p++] = '1' ;
				} else {
					while( i < n ) {
						ans[p++] = '1' - s[i] + 48 ;
						++i ;
					}
				}
			} else {
				side = true ;
				if( s[i] == '1' ) 
					ans[p++] = '1' ;
				else {
					while( i < n ) 
						ans[p++] = s[i++] ;
				}
			}
		}
		for( i = 0; i < n; ++i ) 
			putchar(ans[i] ) ;
		putchar('\n') ;
	}
	return 0 ;
}L
