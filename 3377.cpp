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

const int N = 2010;
int t, n, e, i, x, y, flag, cs=1, v, j;
vi g[N], vis;
queue<int> q;
map<int, int> dist;

void check(int u){
    q.push(u);
    dist[u]=1;
    while(!q.empty()){
        v=q.front();q.pop();
        for(j=0;j<(int)g[v].size();++j){
            x=g[v][j];
            if(dist.count(x)==0){
                dist[x]=1-dist[v];
                vis[x]=1;
                q.push(x);
            }
            else
            if(dist[x]==dist[v])
                flag=1;
        }
    }
}

int main(){
    scanf("%d", &t);
    vis.clear(), vis.assign(N, 0);
    while(t--){
        scanf("%d %d", &n, &e);
        dist.clear();
        for(i=1;i<=n;++i)
            g[i].clear(), vis[i]=0;
        while(e--){
            scanf("%d %d", &x, &y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        flag=0;
        for(i=1;i<=n;++i)
            if(vis[i]==0){
                check(i);
                if(flag)
                    break;
            }
        if(flag)
            printf("Scenario #%d:\nSuspicious bugs found!\n", cs++);
        else
            printf("Scenario #%d:\nNo suspicious bugs found!\n", cs++);
    }
    return 0;
}
