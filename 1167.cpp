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

int t;
ll h, ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &h);
		if(h==0)
			printf("0\n");
		else
		if(h<=4)
			printf("%lld\n", h-1);
		else{
			--h;
			ans=((h+1)*(h+2))/6;
			printf("%lld\n", ans);
		}
	}
	return 0;
}
