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

int t;
double a, b, c, d, s;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
        s=(a+b+c+d)/2.0;
        printf("%.2lf\n", (double)sqrt((s-a)*(s-b)*(s-c)*(s-d)));
    }
    return 0;
}
