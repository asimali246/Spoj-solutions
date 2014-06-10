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

int n, t, T[55][55], cs[55][55], i, j;
ii dp[55][1200];

ii go(int u, int l)
{
    if(l<0)
        return ii(INF, INF);
    if(u==n)
        return ii(0, 0);
    if(dp[u][l]!=ii(-1, -1))
        return dp[u][l];
    ii ans=ii(INF, INF);
    for(int j=1;j<=n;++j)
        if(j!=u)
        {
            ii temp=go(j, l-T[u][j]);
            if(temp.first+cs[u][j]<ans.first)
            {
                ans.first=temp.first+cs[u][j];
                ans.second=temp.second+T[u][j];
            }
        }
    return dp[u][l]=ans;
}

int main()
{
    while(1)
    {
        scanf("%d %d", &n, &t);
        if(!n && !t)
            break;
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
                scanf("%d", &T[i][j]);
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
                scanf("%d", &cs[i][j]);
        memset(dp, -1, sizeof dp);
        ii ans=go(1, t);
        printf("%d %d\n", ans.first, ans.second);
    }
    return 0;
}
