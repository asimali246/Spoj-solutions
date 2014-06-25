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

int n, x;
char a, b, z;

int main(){
    while(1){
        scanf("%c%ce%c", &a, &b, &z);
        getchar();
        if(a=='0' && b=='0')
            break;
        n=0;
        n=a-'0';
        n*=10;
        n+=b-'0';
        n*=(int)pow(10, z-'0');
        x=(int)pow(2, (int)(log(n)/log(2)));
        printf("%d\n", (n%x)*2+1);
    }
    return 0;
}
