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

const int N = 1<<14;
int tt, n, u, v, c, i, j, pr[N][16], fin[N], fout[N], T, pv[N], t[5*N], de[N], ch_pos[N], z;
int end[N], ptr, ch_head[N], a[N], pos[N], ch_num, ch_ind[N], sub_size[N], vis[N], ch_size[N];
char s[101];
vector<ii> g[N];
vector<int> edge_ind[N];

void build(int id, int l, int r) {
	if( l == r ) {
		t[id] = a[l];
		return;		
	}
	int m = (l + r) >> 1;
	build( id<<1, l, m );
	build( (id<<1) | 1, m + 1, r );
	t[id] = max( t[id<<1], t[(id<<1) | 1] );
}

int query(int id, int l, int r, int a, int b) {
	if( a > b )
		return 0;
	if( l == a && r == b ) {
		return t[id];
	}
	int m = ( l + r ) >> 1;
	if(b <= m)
		return query( id<<1, l, m, a, b );
	else
	if(a > m)
		return query( (id<<1) | 1, m+1, r, a, b );
	else
		return max( query(id<<1, l, m, a, m), query((id<<1) | 1, m+1, r, m+1, b) );
}

void update( int id, int l, int r, int p, int v ) {
	if( l == r && l == p ) {
		t[id] = v;
		return;
	}
	int m = ( l + r ) >> 1;
	if( p <= m )
		update( id<<1, l, m, p, v );
	else
		update( (id<<1) | 1, m + 1, r, p, v );
	t[id] = max( t[id<<1], t[(id<<1) | 1] );
}

void dfs( int u ) {
	vis[u] = 1;
	sub_size[u] = 1;
	fin[u] = T++;
	for( int j=0; j < (int)g[u].size(); ++j ) {
		ii v = g[u][j];
		if( !vis[v.first] ) {
			dfs( v.first );
			pv[v.first] = u;
			end[edge_ind[u][j]] = v.first;
			sub_size[u] += sub_size[v.first];
			de[v.first] = de[u]+1;
		}
	}
	fout[u] = T++;
}

void HLD(int u, int cost) {
	if( ch_head[ch_num] == -1 )
		ch_head[ch_num] = u;
	ch_ind[u] = ch_num;
	ch_pos[u] = ch_size[ch_num];
	ch_size[ch_num]++;
	pos[u] = ptr;
	a[ptr++] = cost;
	vis[u] = 1;
	
	int mx = -1, ind = -1;
	for(int j=0; j < (int)g[u].size(); ++j) {
		if(!vis[g[u][j].first] && sub_size[g[u][j].first] > mx)
			mx = sub_size[g[u][j].first], ind = j;
	}
	if(ind >= 0)
		HLD(g[u][ind].first, g[u][ind].second);
	for(int j=0; j < (int)g[u].size(); ++j) { 
		if( !vis[ g[u][j].first ]  && j != ind ) {
			ch_num++;
			HLD( g[u][j].first, g[u][j].second );
		}	
	}
}

inline bool anc( int x, int y) {
	return ((fin[x] <= fin[y]) && (fout[y] <= fout[x]));
}

inline int lca(int x, int y) {
	if( anc(x, y) )
		return x;
	for( j=14; j>=0; --j )
		if( !anc( pr[x][j], y ) )
			x=pr[x][j];
	return pv[x];
}

inline int query_up(int u, int v) {
	if(u == v)
		return 0;
	int ans = 0, u_ch, v_ch;
	v_ch = ch_ind[v];
	while(1) {
		u_ch = ch_ind[u];
		if(u_ch == v_ch){
			if( u == v )
				break;
			ans = max(ans, query(1, 1, n, pos[v]+1, pos[u]));
			break;
		}
		ans = max(ans, query(1, 1, n, pos[ch_head[u_ch]], pos[u]));
		u = ch_head[u_ch];
		u = pv[u];
	}
	return ans;
}

inline int answer(int u, int v){
	if(de[u] > de[v])
		swap(u, v);
	z=lca(u, v);
	int ans;
	ans=query_up(u, z);
	ans=max(ans, query_up(v, z));
	return ans;
}

inline void change(int i, int c) {
	u = end[i];
	update(1, 1, n, pos[u], c);
}

int main(){
	scanf("%d", &tt);
	while(tt--) {
		scanf("%d", &n);
		ch_num = T = 1;
		for(i=1; i<=n; ++i)
			g[i].clear(), vis[i] = 0, edge_ind[i].clear(), ch_head[i] = -1, ch_size[i] = 1;
		for(i=1; i<=n-1; ++i) {
			scanf("%d %d %d", &u, &v, &c);
			g[u].push_back(ii(v, c));
			g[v].push_back(ii(u, c));
			edge_ind[u].push_back(i);
			edge_ind[v].push_back(i);
		}
		getchar();
		ptr = 1;
		de[1] = 0, pv[1] = 1;
		dfs(1); // Find the parent, subsize, and finishing time of nodes.
		
		for(i=1; i<=n; ++i)
			pr[i][0] = pv[i], vis[i] = 0;
		
		HLD(1, -1); //root, cost ( Construct hld for tree)
		build(1, 1, n); // Construct segment tree
		//Construct LCA

		for( j=1; j<=14; ++j )
			for( i=1; i<=n; ++i )
				pr[i][j] = pr[pr[i][j-1]][j-1];

		while(1){
			scanf("%s", s);
			if(s[0] == 'D')
				break;
			if(s[0] == 'Q'){
				scanf("%d %d", &u, &v);
				printf("%d\n", answer(u, v));
			}
			else{
				scanf("%d %d", &i, &c);
				change(i, c);
			}
			getchar();
		}
	}
	return 0;
}
