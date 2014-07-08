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

//Rabin Miller prime method.
/*
	Method:
	Find s and d for n-1 such that n-1=(2**s)d;
	Repeat k times
		now choose random number a from 2 to n-2
		Calculate x=a^d mod n
		if(x==n-1 || x==1) then continue with next a
		repeat s times:
			x=x^2 mod n
			if(x==1) then not prime
			if(x==n-1) check next a
		if not continues then not prime
	return true;
*/
int t, i, a[15];
ll n, s, d, x, j, flag;


ll mul(ll x, ll b){
	ll res=0;
	while(b){
		if(b&1)
			res+=x, res%=n, --b;
		b>>=1;
		x<<=1;
		x%=n;
	}
	return res;
}
ll mod(){
	ll res=1;
	ll b=a[i];
	ll p=d;
	while(d){
		if(d&1)
			res=mul(res, b);
		d>>=1;
		b=mul(b, b);
	}
	d=p;
	return res;
}
bool isPrime(){
	s=0;
	d=n-1;
	while(d%2==0)
		++s, d/=2;
	for(i=1;i<=10;++i){
		if(a[i]>n-2)
			break;
		x=mod();
		flag=0;
		if(x==1 || x==n-1)
			continue;
		for(j=1;j<=s;++j){
			x=mul(x, x);
			if(x==1)
				return false;
			if(x==n-1){
				flag=1;
				break;
			}
		}
		if(!flag)
			return false;
	}
	return true;
}
int main(){
	a[1]=2, a[2]=3, a[3]=5, a[4]=7, a[5]=11, a[6]=13, a[7]=19, a[8]=23, a[9]=29, a[10]=31;
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		if(n==2 || n==3 || n==5){
			puts("YES");
			continue;
		}
		if(isPrime())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
} 
