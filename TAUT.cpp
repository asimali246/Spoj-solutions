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

const int N = 121 ;
int t, n, a[N], i, l, Vis[N << 1] ;
char s[N], temp[N] ;
stack<int> st ;
bool flag ;

inline void check() {
	int x, y ;
	switch(s[i]) {
		case 'N':
			x = st.top() ; st.pop() ;
			st.push( 1 - x ) ;
			break ;
		case 'C':
			x = st.top(); st.pop() ;
			y = st.top(); st.pop() ;
			if( x == 0 || y == 0 ) 
				st.push(0) ;
			else
				st.push(1) ;
			break ;
		case 'D':
			x = st.top(); st.pop() ;
			y = st.top(); st.pop() ;
			if( x == 0 && y == 0 )
				st.push(0) ;
			else
				st.push(1) ;
			break ;
		case 'I':
			x = st.top(); st.pop() ;
			y = st.top(); st.pop() ;
			if( x == 1 && y == 0 ) 
				st.push(0) ;
			else
				st.push(1) ;
			break ;
		case 'E':
			x = st.top(); st.pop() ;
			y = st.top(); st.pop() ;
			if( (x == 0 && y == 0) || ( x == 1 && y == 1 ) )
				st.push(1) ;
			else
				st.push(0) ;
	}
}
void solve(int pos) {
	if( pos == l + 1 ) {
		for( i = n - 1; i >= 0; --i ) {
			if( islower( s[i] ) ) {
				st.push(a[s[i] - 'a']) ;
			} else {
				check() ;
			}
		}
		if( st.top() == 0 ) 
			flag = false ;
		st.pop() ;
		return ;
	}
	if( Vis[temp[pos] - 'a'] ){
		solve( pos + 1 ) ;
		return ;
	}
	Vis[temp[pos] - 'a'] = 1 ;
	a[temp[pos] - 'a'] = 0 ;
	solve(pos + 1) ;
	if( !flag ) 
		return ;
	a[temp[pos] - 'a'] = 1 ;
	solve(pos + 1) ;
	Vis[temp[pos] - 'a'] = 0 ;
	if( !flag ) 
		return ;
}
int main() {
	scanf("%d", &t) ;
	getchar() ;
	while( t-- ) {
		scanf("%s", s) ;
		n = (int) strlen(s) ;
		flag = true ;
		l = 1 ;
		memset( Vis, 0, sizeof Vis ) ;
		for( i = 0; i < n; ++i ) {
			if( islower(s[i]) ) {
				temp[l++] = s[i] ;
			}
		}
		--l ;
		solve(1) ;
		if( flag ) 
			puts("YES") ;
		else
			puts("NO") ;
	}
	return 0 ;
}
