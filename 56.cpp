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



const int N = 2 * 1e4 + 10 ;
int n, i, mx, d, ans, t = 10, cnt;
char s[N] ;
stack<int> st ;

int main() {
	while( t-- ) {
		st = stack<int>() ;
		scanf("%d", &n) ;
		scanf("%s", s ) ;
		mx = 0 ;
		ans = 0 ;
		st.push( 0 ) ;
		cnt = 0 ;
		for( i = 0; i < n; ++i ) {
			d = st.top() ; st.pop() ;
			if( s[i] == '1' ) {
				cnt++ ;
				st.push( d + 1 ) ;
				st.push( d + 1 ) ;
			}
			if( d > mx ) {
				mx = d ;
				ans = cnt ;
			}
		}
		printf("%d\n", ans ) ;
	}
	return 0 ;
}
