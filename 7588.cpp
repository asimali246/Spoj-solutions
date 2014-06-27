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

int n, m, i, j, dp[111][111], f[111][111], ans;

int solve(int p, int b){
    if(p>n)
        return 0;
    if(dp[p][b]!=-1)
        return dp[p][b];
    int ans=INF;
    if(b-1>=1)
        ans=min(f[p][b-1]+solve(p+1, b-1), f[p][b]+solve(p+1, b));
    else
        ans=f[p][b]+solve(p+1, b);
    if(b+1<=m)
        ans=min(ans, f[p][b+1]+solve(p+1, b+1));
    return dp[p][b]=ans;
}
int main(){
    scanf("%d %d", &n, &m);
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            scanf("%d", &f[i][j]), dp[i][j]=-1;
    ans=INF;
    for(i=1;i<=m;++i)
        ans=min(ans, solve(1, i));
    printf("%d\n", ans);
    return 0;
}
