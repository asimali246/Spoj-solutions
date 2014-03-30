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
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> dd;
typedef pair<char, int> ci;

ll i, n;
map<ll, int> mp;
ll a[500010];

int main()
{
    mp.clear();
    mp[0]=0;
    for(i=1;i<=500000;++i)
    {
        if(a[i-1]-i>0 && mp.count(a[i-1]-i)==0)
            mp[a[i-1]-i]=1, a[i]=a[i-1]-i;
        else
            mp[a[i-1]+i]=1, a[i]=a[i-1]+i;
    }
    while(1)
    {
        scanf("%lld", &n);
        if(n==-1)
            break;
        printf("%lld\n", a[n]);
    }
    return 0;
}
