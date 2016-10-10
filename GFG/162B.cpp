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
	int n ;
	cin >> n ;
	arr a(n);
	vectin(a,n);

	ull total = 2*n - 1 ;
	int cur = 0 ;

	fr(i,0,n)
	{
		total += (a[i] - cur);
		if(a[i+1] >= a[i])
			cur = a[i];
		else if(a[i+1] < a[i] && i != n-1)
		{
			total += (a[i] - a[i+1]);
			cur = a[i+1];
		}
	}
	cout << total << endl ;
}