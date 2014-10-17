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

const int N = 1e5 + 10;
int i, l, j, b[N];
char s[N], p[N];

void preprocess() {
	i = 0, j = -1;
	b[i] = j;
	while( i < l ) {
		while( j >=0 && p[i] != p[j] )
			j = b[j];
		++i;
		++j;
		b[i] = j;
	}
}
void solve() {
	preprocess();
	i = 0, j = 0;
	while( i < l ) {
		while( j >=0 && s[i] != p[j] )
			j = b[j];
		++i;
		++j;
	}
}
int main() {
	while( scanf("%s", s) != EOF ) {
		l = (int) strlen( s );
		for( i = 0; i < l; ++i )
			p[i] = s[i];
		reverse( p, p + l ) ;
		solve() ;
		printf("%s", s);
		for( ; j < l; ++j )
			putchar(p[j]);
		putchar('\n');
	}
	return 0;
}
