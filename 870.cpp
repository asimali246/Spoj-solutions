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


int i, a, b, l, pos;
char ss[1010], s[101];
ll num;

inline int val(char c) {
	if( c >= 48 && c <= 57 )
		return c - 48;
	return c - 55;
}
ll Integer() {
	ll ans = 0;
	ll x = 1;
	for( i = l - 1; i >= 0 ; --i ){
		ans += (val(s[i]) * x);
		x *= a;
	}
	return ans;
}
char revval(int v) {
	if( v < 10 )
		return v + 48;
	return v + 55;
}
void Base() {
	while(num) {
		s[pos++] = revval(num % b);
		num /= b;
	}
}
int main() {
	while( gets(ss) ) {
		sscanf(ss, "%s %d %d", s, &a, &b);
		l = strlen(s);
		pos = 1;
		num = Integer();
		Base();
		if( pos > 8 )
			printf("  ERROR\n");
		else{
			for( i = 1; i <= 8 - pos; ++i )
				putchar(' ');
			for( i = pos - 1; i >= 1; --i )
				putchar(s[i]);
		}
		putchar('\n');
	}
	return 0 ;
}
