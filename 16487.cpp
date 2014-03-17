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
 
#define MAX 10010
int t, n, u, q, l, r, val;
int tree[MAX];

void update(int idx, int val)
{
    while(idx<=n)
    {
        tree[idx]+=val;
        idx+=(idx&(-idx));
    }
}
int read(int idx)
{
    int sum=0;
    while(idx>0)
        sum+=tree[idx], idx-=(idx & (-idx));
    return sum;
}
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &u);
        memset(tree, 0, sizeof tree);
        while(u--)
        {
            scanf("%d %d %d", &l, &r, &val);
            ++l, ++r;
            update(l, val);
            update(r+1, -val);
        }
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d", &l);
            ++l;
            printf("%d\n", read(l));
        }
    }
    return 0;
}
