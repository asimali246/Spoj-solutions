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

int n, a[1500], i, c, flag;

int main(){
	while(1){
		scanf("%d", &n);
		if(!n)
			break;
		for(i=1;i<=n;++i)
			scanf("%d", &a[i]);
		sort(a+1, a+n+1);
		flag=1, c=0;
		for(i=1;i<=n;++i){
			if(a[i]>c){
				flag=0;
				break;
			}
			else
				c=a[i]+200;
		}
		if(c<1422)
			flag=0;
		if(!flag){
			puts("IMPOSSIBLE");
			continue;
		}
		c=c-1422;
		for(i=n;i>=1;--i){
			if(1422-a[i]>c){
				flag=0;
				break;
			}
			else
				c=(1422-a[i]+200);
		}
		if(c<1422)
			flag=0;
		if(flag)
			puts("POSSIBLE");
		else
			puts("IMPOSSIBLE");
	}
	return 0;
}
