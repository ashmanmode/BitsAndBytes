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
#define arr vector<int> 
#define vectin(a,n) fr(i,0,n) { cin >> a[i] ; }
typedef unsigned long long int ull;

int main()
{
	int a,b,n,l,t,m;
	cin >> a >> b >> n ;

	fr(i,0,n)
	{
		cin >> l >> t >> m ;
		int vall = a + (l-1)*b ;
		if(t < vall)
			cout << -1 << endl ;
		else
		{
			
		}
	}
}