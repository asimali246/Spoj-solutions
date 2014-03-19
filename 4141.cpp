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

int t, n, ans, i;

int solve(int n)
{
    for(i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            ans/=i;
            ans*=(i-1);
            while(n%i==0)
                n/=i;
        }
    }
    if(n>1)
        ans/=n, ans*=(n-1);
    return ans;
}
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        ans=n;
        printf("%d\n", solve(n));
    }
    return 0;
}
