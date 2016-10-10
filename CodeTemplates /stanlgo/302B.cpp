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
typedef unsigned long long int ull;

int main()
{
	int n,k;
	cin >> n >> k ;
	int max;
	if(n%2 == 0)
	{
		max = (n*n)/2 ;
		if(k > max)
		cout << "NO" << endl ;
		else
		{
			cout << "YES" << endl ;
			fr(i,0,n)
			{
				fr(j,0,n)
				{
				if(i%2 == 0 && j%2==0 && k > 0)
				{
					cout << "L" ;
					k-- ;
				}
				else if(i%2 == 1 && j%2==1 && k > 0)
				{
					cout << "L" ;
					k-- ;
				}
				else
					cout << "S" ;
			}
			cout << endl ;
		}
	}	
	}
	if(n%2 != 0)
	{
		max = (n*n)/2 + 1 ;
		if(k > max)
		cout << "NO" << endl ;
		else
		{
			cout << "YES" << endl ;
			fr(i,0,n)
			{
				fr(j,0,n)
				{
				if(i%2 == 0 && j%2==0 && k > 0)
				{
					cout << "L" ;
					k-- ;
				}
				else if(i%2 == 1 && j%2==1 && k > 0)
				{
					cout << "L" ;
					k-- ;
				}
				else
					cout << "S" ;
			}
			cout << endl ;
		}
	}	
	}
	
	return 0;
}