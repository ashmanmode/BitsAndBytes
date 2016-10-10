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
		string a;
		cin >> a ;
		if(a.length()==1)
		{
			cout << "Case #" << t+1 << ": " << 1 << endl;
			continue;
		}
		ull count = 1 ;
		if(a[0]!=a[1])
			count*=2;
		if(a[a.length()-1]!=a[a.length()-2])
			count*=2;

		fr(i,1,a.length()-1)
		{
			if(a[i-1]==a[i] && a[i]==a[i+1] && a[i-1]==a[i+1])
				count = (count * 1)%mod ;
			else if(a[i-1]==a[i] && a[i]!=a[i+1] && a[i-1]!=a[i+1])
				count = (count * 2)%mod;
			else if(a[i-1]!=a[i] && a[i]==a[i+1] && a[i-1]!=a[i+1])
				count = (count * 2)%mod;
			else if(a[i-1]!=a[i] && a[i]!=a[i+1] && a[i-1]==a[i+1])
				count = (count * 2)%mod;
			else 
				count = (count * 3)%mod;
		}
		cout << "Case #" << t+1 << ": " << count << endl;

	}
	return 0;
}