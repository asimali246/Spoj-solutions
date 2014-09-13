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

const int N = 1 << 17;
int i, j, la, lb, p;
char a[N], b[N], s[N];

int main() {
	while( 1 ) {
		scanf("%s %s", a, b);
		if(a[0] == '*')
			break;
		la = (int)strlen(a), lb = (int)strlen(b);
		if(la > lb) {
			for( i = 0; i < la - lb; ++i )
				s[i] = '0';
			p = 0;
			for(; p < lb; ++p)
				s[i++] = b[p];
			s[i] = '\0';
			for(p = 0; p <= i; ++p)
				b[p] = s[p];
		}
		else
		if(la < lb) {
			for( i = 0; i < lb - la; ++i )
				s[i] = '0';
			p = 0;
			for(; p < la; ++p)
				s[i++] = a[p];
			s[i] = '\0';
			for(p = 0; p <= i; ++p)
				a[p] = s[p];	
		}
		p = strcmp(a, b);
		if(p == 0 )
			puts("=");
		else
		if( p > 0 )
			puts(">");
		else
			puts("<");
	}
	return 0;
	return 0;
}
