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

int t, dp[6200][6200], i, l, j;
char s[6200];

int solve(int l, int r){
    if(l>r)
        return 0;
    if(l==r)
        return 0;
    if(dp[l][r]!=-1)
        return dp[l][r];
    if(s[l]!=s[r])
        return dp[l][r]=min(1+solve(l, r-1), 1+solve(l+1, r));
    else
        return dp[l][r]=solve(l+1, r-1);
}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%s", s);
        l=(int)strlen(s);
        for(i=0;i<l;++i)
            for(j=i;j<l;++j)
                dp[i][j]=-1;
        printf("%d\n", solve(0, l-1));
    }
    return 0;
}
