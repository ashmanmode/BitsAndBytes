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
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
#define pii pair<int,int>
#define pll pair<ull,ull>
#define psll pair<sll,sll>
#define pib pair<int,bool>
typedef unsigned long long int ull;
typedef signed long long int sll;

int main()
{
	sll n,W,v,w;
	cin >> W >> n ; 
	vector<psll> bag;
	fr(i,0,n)
	{
		cin >> v >> w ;
		bag.pb(mp(v,w));
	}
	
	//DP Knapsack 1 
	vector< vector<sll> > dp;
	vector<sll> lst(W+1);
	fr(i,0,n+1)
		dp.pb(lst);

	fr(i,0,W+1)
		dp[0][i] = 0 ;
	fr(i,1,n+1)
	{
		fr(j,0,W+1)
		{
			//cout << j-bag[i-1].S << " ";
			if(j-bag[i-1].S >= 0)
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-bag[i-1].S] + bag[i-1].F);
			else
				dp[i][j] = dp[i-1][j];
		}
		//cout << endl ;
	}
	fr(i,0,n+1)
	{
		fr(j,0,W+1)
		cout << dp[i][j] << " ";
		cout << endl ;		
	}
	cout << dp[n][W] << endl ;
	return 0;		
}