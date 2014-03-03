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

int t, a, b, i, j, low;
bitset<100011> bs, res;
vi primes;
bool blank;

int main()
{
	bs.set();
	bs[1]=0;
	primes.clear();
	for(i=2;i<=100000;++i)
	{
		if(bs[i])
		{
			for(j=i+i;j<=100000;j+=i)
				bs[j]=0;
			primes.push_back(i);
		}
	}
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &a, &b);
		res.set();
		if(blank)
			putchar('\n');
		blank=true;
		if(b<=100000)
		{
			for(i=a;i<=b;++i)
				if(bs[i])
					printf("%d\n", i);
				continue;
		}
		for(i=0;i<(int)primes.size();++i)
		{
			if(primes[i]>a)
				break;
			low=primes[i]-a%primes[i];
			if(low==primes[i])
				low=0;
			for(j=low+1;j<=b-a+1;j+=primes[i])
				res[j]=0;
		}
		for(i=1;i<=b-a+1;++i)
			if(res[i])
			{
				printf("%d\n", i+a-1);
			}
	}
	return 0;
}
