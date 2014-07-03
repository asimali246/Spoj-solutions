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

int t, a, b, i, l;
char x[111], y[111];

int Value(char s[]){
	int ans=0;
	for(i=0;i<l;++i){
		if(s[i]=='m')
			if(i==1)
				ans+=(s[0]-'0')*1000;
			else
				ans=1000;
		if(s[i]=='c')
			if(s[i-1]>=48 && s[i-1]<=57)
				ans+=(s[i-1]-'0')*100;
			else
				ans+=100;
		if(s[i]=='x')
			if(s[i-1]>=48 && s[i-1]<=57)
				ans+=(s[i-1]-'0')*10;
			else
				ans+=10;
		if(s[i]=='i')
			if(s[i-1]>=48 && s[i-1]<=57)
				ans+=(s[i-1]-'0');
			else
				ans+=1;
	}
	return ans;
}
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s %s", x, y);
		a=b=0;
		l=(int)strlen(x);
		a=Value(x);
		l=(int)strlen(y);
		b=Value(y);
		a+=b;
		if(a/1000!=0)
			if(a/1000>1)
				printf("%dm", a/1000);
			else
				printf("m");
		a%=1000;
		if(a/100!=0)
			if(a/100>1)
				printf("%dc", a/100);
			else
				printf("c");
		a%=100;
		if(a/10!=0)
			if(a/10>1)
				printf("%dx", a/10);
			else
				printf("x");
		a%=10;
		if(a!=0)
			if(a>1)
				printf("%di", a);
			else
				printf("i");
		putchar('\n');
	}
	return 0;
}
