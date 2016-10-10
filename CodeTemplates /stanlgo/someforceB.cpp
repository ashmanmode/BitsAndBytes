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

int main()
{
	int n,k;
	cin >> n ; 
	map<int, vector<int> > m;
	fr(i,0,n)
	{
		cin >> k ; 
		m[k].pb(i+1);
	}

	//find max
	int max = 0; 
	int num = 0;
	int prevsize ;
	for (std::map<int, vector<int> >::iterator it=m.begin(); it!=m.end(); ++it)
	{
		if(it->second.size() > max)
		{
			max = it->second.size() ;
			num = it->first ;
			prevsize = it->second[it->second.size()-1] - it->second[0] ;
		}
		else if(it->second.size() == max )
		{
			if( it->second[it->second.size()-1] - it->second[0] < prevsize )
			{
				max = it->second.size() ;
				num = it->first ;
				prevsize = it->second[it->second.size()-1] - it->second[0] ;
			}
		}
    	//std::cout << it->first << " => " << it->second.size() << '\n';
    }
    cout << m[num][0] << " " << m[num][m[num].size()-1] << endl; 
	return 0;
}