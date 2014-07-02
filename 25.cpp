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

int t, a, b, c, ans, p;

int solve(int x, int y, int z){
	ans=1;
	int a=x, b=0;
	while(a!=z && b!=z){
		p=min(a, y-b);
		a-=p, b+=p;
		++ans;
		if(a==z || b==z)
			break;
		if(a==0)
			ans++, a=x;
		if(b==y)
			ans++, b=0;
	}
	return ans;
}
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &a, &b, &c);
		if(c>a && c>b)
			printf("-1\n");
		else
		if(c%gcd(a, b)!=0)
			printf("-1\n");
		else
		if(c==a || c==b)
			printf("1\n");
		else
			printf("%d\n", min(solve(a, b, c), solve(b, a, c)));
	}
	return 0;
}
