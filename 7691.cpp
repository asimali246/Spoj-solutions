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

int q, k, hom, het ;
map<int, int> mp;
char s[15];

int main() {
	scanf("%d", &q );
	while( q-- ) {
		scanf("%s %d", s, &k );
		if( s[0] == 'i' ) {
			if( mp.count(k) == 0 ) {
				mp[k] = 1 ;
				het++;
			}
			else {
				if(mp[k] == 1 ) 
					hom++;
				mp[k]++;
			}
		}
		else {
			if( mp.count(k) != 0 ) {
				mp[k]-- ;
				if( mp[k] == 1 )
					hom--;
				if( mp[k] == 0 )
					mp.erase(k), het--;
			}
		}
		if( hom > 0 && het > 1 ) 
			puts("both");
		else
		if( hom > 0 )
			puts("homo");
		else
		if(het > 1 )
			puts("hetero");
		else
			puts("neither");
	}
	return 0;
}
