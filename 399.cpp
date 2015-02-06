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



int n, i, mn, sum;
char s[] = {'A', 'B', 'C', 'D', 'E' } ;
string ans;
char x[10] ;
vector<string> v ;

int solve(string v) {
	int i, j, ans = 0, k;
	for( i = 0; i < 5; ++i ) {
		for( j = i + 1; j < 5; ++j ) {
			for( k = 0; k < 5; ++k ) {
				if( s[k] == v[j] ) {
					++ans;
					break ;
				} 
				else
				if( s[k] == v[i] ) 
					break ;
			}
		}
	}
	return ans ;
}

int main() {
	while( 1 ) {
		scanf("%d", &n) ;
		if( !n ) 
			break ;
		v.clear() ;
		for( i = 1; i <= n; ++i ) 
			scanf("%s", x), v.push_back(x) ;
		mn = INF ;
		do{
			sum = 0 ;
			for( i = 0; i < n; ++i ) 
				sum += solve(v[i]) ;
			if( sum < mn ) {
				mn = sum ;
				ans = "" ;
				for( i = 0; i < 5; ++i ) 
					ans += s[i] ;
			}
		}while( next_permutation(s, s + 5) ) ;
		printf("%s is the median ranking with value %d.\n", ans.c_str(), mn ) ;
	}
	return 0 ;
} 
