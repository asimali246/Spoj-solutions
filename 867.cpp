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
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;

int a, b, c, d, e[1<<20], i, flag;

int main() {
	for ( i = 2; i <= 100; ++i )
		e[i*i*i] = i;
	for ( a = 2; a <= 100; ++a ){
		for ( b = 2; b <= 100; ++b )
			for ( c = b; c <= 100; ++c ){
				d = a*a*a - ( b*b*b + c*c*c );
				if( d > 1 && e[d] && e[d] >= b && e[d] >= c)
					printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, e[d]);
			}
	}
	return 0;
}
