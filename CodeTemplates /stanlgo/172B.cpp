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
	double x,y,n ;
	cin >> x >> y >> n ; 
	if(n >= y)
		cout << (int)x + "/" + (int)y << endl ;
	else
	{
		double i = n ;
		double j = 1 ;
		double min ;
		while(i > 1)
		{
			j = 1 ; 
			while(j <= i)
			{
				double diff = abs( j/i - x/y ); 
				cout << diff << "\t" ;
				j++ ;
			}
			i-- ;
			cout << endl ;
		}
	}
}