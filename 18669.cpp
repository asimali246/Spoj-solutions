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
 
 using namespace std;
 
#define ll long long int
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> dd;
typedef pair<char, int> ci;

void mul(long long &x, int i, long long md) {
  long long res = 0;
  while (i > 0) {
    if (i & 1) {
      res += x;
      if (res >= md) res -= md;
    }
    i >>= 1;
    x <<= 1;
    if (x >= md) x -= md;
  }
  x = res;
}
 
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    long long b;
    cin >> n >> b;
    long long x = 1;
    for (int i = 2; i <= n; i++) mul(x, i, 2 * b);
    if (x >= b) puts("Odd");
    else puts("Even");
  }
  return 0;
}
