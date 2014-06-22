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

int n, a[111], sum[111][111], dp[111][111], i, j;

int solve(int x, int y){
    if(x==y)
        return 0;
    if(y==x+1)
        return a[x]*a[y];
    if(dp[x][y]!=-1)
        return dp[x][y];
    for(int i=x;i+1<=y;++i)
        if(dp[x][y]==-1)
            dp[x][y]=sum[x][i]*sum[i+1][y]+solve(x, i)+solve(i+1, y);
        else
            dp[x][y]=min(dp[x][y], sum[x][i]*sum[i+1][y]+solve(x, i)+solve(i+1, y));
    return dp[x][y];
}

int main(){
    while(scanf("%d", &n)!=EOF){
        for(i=1;i<=n;++i)
            scanf("%d", &a[i]), sum[i][i]=a[i];
        for(i=1;i<=n;++i)
            for(j=i+1;j<=n;++j)
                sum[i][j]=sum[i][j-1]+a[j], sum[i][j]%=100;
        memset(dp, -1, sizeof dp);
        printf("%d\n", solve(1, n));
    }
    return 0;
}
