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

int n, i;
ll dp[33];

int main(){
	dp[0]=1, dp[2]=3;
	for(i=4;i<=30;i+=2)
		dp[i]=4*dp[i-2]-dp[i-4];
	while(1){
		scanf("%d", &n);
		if(n==-1)
			break;
		printf("%lld\n", dp[n]);
	}
	return 0;
}
