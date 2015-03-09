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



const int N = 1111 ;
int t, n, i, j, l, vis[N];
char name[N][20], ext[N][20], ch, temp[33], MN[N], ME[N], lN[N], lE[N] ;
int sn, ln, se, le ;
string dn, de ;
bool space = false, same ;

void solve() {
	for( j = 0; j < sn; ++j ) {
		ch = '*' ;
		same = true ;
		for( i = 1; i <= n; ++i ) {
			if( vis[i] ) {
				if( ch == '*' ) 
					ch = name[i][j] ;
				else {
					if( name[i][j] != ch ) {
						same = false ;
						break ;
					}
				}
			}
		}
		if( same ) 
			dn += ch ;
		else
			dn += "?" ;
	}
	if( ln > sn )
		dn += "*" ;
	for( j = 0; j < se; ++j ) {
		ch = '*' ;
		same = true ;
		for( i = 1; i <= n; ++i ) {
			if( vis[i] ) {
				if( ch == '*' ) 
					ch = ext[i][j] ;
				else {
					if( ext[i][j] != ch ) {
						same = false ;
						break ;
					}
				}
			}
		}
		if( same ) 
			de += ch ;
		else
			de += "?" ;
	}
	if( le > se )
		de += "*" ;
}

bool check() {
	for( i = 1; i <= n; ++i ) {
		if( !vis[i] ) {
			same = true ;
			int pos = 0 ;
			for( j = 0 ; j < lN[i]; ++j ) {
				if( pos == dn.length() ) {
					same = false ;
					break ;
				}
				if( dn[pos] == '*' ) {
					break ;
				}
				if( dn[pos] == '?' ) {
					pos++ ;
					continue ;
				}
				if( dn[pos] != name[i][j] ) {
					same = false ;
					break ;
				}
				++pos ;
			}
			if( pos < dn.length() ) {
				if( dn[pos] != '*' ) {
					same = false ;
				}
			}
			if( same ) 
				MN[i] = 1 ;
			else
				MN[i] = 0 ;
		}
	}

	for( i = 1; i <= n; ++i ) {
		if( !vis[i] ) {
			same = true ;
			int pos = 0 ;
			for( j = 0 ; j < lE[i]; ++j ) {
				if( pos == de.length() ) {
					same = false ;
					break ;
				}
				if( de[pos] == '*' ) {
					break ;
				}
				if( de[pos] == '?' ) {
					pos++ ;
					continue ;
				}
				if( de[pos] != ext[i][j] ) {
					same = false ;
					break ;
				}
				++pos ;
			}
			if( pos < de.length() ) {
				if( de[pos] != '*' ) {
					same = false ;
				}
			}
			if( same ) 
				ME[i] = 1 ;
			else
				ME[i] = 0 ;
		}
	}
	for( i = 1; i <= n; ++i ) 
		if( MN[i] && ME[i] ) 
			return false ;
	return true ;
}

int main() {
	scanf("%d", &t) ;
	getchar() ;
	getchar() ;
	while( t-- ) {
		n = 1 ; 
		sn = se = INF ;
		ln = le = -INF ;
		memset(vis, 0, sizeof vis ) ;
		while( gets(temp) && strlen(temp) != 0 ) {
			l = (int) strlen( temp ) ;
			j = 0 ;
			if( temp[0] == '-' ) 
				vis[n] = 1 ;
			for( i = 1; temp[i] != '.' && temp[i] != '\0'; ++i ) 
				name[n][j++] = temp[i] ;
			if( vis[n] ) {
				sn = min(sn, j) ;
				ln = max(ln, j) ;
			}
			lN[n] = j ;
			if( temp[i] == '.' )
				++i ;
			j = 0 ;
			for( ; temp[i] != '\0'; ++i ) 
				ext[n][j++] = temp[i] ;
			if( vis[n] ) {
				se = min(se, j) ;
				le = max(le, j) ;
			}
			lE[n] = j ;
			++n ;
		}
		--n ;
		for( i = 1; i <= n; ++i ) 
			MN[i] = ME[i] = 0 ;
		dn = de = "" ;
		solve() ;
		if( space ) 
			putchar('\n') ;
		space = true ;
		if( !check() ) 
			puts("IMPOSSIBLE") ;
		else
			printf("DEL %s.%s\n", dn.c_str(), de.c_str() ) ;
	}
	return 0 ;
}
