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

ull divi(ull n,ull b)
{
	// cout << n << " " << b << " " ;
	int ans = 0; 
	int mult = 1;
	while(n >= mult)
	{
		if(n==mult)
		{
			// cout << ans << endl ;
			return ans;
		}
		mult = b*mult;
		ans++;
	}
	return -1;
}

ull get(ull n)
{
	int max_i = 0;
	int max_n = 0;
	for(int i=2;i<=n;i++)
	{
		ull bn = n*(i-1) + 1;
		ull a = divi(bn,i);
		if(a!=-1)
		{
			// cout << bn << " " << i << " " << a << " " << max_n<< endl ; 
			if(max_n < a)
			{
				max_n = a;
				max_i = i;
				// cout << "In " << max_n << " " << max_i << endl ;
			}
		}
	}
	return max_i;
}

int main()
{
	ull test;
	cin >> test;
	fr(t,0,test)
	{	
		ull n;
		cin >> n;

		cout << "Case #" << t+1 << ": "  ;
		cout << get(n) << endl;
	}
	return 0;
}