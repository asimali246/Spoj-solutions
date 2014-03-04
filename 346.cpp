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

//BASIC DP VERY HAPPY DEVISED IT MYSELF. :)
int n;
map<int, ll> mp;

ll solve(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    if(mp.count(n))
        return mp[n];
    return mp[n]=max((ll)n, (ll)solve(n/2)+(ll)solve(n/3)+(ll)solve(n/4));
}
int main()
{
    mp.clear();
    while(scanf("%d", &n)!=EOF)
        printf("%lld\n", solve(n));
    return 0;
}
