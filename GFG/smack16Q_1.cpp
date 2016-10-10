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
	int n;
	cin >> n ; 
	fr(i,0,n)
	{
		int k;
		cin >> k ;
		vector<int> a(k+1); 
		vector<int> b(k); 
		a[0] = 0;
		fr(j,1,k+1)
			cin >> a[j];
		fr(j,0,k)
			cin >> b[j];

		int count = 0 ;
		fr(j,0,k)
		{
			if(b[j] <= (a[j+1]-a[j]))
				count++;
		}
		cout << count << endl ;
	}
}
