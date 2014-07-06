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

int t, a, b, l, i, j, ans, c;
vi p;
bitset<1010> bs;

int main(){
	bs.set(), p.clear();
	for(i=2;i<=1000;++i)
		if(bs[i]){
			p.push_back(i);
			for(j=i+i;j<=1000;j+=i)
				bs[j]=0;
		}
	l=(int)p.size();
	scanf("%d", &t);
	while(t--){
		ans=1;
		scanf("%d %d", &a, &b);
		a=gcd(a, b);
		for(i=0;i<l && p[i]*p[i]<=a;++i){
			c=0;
			while(a%p[i]==0)
				++c, a/=p[i];
			ans*=c+1;
		}
		if(a>1)
			ans*=2;
		printf("%d\n", ans);
	}
	return 0;
}
