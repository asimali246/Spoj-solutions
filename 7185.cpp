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

int a[11], i, p, q, r, s, ans;

int main(){
    while(1){
        for(i=1;i<=8;++i)
            scanf("%d", &a[i]);
        if(a[1]==-1)
            break;
        ans=-INF;
        p=a[1]/a[5];
        ans=p;
        if(a[1]%a[5])
            ans++;
        q=a[2]/a[6];
        ans=max(ans, q+((a[2]%a[6])?1:0));
        r=a[3]/a[7];
        ans=max(ans, r+((a[3]%a[7])?1:0));
        s=a[4]/a[8];
        ans=max(ans, s+((a[4]%a[8])?1:0));
        printf("%d %d %d %d\n", ans*a[5]-a[1], ans*a[6]-a[2], ans*a[7]-a[3], ans*a[8]-a[4]);
    }
    return 0;
}
