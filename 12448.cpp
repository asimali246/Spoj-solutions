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

int t, a, b, l, g, i;
char s[11];

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%s", s);
		l = (int) strlen(s);
		for( i = 0; i < l; ++i )
			if( s[i] == '.' )
				break;
		if( i == l )
			printf("1\n");
		else {
			b = 0;
			a = pow(10, l - i - 1);
			for( i += 1; i < l; ++i )
				b = b*10 + s[i] - '0';
			g = gcd( a, b);
			a /= g, b /= g;
			printf("%d\n", a);
		}
	}
	return 0;
}
