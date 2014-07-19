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

int t, i, j, l, c, flag;
map<string, int> mp;
char s[15], x[15];

int main(){
	scanf("%d", &t);
	getchar();
	while(t--){
		scanf("%s", s);
		l=(int)strlen(s);
		mp.clear();
		for(i=0;i<l;++i){
			c=0;
			for(j=i;j<l;++j)
				x[c++]=s[j], x[c]='\0', mp[x]=1;
		}
		flag=1;
		for(i=l-1;i>=0;--i){
			c=0;
			for(j=i;j>=0;--j){
				x[c++]=s[j], x[c]='\0';
				if(mp.count(x)==0)
					flag=0;
				if(!flag)
					break;
			}
			if(!flag)
				break;
		}
		if(flag)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
