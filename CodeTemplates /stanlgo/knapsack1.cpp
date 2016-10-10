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

//container
vector<psll> bag;
vector< map<sll,sll> > dp;

sll knap(sll i,sll j)
{
	if(i == 0)
		return 0;
	else if(dp[i].find(j) != dp[i].end())
		return dp[i][j];

	sll val,dp1,dp2;
	if(dp[i-1].find(j) == dp[i-1].end())
		dp1 = knap(i-1,j);
	else
		dp1 = dp[i-1][j];

	if(dp[i-1].find(j-bag[i-1].S) == dp[i-1].end())
		dp2 = knap(i-1,j-bag[i-1].S);
	else
		dp2 = dp[i-1][j-bag[i-1].S];

	if(j-bag[i-1].S >= 0)
		val = max(dp1,dp2 + bag[i-1].F);
	else
		val = dp1;
	return val;
}

int main()
{
	sll n,W,v,w;
	cin >> W >> n ; 
	fr(i,0,n)
	{
		cin >> v >> w ;
		bag.pb(mp(v,w));
	}
	
	//DP Knapsack 1 
	map<sll,sll> lst;
	fr(i,0,n+1)
		dp.pb(lst);

	cout << knap(n,W) << endl ;
	return 0;		
}