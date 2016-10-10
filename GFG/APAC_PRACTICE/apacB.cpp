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
	ull test;
	cin >> test;
	fr(t,0,test)
	{
		int n;
		cin >> n ;
		long double k,p;
		long double gminF = 0;
		long double gmaxF = LDBL_MAX;
		long double ans = -1 ;
		fr(i,0,n)
		{
			cin >> p >> k ;
			gminF = max(gminF,(k*100)/(p+1)); 
			gmaxF = min(gmaxF,(k*100)/(p)); 
			if(p==100)
				ans = k;
		}
		if(ans != -1)
		{
			cout << "Case #" << t+1 << ": " << ans << endl;
			continue;
		}
		if( ((ceil(gminF)==gminF)&&(gminF+1==floor(gmaxF))) || ((ceil(gminF)!=gminF)&&(ceil(gminF)==floor(gmaxF))) )
			cout << "Case #" << t+1 << ": " << fixed << 	floor(gmaxF) << endl;
		else
			cout << "Case #" << t+1 << ": " << -1 << endl;
	}
	return 0;
}