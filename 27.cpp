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

struct Node
{
    int a, b, c, d, e, f;
};
int t, n, i, ans;
vector<Node> v;
bool blank=false;
bool cmp(Node a, Node b)
{
    if(a.a!=b.a)
        return a.a<b.a;
    if(a.b!=b.b)
        return a.b<b.b;
    if(a.c!=b.c)
        return a.c<b.c;
    if(a.d!=b.d)
        return a.d<b.d;
    if(a.e!=b.e)
        return a.e<b.e;
    return a.f<=b.f;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        v.clear();
        scanf("%d", &n);
        Node temp;
        for(i=1;i<=n;++i)
        {
            scanf("%d %d %d %d %d %d", &temp.a, &temp.b, &temp.c, &temp.d, &temp.e, &temp.f);
            v.push_back(temp);
        }
        if(blank)
            putchar('\n');
        blank=true;
        sort(v.begin(), v.end(), cmp);
        ans=1;
        for(i=1;i<(int)v.size();++i)
        {
            if(v[i-1].a!=v[i].a || v[i-1].b!=v[i].b || v[i-1].c!=v[i].c || v[i-1].d!=v[i].d || v[i-1].e!=v[i].e || v[i-1].f!=v[i].f)
            {
                printf("%02d %08d %04d %04d %04d %04d %d\n", v[i-1].a, v[i-1].b, v[i-1].c, v[i-1].d, v[i-1].e, v[i-1].f, ans);
                ans=1;
            }
            else
                ++ans;
        }
        i--;
        printf("%02d %08d %04d %04d %04d %04d %d\n", v[i].a, v[i].b, v[i].c, v[i].d, v[i].e, v[i].f, ans);
    }
    return 0;
}
