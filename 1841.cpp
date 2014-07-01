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

const int N = 100010;
int tt, s, t, ans[N], i, j, v, n;
bitset<N> bs;
queue<int> q;

void solve(){
	ans[s]=0;
	q.push(s);
	while(!q.empty()){
		v=q.front();q.pop();
		if(v==t)
			break;
		for(i=1;i<=9;++i){
			n=i*1000+v%1000;
			if(bs[n] && ans[n]==-1)
				ans[n]=ans[v]+1, q.push(n);
		}
		for(i=0;i<=9;++i){
			n=v/1000;
			n=(n*1000)+i*100;
			n+=v%100;
			if(bs[n] && ans[n]==-1)
				ans[n]=ans[v]+1, q.push(n);
		}
		for(i=0;i<=9;++i){
			n=v/100;
			n=(n*100)+i*10;
			n+=v%10;
			if(bs[n] && ans[n]==-1)
				ans[n]=ans[v]+1, q.push(n);
		}
		for(i=0;i<=9;++i){
			n=v/10;
			n*=10, n+=i;
			if(bs[n] && ans[n]==-1)
				ans[n]=ans[v]+1, q.push(n);
		}
	}
}
int main(){
	bs.set();
	bs[0]=bs[1]=0;
	for(i=2;i<N;++i)
		if(bs[i]){
			for(j=i+i;j<N;j+=i)
				bs[j]=0;
		}
	scanf("%d", &tt);
	while(tt--){
		q=queue<int>();
		scanf("%d %d", &s, &t);
		for(i=1000;i<N;++i)
			ans[i]=-1;
		solve();
		if(ans[t]==-1)
			puts("Impossible");
		else
			printf("%d\n", ans[t]);
	}
	return 0;
}
