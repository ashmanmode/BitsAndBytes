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
		string s;
		cin >> s;
		ull a,b;
		cin >> a >> b;
		a--;b--;
		ull n = s.length();
		ull count = 0 ;
		// a = a/n + 1;
		// b = b/n + 1;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='B')
				count++;
		}
		unsigned long long int ans = count*(b/n-a/n-1);
		// cout << b << " " << a << endl;
		// cout << a%n << " " << b%n << endl ;
		for(int i=a%n;i<n;i++)
		{
			if(s[i]=='B')
				ans++;
		}
		for(int i=0;i<=b%n;i++)
		{
			if(s[i]=='B')
				ans++;
		}
		cout << "Case #" << t+1 << ": " <<  ans << endl ;
	}
	return 0;
}