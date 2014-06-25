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

int n, i, a[55];

int main(){
    scanf("%d", &n);
    if(n==0){
        printf("0\n");
        return 0;
    }
    i=1;
    while(n!=0){
        a[i]=n%-2;
        n/=-2;
        if(a[i]<0)
            a[i]+=2, n++;
        ++i;
    }
    for(i=i-1;i>=1;--i)
        printf("%d", a[i]);
    putchar('\n');
    return 0;
}
