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

int t, n, m;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        if(m>=n)
            if(n%2)
                printf("R\n");
            else
                printf("L\n");
        else{
            if(m%2)
                printf("D\n");
            else
                printf("U\n");
        }
    }
    return 0;
}
