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
		string a;
		cin >> a;

		int flip_points = 0 ;
		char prev = a[0]; 
		fr(i,1,a.length())
		{
			if(a[i] != prev)
				flip_points++;
			prev = a[i];
		}
		if(a[a.length()-1]=='-')
			flip_points++;
		cout << "Case #" << t+1 << ": " << flip_points << endl;
	}
	return 0;
}