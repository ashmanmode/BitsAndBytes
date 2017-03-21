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

double dp[2001][2001];

int main()
{
	ull test,n;
	cin >> test;
	fr(t,0,test)
	{
		ull n,m;
		cin >> n >> m ; 

		int x=n;
		int y=m;
		fr(i,1,n)
		{
			fr(j,0,min(m,i-1))
			{
				if(i==1&&j==0)
					dp[i][j]=((double)(n))/(n+m);
				else if(j==0)
					dp[i][j]=dp[i-1][j]*((double)(n-i+1))/(n-i+1+m);
				else
				{
					dp[i][j]=dp[i][j-1]*((double)m-j+1)/(m-j+1+n-i);
					if(j!=i-1)
						dp[i][j]+=dp[i-1][j]*((double)n-i+1)/(m-j+1+n-i);	
				}
			}
		}

		cout << "Case #" << t+1 << ": " << fixed <<  setprecision(12) << dp[n][m] << endl;
	}
	return 0;
}