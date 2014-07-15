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

const ll MOD = 1e7+7;
ll ans, n, k;

ll mod(ll b, ll p){
	ll res=1;
	while(p){
		if(p&1)
			res=(res*b)%MOD;
		b=(b*b)%MOD;
		p>>=1;
	}
	return res;
}
int main(){
	while(1){
		scanf("%lld %lld", &n, &k);
		if(!n && !k)
			break;
		printf("%lld\n", (2*mod(n-1, k)+2*mod(n-1, n-1)+mod(n, k)+mod(n, n))%MOD);
	}
	return 0;
}
