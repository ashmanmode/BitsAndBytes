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
		int a,b,c,p,q,m;
		cin >> a >> b >> c ;
		vector<ull> vecA(a);
		vector<ull> vecB(b);
		vector<ull> vecC(c);
		fr(i,0,a)
			cin >> vecA[i];
		fr(i,0,b)
			cin >> vecB[i];
		fr(i,0,c)
			cin >> vecC[i]; 

		//Second Prods
		map<double,ull> map;
		fr(i,0,b)
		{
			fr(j,0,c)
				map[vecB[i]*vecC[j]] = vecB[i] ; 
		}

		cin >> m ;
		cout << "Case #" << t+1 << ": " << endl ;
		fr(k,0,m)
		{
			cin >> p >> q ;
			bool isit = false;
			fr(i,0,a)
			{
				fr(j,0,b)
				{
					double val = (q*vecA[i]*vecB[j])/p  ; 
					if( map.find(val) != map.end() )
					{
						if(map[val] != vecB[j] )
						{
							//cout << val << " " << vecA[i] << " " << vecB[j] << endl ;
							isit = true;
						}
					}

				}
			}
			if(isit)
				cout << "Yes" << endl ;
			else
				cout << "No" << endl ;
		}

	}
	return 0;
}