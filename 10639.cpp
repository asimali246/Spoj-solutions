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

int t, n, r;
int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d", &n);
		if( n == 1 ) {
			printf("poor conductor\n");
			continue;
		}
		--n;
		r = ( n / 5 ) + ((n % 5) ? 1 : 0);
		printf("%d ", r);
		++n;
		if( r & 1 ) {
			if( 5 * (r - 1) + 2 == n )
				printf("W L\n");
			if( 5 * (r - 1) + 3 == n )
				printf("A L\n");
			if( 5 * (r - 1) + 4 == n )
				printf("A R\n");
			if( 5 * (r - 1) + 5 == n )
				printf("M R\n");
			if( 5 * (r - 1) + 6 == n )
				printf("W R\n");
		} 
		else {
			if( 5 * (r - 1) + 2 == n )
				printf("W R\n");
			if( 5 * (r - 1) + 3 == n )
				printf("M R\n");
			if( 5 * (r - 1) + 4 == n )
				printf("A R\n");
			if( 5 * (r - 1) + 5 == n )
				printf("A L\n");
			if( 5 * (r - 1) + 6 == n )
				printf("W L\n");
		}
	}
	return 0;
}
