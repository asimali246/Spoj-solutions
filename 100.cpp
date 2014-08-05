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
#define EPS 1e-15

template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}

typedef vector<int> vi;
typedef pair<int, int> ii;

int n, i, j, ans, dp[333], tmp[5];
vector<pair<ii, int> > v;

void process(){
	v.push_back(make_pair(ii(tmp[2], tmp[1]), tmp[0]));
	v.push_back(make_pair(ii(tmp[1], tmp[0]), tmp[2]));
	v.push_back(make_pair(ii(tmp[2], tmp[0]), tmp[1]));
}
bool cmp(pair<ii, int> a, pair<ii, int> b){
	if(a.first.first == b.first.first)
		return a.first.second > b.first.second;
	return a.first.first > b.first.first;
}
int main(){
	while(1){
		scanf("%d", &n);
		if(!n)
			break;
		v.clear();
		for(i=1;i<=n;++i)
			scanf("%d %d %d", &tmp[0], &tmp[1], &tmp[2]), sort(tmp, tmp+3), process();
		sort(v.begin(), v.end(), cmp);
		ans=0;
		for(i=0;i<n*3;++i){
			dp[i]=v[i].second;
			for(j=0;j<i;++j){
				if(v[j].first.first>v[i].first.first && v[j].first.second>v[i].first.second)
					dp[i]=max(dp[i], dp[j]+v[i].second);
			}
			ans=max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
