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

const int N = 50010;
int t, i, x, y, l;
char s[N];

int main() {
	scanf("%d", &t);
	while( t-- ) {

		scanf("%s", s);
		l = (int) strlen( s );
		x = y = 0;
		for( i = 0; i < l; ++i ) {
			x = ( x * 10 + s[i] - 48 ) % 252;
			y = ( y * 10 + s[i] - 48 ) % 525;
		}
		if( x == 0 )
			printf("Yes ");
		else
			printf("No ");
		if( y == 0 )
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
