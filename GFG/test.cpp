#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define frr(i,k,n) for(int i = k ; i >= n ; i-- )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
#define point pair<int,int>
#define pii pair<int,int>
#define pib pair<int,bool>
#define arr vector<int> 
#define vectin(a,n) fr(i,0,n) { cin >> a[i] ; }
typedef unsigned long long int ull;
typedef long long int ll;



int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);

	string num = "0000000011";
	ll sol = bitset<40>(num).to_ulong();
	cout << bitset<40>(num) << " " << sol << endl ;	
	return 0;
}