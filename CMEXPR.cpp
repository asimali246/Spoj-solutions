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
#include <cassert>
#include <stdint.h>
#include <unistd.h>

using namespace std;

#define ll long long int
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9


template < typename X > X gcd( X a, X b ) { if( !b ) return a ; else return gcd(b, a%b) ; }

typedef vector<int> vi ;
typedef pair<int, int> ii ;

struct Node {
	char ch ;
	Node *left ;
	Node *right ;
} ;

Node *root ;
const int N = 333 ;
int t, i, l ;
stack<char> st ;
char s[N], ch ;
vector<char> P ;
vector<string> ans ;
stack<Node*> stm ;

void MakeTree() {
	stm = stack<Node*>() ;
	for( i = 0; i < (int) P.size(); ++i ) {
		Node *temp ;
		if( islower( P[i] ) ) {
			temp = new Node() ;
			temp -> ch = P[i] ;
			temp -> left = NULL ;
			temp -> right = NULL ;
			stm.push( temp ) ;
		} else {
			temp = new Node() ;
			temp -> ch = P[i] ;
			Node *First = stm.top() ; stm.pop() ;
			Node *Second = stm.top() ; stm.pop() ;
			temp -> left = Second ;
			temp -> right = First ;
			stm.push( temp ) ;
		}
	}
	root = stm.top() ; stm.pop() ;
}

void Print( Node *trav ) {
	ch = trav -> ch ;
	int flag ;
	char nch ; 
	switch(ch) {
		case '+':
			Print( trav -> left ) ;
			putchar('+') ;
			Print( trav -> right ) ;
			break ;
		case '-':
			Print( trav -> left ) ;
			putchar('-') ;
			nch = trav -> right -> ch ;
			flag = 0 ;
			if( nch == '+' || nch == '-' ) 
				flag = 1 ;
			if( flag ) 
				putchar('(') ;
			Print( trav -> right ) ;
			if( flag ) 
				putchar(')') ;
			break ;
		case '*':
			nch = trav -> left -> ch ;
			flag = 0 ;
			if( nch == '+' || nch == '-' ) 
				flag = 1 ;
			if( flag ) 
				putchar('(') ;
			Print( trav -> left ) ;
			if( flag ) 
				putchar(')') ;
			putchar('*') ;
			nch = trav -> right -> ch ;
			flag = 0 ;
			if( nch == '+' || nch == '-' ) 
				flag = 1 ;
			if( flag ) 
				putchar('(') ;
			Print( trav -> right ) ;
			if( flag ) 
				putchar(')') ;
			break ;
		case '/': 
			nch = trav -> left -> ch ;
			flag = 0 ;
			if( nch == '+' || nch == '-' ) 
				flag = 1 ;
			if( flag ) 
				putchar('(') ;
			Print( trav -> left ) ;
			if( flag ) 
				putchar(')') ;
			putchar('/') ;
			nch = trav -> right -> ch ;
			flag = 1 ;
			if( islower(nch) )
				flag = 0 ;
			if( flag ) 
				putchar('(') ;
			Print( trav -> right ) ;
			if( flag )
				putchar(')') ;
			break ;
		default:
			putchar(ch) ;
	}
}
int Priority( char ch ) {
	switch(ch) {
		case '+':
			return 1 ;
		case '-':
			return 1 ;
		case '*':
			return 2 ;
		case '/':
			return 2 ;
	}
	return 0 ;
}
int main() {
	scanf("%d", &t) ;
	while( t-- ) {
		scanf("%s", s ) ;
		l = (int) strlen( s ) ;
		st = stack<char>() ;
		P.clear() ;
		for( i = 0; i < l; ++i ) {
			if( islower(s[i]) ) {
				P.push_back( s[i] ) ;
			} else
			if( s[i] == '(' ) {
				st.push( s[i] ) ;
			} else 
			if( s[i] == ')' ) {
				while( true ) {
					ch = st.top() ; st.pop() ;
					if( ch == '(' ) 
						break ;
					P.push_back( ch ) ;
				}
			} else {
				int a = Priority( s[i] ) ;
				int b ;
				if( st.empty() ) 
					b = -1 ;
				else
					b = Priority( st.top() ) ;
				while( a <= b ) {
					ch = st.top() ; st.pop() ;
					P.push_back( ch ) ;
					if( st.empty() ) 
						b = -1 ;
					else
						b = Priority( st.top() ) ;
				}
				st.push( s[i] ) ;
			}
		}
		while( !st.empty() ) {
			ch = st.top() ; st.pop() ;
			P.push_back( ch ) ;
		}
		MakeTree() ;
		Print( root ) ;
		putchar('\n') ;
	}
	return 0 ;
}
