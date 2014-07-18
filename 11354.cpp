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

int t, n, i;
ll k, p[60], s;

int solve(){
	int l=1, r=60, m, ans;
	while(l<=r){
		m=(l+r)>>1;
		if(p[m]<k)
			l=m+1;
		if(p[m]>=k)
			r=m-1, ans=m;
	}
	return ans;
}
int main(){
	p[0]=1;
	for(i=1;i<=60;++i)
		p[i]=2*p[i-1];
	p[0]=0;
	for(i=1;i<=60;++i)
		p[i]+=p[i-1];
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &k);
		n=solve();
		k-=p[n-1];
		s=p[n]-p[n-1];
		while(1){
			if(k>(s/2))
				putchar('6'), s/=2, k-=s;
			else
				putchar('5'), s/=2;
			if(s==1)
				break;
		}
		putchar('\n');
	}
	return 0;
}
