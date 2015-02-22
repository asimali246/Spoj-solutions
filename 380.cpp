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


const int N = 111 ;
int i, l, sum, games, p;
map<string, int> mp ;
char s[N], t[N], ch;

int main() {
	while( gets(s) && strlen(s) != 0 ) {
		l = (int) strlen( s ) ;
		for( i = 0; i < l; ++i ) {
			ch = s[i] ;
			if( (ch >= 97 && ch <= 122 ) || ( ch >= 65 && ch <= 90 ) ) {
				t[p++] = tolower(ch) ;
			}
			else {
				t[p] = '\0' ;
				if( strcmp( t, "bullshit" ) == 0 ) {
					games++ ;
					sum += (int) mp.size() ;
					mp.clear() ;
				}
				else
				if( p != 0 ) {
					if( mp.count(t) == 0 ) 
						mp[t] = 1 ;
				}
				p = 0 ;
			}
		}
	}
	t[p] = '\0' ;
	if( strcmp( t, "bullshit" ) == 0 ) {
		games++ ;
		sum += (int) mp.size() ;
	}
	p = gcd(sum, games ) ;
	printf("%d / %d\n", sum / p, games / p ) ;
	return 0 ;
}
