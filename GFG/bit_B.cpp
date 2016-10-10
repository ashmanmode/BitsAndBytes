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
	int n,m;
	cin >> n >> m ;
	vector<int> a(2*n);
	fr(i,0,n)
		cin >> a[i];
	fr(i,0,n)
		cin >> a[i+n];
	sort(a.begin(),a.end());

	int rooms = 0 ;
	int i=0;
	while(m > 0)
	{
		m -= a[i];
		i++;
		rooms++;
	}
	if(m<0)
		rooms--;
	cout << min(rooms,n) << endl ;
    return 0;
}