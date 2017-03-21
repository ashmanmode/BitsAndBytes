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
	int n,d,s;
	cin >> n;
	vector< pair<int,int> > data;

	for(int i=0;i<n;i++)
	{
		cin >> s >> d ;
		data.pb(mp(d,s));
	}

	sort(data.begin(),data.end());

	int sol = 0 ; 
	map<int,bool> cities;
	int duplicate = 0 ;
	int city = 0 ;
	for(int i=0;i<n;i++)
	{
		if(cities.find(data[i].S)==cities.end())
		{
			city++; cities[data[i].S] = true;
			sol += city*data[i].F;
		}
		else
			duplicate += data[i].F;
	}

	sol += city*duplicate ;
	cout << sol << endl ;
}