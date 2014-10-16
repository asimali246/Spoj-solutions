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

int t ;
ll n ;

bool check(ll v) {
	ll n = v;
	int sum = 0;
	while(n != 0) {
		sum += n % 10;
		n /= 10;
	}
	if( v % sum == 0 )
		return true;
	return false;
}
int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%lld", &n);
		for( ; ; ++n ) {
			if( check(n) ) {
				printf("%lld\n", n);
				break;
			}
		}
	}
	return 0;
}
