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

const int N = 10010;
int n, x, y, i, mx, s, dist[N];
vector<int> g[N];
bool vis[N];

void dfs(int u){
    vis[u]=true;
    for(int j=0;j<(int)g[u].size();++j){
        int v=g[u][j];
        if(!vis[v]){
            dist[v]=dist[u]+1;
            if(dist[v]>mx){
                mx=dist[v];
                s=v;
            }
            dfs(v);
        }
    }
}
int main(){
    scanf("%d", &n);
    for(i=1;i<=n;++i)
        g[i].clear();
    for(i=1;i<=n-1;++i){
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for(i=1;i<=n;++i)
        vis[i]=false, dist[i]=0;
    mx=0;
    dfs(s);
    printf("%d\n", mx);
    return 0;
}
