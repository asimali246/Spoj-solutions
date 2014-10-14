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
#include <cassert>
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

int t, i ;
double ans, a, b, c;

double f( double v ) {
	double sum ;
	sum = a * v + b * sin(v) - c;
	return sum;
}

double fd(double v ) {
	double sum;
	sum = a + b * cos(v);
	return sum;
}

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%lf %lf %lf", &a, &b, &c);
		ans = 1.57;
		for( i = 1; i <= 100; ++i ) {
			ans = ans - (double) ( f(ans) / fd(ans) ) ;
		}
		printf("%.6lf\n", ans);
	}
	return 0;
}
