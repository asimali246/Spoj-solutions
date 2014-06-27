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

int t, la, lb, a[1010], b[1010], i, ans, j;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &la);
        for(i=1;i<=la;++i)
            scanf("%d", &a[i]);
        scanf("%d", &lb);
        for(i=1;i<=lb;++i)
            scanf("%d", &b[i]);
        sort(a+1, a+la+1);
        sort(b+1, b+lb+1);
        ans=INF, i=j=1;
        while(i<=la && j<=lb){
            ans=min(ans, abs(a[i]-b[j]));
            if(a[i]<=b[j])
                ++i;
            else
                ++j;
        }
        printf("%d\n", ans);
    }
    return 0;
}
