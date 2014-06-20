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

int h, w, i, j, ans, t;
int dp[111][111];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &h, &w);
        memset(dp, 0, sizeof dp);
        for(i=1;i<=h;++i)
            for(j=1;j<=w;++j)
                scanf("%d", &dp[i][j]);
        for(i=2;i<=h;++i){
            for(j=1;j<=w;++j)
                dp[i][j]=dp[i][j]+max(max(dp[i-1][j], dp[i-1][j-1]), dp[i-1][j+1]);
        }
        ans=-INF;
        for(j=1;j<=w;++j)
            ans=max(dp[h][j], ans);
        printf("%d\n", ans);
    }
    return 0;
}
