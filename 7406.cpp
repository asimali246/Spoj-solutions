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

int n, i;
ll a;
map<int, int> mp;

int main(){
    a=1;
    i=1;
    while(1){
        mp[a]=1;
        a+=6*i;
        ++i;
        if(a>1000000000)
            break;
    }
    while(1){
        scanf("%d", &n);
        if(n==-1)
            break;
        if(mp.count(n)==0)
            putchar('N');
        else
            putchar('Y');
        putchar('\n');
    }
    return 0;
}
