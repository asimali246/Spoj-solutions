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

struct Node{
    int br, bl, bs, s;
};

const int N = 50010;
int i, n, m, a[N], op, x, y;
Node t[5*N];

void build(int id, int l, int r){
    if(l==r){
        t[id].bl=t[id].br=t[id].bs=t[id].s=a[l];
        return;
    }
    int m=(l+r)>>1;
    build(id*2, l, m);
    build(id*2+1, m+1, r);
    t[id].bl=max(t[id*2].bl, t[id*2+1].bl+t[id*2].s);
    t[id].br=max(t[id*2].br+t[id*2+1].s, t[id*2+1].br);
    t[id].s=t[id*2].s+t[id*2+1].s;
    t[id].bs=max(t[id*2].br+t[id*2+1].bl, max(t[id*2].bs, t[id*2+1].bs));
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
    else{
        Node p, q, res;
        p=query(id*2, l, m, a, m);
        q=query(id*2+1, m+1, r, m+1, b);
        res.bl=max(p.bl, q.bl+p.s);
        res.br=max(q.s+p.br, q.br);
        res.s=p.s+q.s;
        res.bs=max(p.br+q.bl, max(p.bs, q.bs));
        return res;
    }
}
void update(int id, int l, int r, int p, int v){
    if(l==r && l==p){
        t[id].bl=t[id].br=t[id].bs=t[id].s=v;
        return;
    }
    int m=(l+r)>>1;
    if(p<=m)
        update(id*2, l, m, p, v);
    else
    if(p>m)
        update(id*2+1, m+1, r, p, v);
    t[id].bl=max(t[id*2].bl, t[id*2+1].bl+t[id*2].s);
    t[id].br=max(t[id*2].br+t[id*2+1].s, t[id*2+1].br);
    t[id].s=t[id*2].s+t[id*2+1].s;
    t[id].bs=max(t[id*2].br+t[id*2+1].bl, max(t[id*2].bs, t[id*2+1].bs));
}
int main(){
    scanf("%d", &n);
    for(i=1;i<=n;++i)
        scanf("%d", &a[i]);
    build(1, 1, n);
    scanf("%d", &m);
    while(m--){
        scanf("%d %d %d", &op, &x, &y);
        if(op)
            printf("%d\n", query(1, 1, n, x, y).bs);
        else
            update(1, 1, n, x, y);
    }
    return 0;
}
