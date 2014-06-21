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

struct Node{
    int bl, br, s, bs;
};

const int N = 50010;
int n, a[N], i, m, x, y;
Node t[5*N];

void build(int id, int l, int r){
    if(l==r){
        t[id].bl=t[id].br=t[id].s=t[id].bs=a[l];
        return;
    }
    int m=(l+r)>>1;
    build(id*2, l, m);
    build(id*2+1, m+1, r);
    t[id].bl=max(t[id*2].bl, t[id*2+1].bl+t[id*2].s);
    t[id].br=max(t[id*2+1].br, t[id*2].br+t[id*2+1].s);
    t[id].s=t[id*2].s+t[id*2+1].s;
    t[id].bs=max(max(t[id*2].bs, t[id*2+1].bs), t[id*2].br+t[id*2+1].bl);
}
Node query(int id, int l, int r, int a, int b){
    if(l==a && r==b)
        return t[id];
    int m=(l+r)>>1;
    if(b<=m)
        return query(id*2, l, m, a, b);
    else
    if(a>m)
        return query(id*2+1, m+1, r, a, b);
    else
    {
        Node x=query(id*2, l, m, a, m);
        Node y=query(id*2+1, m+1, r, m+1, b);
        Node res;
        res.s=x.s+y.s;
        res.bl=max(x.bl, y.bl+x.s);
        res.br=max(x.br+y.s, y.br);
        res.bs=max(max(x.bs, y.bs), x.br+y.bl);
        return res;
    }
}
int main(){
    scanf("%d", &n);
    for(i=1;i<=n;++i)
        scanf("%d", &a[i]);
    build(1, 1, n);
    scanf("%d", &m);
    while(m--){
        scanf("%d %d", &x, &y);
        printf("%d\n", query(1, 1, n, x, y).bs);
    }
    return 0;
}
