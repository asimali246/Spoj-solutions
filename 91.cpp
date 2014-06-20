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

int t, flag, c, prime[100100], l, j;
ll n, i, x;
bitset<1000010> bs;

int main(){
    bs.reset();
    l=1;
    for(i=3;i<=1000000;++i){
        if(!bs[i]){
            prime[l++]=i;
            for(j=i+i;j<=1000000;j+=i)
                bs[j]=1;
        }
    }
    --l;
    scanf("%d", &t);
    while(t--){
        flag=0;
        scanf("%lld", &n);
        while(n%2==0 && n)
            n/=2;
        for(i=1;i<=l;++i){
            if(prime[i]>n)
                break;
            c=0;
            while(n%prime[i]==0)
                n/=prime[i], c++;
            if(prime[i]%4==3 && c%2!=0){
                printf("No\n");
                flag=1;
                break;
            }
        }
        if(n>1 && n%4==3 && !flag){
            printf("No\n");
            continue;
        }
        if(!flag)
            printf("Yes\n");
    }
    return 0;
}
