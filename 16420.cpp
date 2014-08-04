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
#define EPS 1e-15

template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}

typedef vector<int> vi;
typedef pair<int, int> ii;

int t, n, ans, i, x, flag;
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		ans=flag=0, x=1;
		if(!(n&1))
		for(i=30;i>=0;--i){
			if(n&(1<<i)){
				flag=1;
				ans+=x;
			}
			if(flag)
				x*=2;
		}
		else
			ans=n;
		printf("%d\n", ans);
	}
	return 0;
}
