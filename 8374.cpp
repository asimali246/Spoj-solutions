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
 
#define ll unsigned long long int
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;

int r, b, h, w, p;
ll i;

int main() {
	scanf("%d %d", &r, &b);
	p = b;
	b += r;
	for(i = 3; ; ++i ) {
		if( b % i == 0 ) {
			h = i, w = b/i;
			if( ( (h-2) * (w-2) ) == p )
				break;
		}
	}
	if( w > h )
		swap(h, w);
	printf("%d %d\n", h, w);
	return 0;
}
