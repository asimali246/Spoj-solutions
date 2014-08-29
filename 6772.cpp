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

int t, n, i, a, b;
char s[5];

int main() {
	scanf("%d", &t);
	getchar();
	while( t-- ) {
		a = b = 0;
		scanf("%d", &n);
		for( i = 1; i <= n; ++i ){
			scanf("%s", s);
			getchar();
			if( s[0] == 'l' )
				++a;
			else
				++b;
		}
		if( (n & 1) && (b & 1) )
			puts("hhb");
		else
		if( !(n & 1) && !(b & 1) )
			puts("hhb");
		else
			puts("lxh");
	}
	return 0;
}
