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

int t, n, ans, x, y, i;
int a[11], b[11];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        for(i=1;i<=n;++i)
            scanf("%d", &x), a[x]++;
        for(i=1;i<=n;++i)
            scanf("%d", &x), b[x]++;
        for(i=10;i>=0;--i)
            if(a[i])
            {
                x=i;
                break;
            }
        for(i=10;i>=0;--i)
            if(b[i])
            {
                y=i;
                break;
            }
        ans=0;
        while(1)
        {
            if(!x && !y)
                break;
            if(a[x]<=b[y])
                ans+=a[x]*(x*y), b[y]-=a[x], a[x]=0;
            else
                ans+=b[y]*(x*y), a[x]-=b[y], b[y]=0;
            while(!a[x] && x>0)--x;
            while(!b[y] && y>0)--y;
        }
        printf("%d\n", ans);
    }
    return 0;
}
