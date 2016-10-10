//Normal Segment tree
#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
#define point pair<int,int>
#define pii pair<int,int>
#define pib pair<int,bool>
#define vectin(a,n)
typedef unsigned long long int ull;

int t[123456][50] ;
int a[123456];
int n ;

int fun(int a,int b)
{
	return a+b ;
}

void build()
{
	fr(i,0,n)
		t[i][0] = a[i] ;
	for(int j = 1 ; j < log2(n)+1 ; j++ )
		for(int i = 0 ; i < n ; i += pow(2,j) )
			t[i][j] = fun( t[i][j-1], t[i+(int)pow(2,j-1)][j-1] );
}

void set(int x,int v)
{
	t[x][0] = v ; 
	for(int j = 1 ; j < log2(n) ; j++ )
	{
		int index = x - ( x&(pow(2,y)-1) ) ; 
		t[index][j] = fun(t[index][j-1] + t[index+(int)pow(2,j-1)][j-1] ) ;
	}
}

int get(int x,int y)
{
	
}

int main()
{
	cin >> n ; 
	fr(i,0,n)
		cin >> a[i] ;

	build();
	fr(i,0,log2(n)+1)
	{
		fr(j,0,n)
			cout << t[j][i] << " " ;
		cout << endl ;
	}
}