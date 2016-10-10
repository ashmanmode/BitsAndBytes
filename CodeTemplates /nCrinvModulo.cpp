//Graph Implementation with BFS,DFS,TopoSort
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

ull power(ull a,ull b)
{
	if(b==0)
		return 1;
	ull ans = power(a,b/2);
	if(b%2==0)
		return (ans*ans)%mod;
	else
		return (((ans*ans)%mod)*a)%mod;
	return ans ;
}

ull binomialCoeff(ull n, ull k)
{
    ull C[n+1][k+1];
    ull i, j;
 
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
 
    return C[n][k];
}

int main()
{
	int n,r;
	cin >> n >> r ;

	vector<ull> factorials(n+1);
	vector<ull> invFactorials(n+1);
	factorials[0] = 1 ; 
	fr(i,1,n+1)
		factorials[i] = (factorials[i-1]*i)%mod ; 

	//Inverse modulo
	invFactorials[n] = (ull)(power(factorials[n],mod-2))%mod ;
	for(int i=n-1;i>=0;i--)
		invFactorials[i] = (invFactorials[i+1]*(i+1))%mod ;

	cout << "Answer " << binomialCoeff(n,r) << endl;
	cout << (((factorials[n]*invFactorials[r])%mod)*invFactorials[n-r])%mod << endl ;
	return 0;
}