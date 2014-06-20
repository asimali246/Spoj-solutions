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

int n, a[2010], dp[2010][2010], i, j;

int solve(int l, int r, int d){
    if(l==r)
        return a[l]*d;
    if(dp[l][r]!=-1)
        return dp[l][r];
    return dp[l][r]=max(a[l]*d+solve(l+1, r, d+1), a[r]*d+solve(l, r-1, d+1));
}
int main(){
    scanf("%d", &n);
    for(i=1;i<=n;++i)
        scanf("%d", &a[i]);
    memset(dp, -1, sizeof dp);
    printf("%d\n", solve(1, n, 1));
    return 0;
}
