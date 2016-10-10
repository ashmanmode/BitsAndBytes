#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define mod 1000000007
#define F first
#define S second
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%llu",&a)
#define pi(a) printf("%d",a)
#define pl(a) printf("%llu",a)
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << fixed << a[i] << " " ;
typedef unsigned long long int ull;

bool myfunction (pair<int,string> i,pair<int,string> j) 
{
	if(i.F==j.F)
		return (i.S<j.S);
 	return (i.F>j.F); 
}

int minimum (int i,int j) 
{
	if(i< j)
		return i;
	return j;
}

int main()
{
	ull test;
	cin >> test;
	fr(t,0,test)
	{
		int p;
		cin >> p ;
		vector<int> s(p) ;
		fr(i,0,p)
			cin >> s[i] ;
		int n,w;
		cin >> n;
		map< string,vector<int> > players;
		string name;
		fr(i,0,n)
		{
			cin >> w ;
			fr(j,0,p)
			{
				cin >> name ;
				if(players.find(name) == players.end())
				{
					//cout << "adding player " << name << endl;
					vector<int> scores;
					scores.pb(s[j]*w);
					players[name] = scores ;
				}
				else
				{
					//cout << "same player " << name << endl; 
					players[name].pb(s[j]*w);
				}
			}
		}	
		int m;
		cin >> m ;

		vector<pair<int,string> > final;
		for (std::map<string,vector<int> >::iterator it=players.begin(); it!=players.end(); ++it)
		{
			//std::cout << it->first << '\n';	
			sort(players[it->first].begin(),players[it->first].end());
			int sum = 0 ;
			for(int i=0;i<minimum(m,players[it->first].size());i++)
				sum += players[it->first][i] ;
			final.pb(mp(sum,it->first));
		}

		sort(final.begin(),final.end(),myfunction);
		cout << "Case #" << t+1 << ": "<< endl;
		int currentScore = -1 ;
		int currentRank = 0 ;
		fr(i,0,final.size())
		{
			if(currentScore != final[i].F)
			{
				cout << i+1 << ": " << final[i].S << endl ;
				currentRank = i+1 ;
			}
			else
				cout << currentRank << ": " << final[i].S << endl ;
			currentScore = final[i].F ;
		}
	}
	return 0;
}