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

int p, d, i, l;
map<string, int> mp;
char s[44], t[5];

int main(){
    scanf("%d", &p);
    mp["TTT"]=mp["TTH"]=mp["THT"]=mp["THH"]=mp["HTT"]=mp["HTH"]=mp["HHT"]=mp["HHH"]=0;
    while(p--){
        scanf("%d", &d);
        scanf("%s", s);
        t[3]='\0';
        l=(int)strlen(s);
        t[0]=s[0];
        t[1]=s[1];
        mp["TTT"]=mp["TTH"]=mp["THT"]=mp["THH"]=mp["HTT"]=mp["HTH"]=mp["HHT"]=mp["HHH"]=0;
        for(i=2;i<l;++i){
            t[2]=s[i];
            mp[t]+=1;
            t[0]=t[1], t[1]=t[2];
        }
        map<string, int>::reverse_iterator it=mp.rbegin();
        printf("%d", d);
        while(it!=mp.rend())
            printf(" %d", it->second), ++it;
        putchar('\n');
    }
    return 0;
}
