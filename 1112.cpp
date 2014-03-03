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
 
 using namespace std;
 
#define ll long long int
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> dd;
typedef pair<char, int> ci;

int t, x, y, i;
int ansy[10010], ansx[10010];
bool flag, xx;

int main()
{
	scanf("%d", &t);
	flag=true;
	xx=true;
	ansy[0]=0, ansx[1]=-1;
	for(i=1;i<=10000;++i)
	{
		if(flag)
			ansy[i]=ansy[i-1]+1, flag=false;
		else
			ansy[i]=ansy[i-1]+3, flag=true;
		if(i>=2)
		{
			if(xx)
				ansx[i]=ansx[i-1]+3, xx=false;
			else
				ansx[i]=ansx[i-1]+1, xx=true;
		}
	}
	while(t--)
	{
		scanf("%d %d", &x, &y);
		if(x==y)
			printf("%d\n", ansy[x]);
		else
		if(x==y+2)
			printf("%d\n", ansx[x]);
		else
			printf("No Number\n");
	}
	return 0;
}
