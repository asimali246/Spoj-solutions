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

int t, n, m, dp[2010][2010], i, j;
char a[2010], b[2010];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%s", a);
        scanf("%s", b);
        n=(int)strlen(a), m=(int)strlen(b);
        for(i=1;i<=m;++i)
            dp[i][0]=i*1;
        for(i=1;i<=n;++i)
            dp[0][i]=i*1;
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j){
                dp[i][j]=dp[i-1][j-1]+(a[i-1]==b[j-1]?0:1);
                dp[i][j]=min(dp[i][j], dp[i-1][j]+1);
                dp[i][j]=min(dp[i][j], dp[i][j-1]+1);
            }
        printf("%d\n", dp[n][m]);
    }
    return 0;
}
