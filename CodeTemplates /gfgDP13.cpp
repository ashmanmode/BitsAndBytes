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

vector<int> l;
vector<int> v;

ull findA(ull u,ull v)
{
	if(u==v)
		return v[0];
	else 
	{
		int max = 0 ;
		fr(i,0,(v-u+1)/2)
		{
			
		}
	}
}

int main()
{
	ull n,x,y;
	cin >> n ;
	fr(i,0,n)
	{
		cin >> x ;
		l.pb(x);
	}
	fr(i,0,n)
	{
		cin >> x ;
		v.pb(x);
	}
	cout << findA(0,n-1) << endl ;
}