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

int t, i, l, a, b;
char s[444], ch;
vector<char> v;
stack<char> st;

int priority(char c){
    if(c=='+')
        return 1;
    if(c=='-')
        return 2;
    if(c=='*')
        return 3;
    if(c=='/')
        return 4;
    if(c=='^')
        return 5;
    return 0;
}


int main(){
    scanf("%d", &t);
    getchar();
    while(t--){
        gets(s);
        l=(int)strlen(s);
        v.clear();
        st=stack<char>();
        for(i=0;i<l;++i){
            if(s[i]>=97 && s[i]<=122)
                v.push_back(s[i]);
            else
            if(s[i]=='(')
                st.push('(');
            else
            if(s[i]==')'){
                while(1){
                    ch=st.top();
                    st.pop();
                    if(ch=='(')
                        break;
                    v.push_back(ch);
                }
            }
            else{
                a=priority(s[i]);
                if(st.empty())
                    b=-1;
                else
                    b=priority(st.top());
                if(a>b)
                    st.push(s[i]);
                else{
                    while(b>=a){
                        ch=st.top();st.pop();
                        v.push_back(ch);
                        if(st.empty())
                            b=-1;
                        else
                            b=priority(st.top());
                    }
                    st.push(s[i]);
                }
            }
        }
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        for(i=0;i<(int)v.size();++i)
            putchar(v[i]);
        putchar('\n');
    }
    return 0;
}
