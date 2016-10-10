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
#define pib pair<int,bool>
typedef unsigned long long int ull;

int main()
{
	int n,w; 
	cin >> n ;
	vector<int> vert;
	fr(i,0,n)
	{
		cin >>  w ;
		vert.pb(w);
	} 
	vector<int> dp(n+1);
	dp[0] = 0 ;
	dp[1] = vert[0];
	fr(i,2,n+1)
	{
		dp[i] = max(dp[i-1],dp[i-2]+vert[i-1]) ;
		cout << dp[i] << endl;
	}
	//cout << dp[n] << endl ;
	return 0;		
}