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
#define EPS 1e-15

template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}

typedef vector<int> vi;
typedef pair<int, int> ii;

int t, WX, WY, WZ, XY, XZ, YZ;
double Vol,r,S,u, v, w, U, V, W, A1, A2, A3, A4, sum;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d %d %d %d", &WX, &WY, &WZ, &XY, &XZ, &YZ);
		u = WX;
		U = YZ;
		v = WY;
		V = XZ;
		w = WZ;
		W = XY;
		Vol = sqrt(4*u*u*v*v*w*w - u*u*(v*v+w*w-U*U)*(v*v+w*w-U*U) - v*v*(w*w+u*u-V*V)*(w*w+u*u-V*V) - w*w*(u*u+v*v-W*W)*(u*u+v*v-W*W) + (v*v+w*w-U*U)*(w*w+u*u-V*V)*(u*u+v*v-W*W))/12;
		sum = (WX+WY+XY)/2.0;
		A1 = sqrt(sum * (sum - WX) * (sum - WY) * (sum - XY));
		sum = (WZ+WY+YZ)/2.0;
		A2 = sqrt(sum * (sum - WZ) * (sum - WY) * (sum - YZ));
		sum = (WZ+WX+XZ)/2.0;
		A3 = sqrt(sum * (sum - WZ) * (sum - WX) * (sum - XZ));
		sum = (XY+YZ+XZ)/2.0;
		A4 = sqrt(sum * (sum - XZ) * (sum - XY) * (sum - YZ));
		S = A1+A2+A3+A4;
		r = (Vol*3)/S;
		printf("%.4lf\n", r);
	} 
	return 0;
} 
