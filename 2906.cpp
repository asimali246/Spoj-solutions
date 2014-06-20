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

int t, r, i, a;
char b[3333];
int rem(){
    i=r=0;
    for(;b[i];++i)
        r*=10, r+=b[i]-'0', r%=a;
    return r;
}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %s", &a, b);
        if(a==0)
            printf("%s\n", b);
        else
            printf("%d\n", gcd(a, rem()));
    }
    return 0;
}
