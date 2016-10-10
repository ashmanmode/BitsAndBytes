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

ull acker(ull m,ull n)
{
	if(m == 0 )
		return n+1 ;
	else if(m > 0 && n==0)
		return acker(m-1,1);
	else 
		return acker(m-1,acker(m,n-1));
}

int main()
{
	ull a,b;
	cin >> a >> b ;
	cout << acker(a,b) << endl ;
}