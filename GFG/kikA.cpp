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

int main()
{
	ull test,n;
	cin >> test;
	fr(t,0,test)
	{
		ull r,c ;
		cin >> r >> c ;
		ull ans = 0;
		ull i=1;
		while(r-i>0&&c-i>0)
		{
			ans = ans+((((r-i)*(c-i))%mod)*i)%mod ;
			ans = ans%mod;
			i++;
		}
		cout << "Case #" << t+1 << ": " << ans << endl;
	}
	return 0;
}