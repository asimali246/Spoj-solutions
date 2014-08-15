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

ll t, n, k, ans;

int main() {
	scanf("%lld", &t);
	while( t-- ) {
		scanf("%lld %lld", &n, &k);
		ans = 0;
		while( k != 1 ) {
			if(!(k & 1))
				++ans ;
			else
				++k;
			k >>= 1;
		}
		if(! (ans & 1) )
			puts("Male");
		else
			puts("Female");
	}
	return 0;
}
