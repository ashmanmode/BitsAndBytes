//FB-01
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
	int n ,s ;
	cin >> n >> s ;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	bool skip = false;
	int brocken = 0 ; 
	for(int i = 0 ;i<n;i++)
	{
		if(a[i] <= s)
			brocken++ ; 
		else if(!skip)
			skip = true;
		else
			break;
	}
	cout << brocken << endl ;
}
