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

int dx[]={0, 1, 0, -1};
int dy[]={-1, 0, 1, 0};
int t, i, j, bt[190][190], vis[190][190], n, m, dist[190][190], x, y;
queue<pair<ii, int> > q; // BFS state=((r, c), distance)

bool valid(int x, int y){
    if(x<1 || x>n || y<1 || y>m)
        return false;
    if(vis[x][y])
        return false;
    return true;
}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d\n", &n, &m);
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
                vis[i][j]=0, dist[i][j]=INF;
        q=queue<pair<ii, int> >();
        for(i=1;i<=n;++i){
            for(j=1;j<=m;++j){
                bt[i][j]=getchar()-'0';
                if(bt[i][j]){
                    dist[i][j]=0;
                    vis[i][j]=1;
                    q.push(make_pair(make_pair(i, j), 0));
                }
            }
            getchar();
        }
        while(!q.empty()){
            pair<ii, int> temp=q.front();q.pop();
            x=temp.first.first, y=temp.first.second;
            for(i=0;i<4;++i)
                if(valid(x+dy[i], y+dx[i])){
                    vis[x+dy[i]][y+dx[i]]=1;
                    dist[x+dy[i]][y+dx[i]]=temp.second+1;
                    q.push(make_pair(make_pair(x+dy[i], y+dx[i]), temp.second+1));
                }
        }
        for(i=1;i<=n;++i){
            for(j=1;j<=m;++j){
                if(j>1)
                    putchar(' ');
                printf("%d", dist[i][j]);
            }
            putchar('\n');
        }
    }
    return 0;
}
