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

int t, f, e, w, W[510], P[510], dp[10010], i, j, n;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &e, &f);
        w=f-e;
        scanf("%d", &n);
        for(i=1;i<=n;++i)
            scanf("%d %d", &P[i], &W[i]);
        dp[0]=0;
        for(i=1;i<=w;++i){
            dp[i]=-1;
            for(j=1;j<=n;++j)
                if(i>=W[j] && dp[i-W[j]]!=-1 && (dp[i]==-1 || P[j]+dp[i-W[j]]<dp[i]))
                    dp[i]=P[j]+dp[i-W[j]];
        }
        if(dp[w]==-1)
            puts("This is impossible.");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[w]);
    }
    return 0;
}
