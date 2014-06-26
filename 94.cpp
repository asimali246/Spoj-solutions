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

int n, i, l, c, j;
ll ans, x, a[11], ss;
char s[20];

int main(){
    while(1){
        scanf("%d", &n);
        getchar();
        if(!n)
            break;
        ans=0;
        for(i=1;i<=n;++i){
            gets(s);
            ss=c=0;
            l=(int)strlen(s);
            s[l]=' ';
            for(j=0;j<=l && s[j]!='S';++j)
                if(s[j]=='.')
                    ++c;
                else
                if(s[j]==' '){
                    if(c)
                        ss+=c, c=0;
                    else
                        ss+=5;
                }
            a[i]=ss;
        }
        getchar();
        x=1;
        for(i=n;i>=1;--i){
            ans+=(x*a[i]), x*=20;
            if(x==400)
                x=360;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
