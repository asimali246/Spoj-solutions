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

//Stirling Approximation Formula
int t;
ll ans, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		if(n<=3){
			printf("1\n");
			continue;
		}
		ans=1+(ll)(((log(2*PI*n))/2+n*(log(n)-1))/log(10));
		printf("%lld\n", ans);
	}
	return 0;
}
