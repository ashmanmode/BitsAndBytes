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
		ull n,k,x;
		cin >> n >> k ;
		vector<ull> a(n);
		vector<ull> b(n);
		vector<ull> c(n);
		vector<ull> d(n);
		vector<ull> e;
		map<ull,ull> mymap;
		fr(i,0,n)
			cin >> a[i] ;
		fr(i,0,n)
			cin >> b[i] ;
		fr(i,0,n)
			cin >> c[i] ;
		fr(i,0,n)
			cin >> d[i] ;
		fr(i,0,n)
		{
			fr(j,0,n)
				e.pb(a[i]^b[j]);
		}
		fr(i,0,n)
		{
			fr(j,0,n)
			{
				x = c[i]^d[j];
				if(mymap.find(x)==mymap.end())
					mymap[x] = 1;	
				else
					mymap[x]++;
			}
		}	
		ull count = 0 ;
		fr(i,0,e.size())
		{
			ull val = e[i]^k;
			if(mymap.find(val)!=mymap.end())
				count+=mymap[val];
		}
		cout << "Case #" << t+1 << ": " << count << endl;
	}
	return 0;
}