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

const int N  = 1e6 + 10 ;
int t, l, i, j, cs = 1, p[N] ;
char s[N];

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &l);
		getchar();
		gets(&s[1]);
		p[1] = 0;
		i = 2, j = 0;
		while ( i <= l ) {
			while( j > 0 && s[j + 1] != s[i] )
				j = p[j];
			if( s[j + 1] == s[i] )
				++j;
			p[i] = j;
			++i;
		}
		printf("Test case #%d\n", cs++);
		for( i = 1; i <= l; ++i )
			if( p[i] > 0 && i % (i - p[i]) == 0 )
				printf("%d %d\n", i, i / ( i - p[i]));
		putchar('\n');
	}
	return 0;
}
