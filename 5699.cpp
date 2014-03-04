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

int t, a;
ll b;
char s[1010];

int solve(int base, ll p)
{
    int ans=1;
    while(p)
    {
        if(p&1)
            ans=(ans*base)%10;
        base=(base*base)%10;
        p>>=1;
    }
    return ans;
}
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", s);
        scanf("%lld", &b);
        a=s[(int)strlen(s)-1]-48;
        printf("%d\n", solve(a, b));
    }
    return 0;
}
