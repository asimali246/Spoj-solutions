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
 
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e5 + 10 ;
int i, j, F[N], n ;
char s[N] ;

int main() {
	while( 1 ) {
		scanf("%s", s);
		if( s[0] == '*' )
			break;
		n = (int) strlen( s ) ;
		j = 0 ;
		for( i = 2; i <= n; ++i ) {
			while( j > 0 && s[i-1] != s[j] )
				j = F[j] ;
			if( s[i - 1] == s[j] )
				++j;
			F[i] = j;
		}
		if( n % ( n - F[n] ) == 0 )
			printf("%d\n", n / ( n - F[n] ) );
		else
			printf("1\n");
	}
	return 0;
}
