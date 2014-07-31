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

int t, d, n, i, j;
ll a[13], sum, ans[100];

int main(){
	scanf("%d", &t);
	for(i=1;i<=10;++i)
		a[i]=1;
	ans[1]=10;
	for(i=2;i<=64;++i){
		sum=0;
		for(j=2;j<=10;++j)
			a[j]+=a[j-1];
		for(j=1;j<=10;++j)
			sum+=a[j];
		ans[i]=sum;
	}
	while(t--){
		scanf("%d %d", &d, &n);
		printf("%d %lld\n", d, ans[n]);
	}
	return 0;
}
