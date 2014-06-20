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
double ans, a, b, c, d, X, x, Y, y, Z, z, U, V, W, u, v, w;
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%lf %lf %lf %lf %lf %lf", &U, &W, &v, &V, &w, &u);
        X=(w-U+v)*(U+v+w);
        x=(U-v+w)*(v-w+U);
        Y=(u-V+w)*(V+w+u);
        y=(V-w+u)*(w-u+V);
        Z=(v-W+u)*(W+u+v);
        z=(W-u+v)*(u-v+W);
        a=sqrt(x*Y*Z);
        b=sqrt(y*Z*X);
        c=sqrt(z*X*Y);
        d=sqrt(x*y*z);
        ans=sqrt((-a+b+c+d)*(a-b+c+d)*(a+b-c+d)*(a+b+c-d))/(192.0*u*v*w);
        printf("%.4lf\n", ans);
    }
    return 0;
}
