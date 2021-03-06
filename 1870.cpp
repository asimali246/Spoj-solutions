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

int n, cs = 1;
int main() {
	while(1) {
		scanf("%d", &n);
		if(!n)
			break;
		if( n == 1 || n == 2 )
			printf("Case %d, N = %d, # of different labelings = 1\n", cs++, n);
		else
			printf("Case %d, N = %d, # of different labelings = %d\n", cs++, n, (int)pow(n, n-2));
	}
	return 0;
}
