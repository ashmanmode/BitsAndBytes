#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define F first
#define S second
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%llu",&a)
#define pi(a) printf("%d",a)
#define pl(a) printf("%llu",a)
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
typedef unsigned long long int ull;
typedef pair<int,int> pii;

bool comp1(pii a,pii b)
{
	int c = a.F-a.S ;
	int d = b.F-b.S ;
	if( c == d )
		return a.F > b.F ;
	return c > d ;
}

bool comp2(pii a,pii b)
{
	double c = (double)a.F/(double)a.S ;
	double d = (double)b.F/(double)b.S ;
	return c > d ;
}

int main()
{
	ull n,w,l; 
	cin >> n ;
	vector<pii> lst; 
	fr(i,0,n)
	{
		cin >> w >> l ;
		lst.pb(mp(w,l));
	}
	sort(lst.begin(),lst.end(),comp2);
	ull ans = 0 ;
	ull ft = lst[0].S;
	fr(i,0,n)
	{
		ans += lst[i].F * ft ;
		ft += lst[i+1].S ;
	}
	cout << ans << endl ;
}