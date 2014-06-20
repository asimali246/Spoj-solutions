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

int a[1010], n, ans;

int sum(int n){
    int ans=0;
    while(n!=0){
        ans+=(n%10)*(n%10);
        n/=10;
    }
    return ans;
}
int main(){
    scanf("%d", &n);
    ans=0;
    while(1){
        n=sum(n);
        if(!a[n])
            a[n]=1, ans++;
        else{
            if(n==1)
                break;
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}
