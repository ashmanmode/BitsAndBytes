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
	int n ,k; 
	cin >> n >> k ; 
	vector<int> a(n);
	fr(i,0,n)
		cin >> a[i] ;

	multiset< pair<int,int> > vals;
	fr(i,0,k)
		vals.insert(mp(a[i],i));

	int curMax = vals.end().S ;

	for (std::multiset< pair<int,int> >::iterator it=vals.begin(); it!=vals.end(); ++it)
	    std::cout << ' ' << (*it).F;
	std::cout << '\n';
	
	return 0;
}