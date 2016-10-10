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
		int n,l1,r1,a,b,c1,c2,m,x,y,newx,newy;
		cin >> n >> l1 >> r1 >> a >> b >> c1 >> c2 >> m; 

		vector<ull> ls;
		vector<ull> rs;
		ls.pb(l1);
		rs.pb(r1);
		x  = l1 ; 
		y = r1 ;
		fr(i,1,n)
		{
			newx = (a*x+b*y+c1)%m;
			newy = (a*y+b*x+c2)%m;
			ls.pb(min(newx,newy));
			rs.pb(max(newx,newy));
			x = newx ; y = newy;
		}
		fr(i,0,n)
			cout << "( " << ls[i] << " , " << rs[i] << " ) " << endl; 
		cout << "Case #" << t+1 << ": " <<  "hjb" << endl ;
	}
	return 0;
}