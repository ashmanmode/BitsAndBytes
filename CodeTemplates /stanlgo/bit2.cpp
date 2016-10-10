#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define maxsiz 1000000
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
typedef unsigned long long int ull;

ull dp[5002];
bool d[5002];

ull C[5002][5002];

void binomialCoeff()
{
    int n = 5000 ; 
    int k = 5000 ; 
    int i, j;
    // Caculate value of Binomial Coefficient in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;
 
            // Calculate value using previosly stored values
            else
                C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
        }
    }
}

ull comp(int n)
{
	ull sol  = 0 ;
	if(d[n]) return dp[n] ;
	
	for(int i = 1 ; i < n+1 ; i++ )
	{
		if(d[n-i])
			sol = ( sol + ( C[n][i]*dp[n-i] )%mod )%mod ;
		else
			sol = ( sol + ( C[n][i]*comp(n-i) )%mod )%mod ;
	}
	dp[n] = sol ; d[n] = true ;
	return dp[n] ;
}

int main()
{
	//pre
	dp[0] = 1 ; d[0] = true ;
	dp[1] = 1 ; d[1] = true ;
	dp[2] = 3 ; d[2] = true ;

	binomialCoeff();

	fr(i,3,5002) d[i] = false;
	int t;
	cin >> t ;
	while(t--)
	{
		int n ; cin >> n ; 
		cout << comp(n) << endl ;
	}
	return 0 ;
}