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

int t, n, k, dp[1<<13][100];

int solve(int mask, int sum){
    if(mask==(1<<n)-1){
        if(sum==k)
            return 1;
        return 0;
    }
    if(dp[mask][sum]!=-1)
        return dp[mask][sum];
    dp[mask][sum]=0;
    for(int i=0;i<n;++i){
        if(mask & (1<<i))
            continue;
        int c=0;
        for(int j=i+1;j<n;++j)
            if(mask & (1<<j))
                ++c;
        dp[mask][sum]+=solve(mask|(1<<i), sum+c);
    }
    return dp[mask][sum];
}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        memset(dp, -1, sizeof dp);
        printf("%d\n", solve(0, 0));
    }
    return 0;
}
