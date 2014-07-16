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

const int N = 55555;
int t, i, j, ans, sa[N], tsa[N], ra[N], tra[N], lcp[N], plcp[N], phi[N], l, k, n, r, c[N], sum, p, L;
char s[N];

void csort(int k){
	for(i=0;i<N;++i)
		c[i]=0;
	for(i=0;i<n;++i)
		c[i+k<n?ra[i+k]:0]++;
	sum=0;
	for(i=0;i<max(n, 300);++i)
		p=c[i], c[i]=sum, sum+=p;
	for(i=0;i<n;++i)
		tsa[c[sa[i]+k<n?ra[sa[i]+k]:0]++]=sa[i];
	for(i=0;i<n;++i)
		sa[i]=tsa[i];
}
void Suffix_Array(){
	for(i=0;i<n;++i)
		sa[i]=i, ra[i]=s[i]-'!';
	for(k=1;k<n;k<<=1){
		csort(k);
		csort(0);
		tra[sa[0]]=r=0;
		for(i=1;i<n;++i){
			if(ra[sa[i]]==ra[sa[i-1]] && ra[sa[i]+k]==ra[sa[i-1]+k])
				tra[sa[i]]=r;
			else
				tra[sa[i]]=++r;
		}
		for(i=0;i<n;++i)
			ra[i]=tra[i];
	}
}
void LCP(){
	phi[0]=-1;
	for(i=1;i<n;++i)
		phi[sa[i]]=sa[i-1];
	L=0;
	for(i=0;i<n;++i){
		if(phi[i]==-1){
			plcp[i]=0;
			continue;
		}
		while(s[i+L]==s[phi[i]+L])
			++L;
		plcp[i]=L;
		L=max(L-1, 0);
	}
	for(i=1;i<n;++i)
		lcp[i]=plcp[sa[i]];

}
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		l=(int)strlen(s);
		s[l++]='!';
		n=l;
		--l;
		Suffix_Array();
		LCP();
		ans=(l-sa[0]);
		for(i=1;i<n;++i)
			ans+=(l-sa[i]-lcp[i]);
		printf("%d\n", ans);
	}
	return 0;
}
