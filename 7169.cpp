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

int n, a, b, x, y, z, ans, i;
int main(){
    scanf("%d", &n);
    for(i=1;i<=n;++i){
        scanf("%d/%d", &a, &b);
        if(a==3)
            z++;
        else
        if(b==2)
            x++;
        else
            y++;
    }
    ans=1;
    ans+=(x/2);
    x=(x&1);
    if(y>=z && z!=0)
        ans+=z, y-=z, z=0;
    else
    if(z>=y && y!=0)
        ans+=y, z-=y, y=0;
    if(y){
        ans+=(y/4);
        if(x && y>=2)
            ans+=1, y-=2;
        if(y)
            ans++;
    }
    if(z){
        ans+=z;
        if(x)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}
