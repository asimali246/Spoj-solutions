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

int n, d, i, r;

int solve(){
	i=1;
	r=0;
	while(i<=n)
		r=(r+d)%i, ++i;
	return r+1;
}
int main(){
	while(1){
		scanf("%d %d", &n, &d);
		if(!n && !d)
			break;
		printf("%d %d %d\n", n, d, solve());
	}
	return 0;
}
