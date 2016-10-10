#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
#define point pair<int,int>
#define pii pair<int,int>
#define pib pair<int,bool>
#define arr vector<int> 
#define vectin(a,n) fr(i,0,n) { cin >> a[i] ; }
typedef unsigned long long int ull;

int main()
{
	int n,cpy;
	cin >> n ;
	cpy = n ;

	int size = 0 ;
	while(cpy > 0 )
	{
		size++ ; 
		cpy /= 10 ;
	}

	ull ans = 2*(pow(2,size-1) - 1) ; 

	int bit ;
	fr(i,0,size)
	{
		bit = 0 ;
		if(n%10 == 7)
			bit = 1 ;
		ans += bit*(pow(2,i));
		n /= 10 ;
	}
	cout << ans +1  << endl ;
}