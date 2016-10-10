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
#define vectin(a,n)
typedef unsigned long long int ull;

struct me
{
	int i ;
	int l;
	int r;
	int q ;
};

bool sortfun(me a ,me b)
{
	return a.i < b.i ;
}

int main()
{
	int h,q;
	cin >> h >> q ;
	vector<me> data ;
	me temp;
	fr(i,0,q)
	{
		cin >> temp.i >> temp.l >> temp.r >> temp.q ;
		data.pb(temp);
	}
	sort(data.begin(),data.end(),sortfun);

	int curstart = 0 ;
	int curend = 0 ;
	fr(i,0,q)
	{
		cout << data[i].i << " " ;
		if(data[i].q == 1 )
		{
			curstart = pow(2,h-1) + ( data[i].l - pow(2,i-1) )*( pow(2,h-i) ) ;
			curend = pow(2,h-1) + ( data[i].v - pow(2,i-1) + 1 )*( pow(2,h-i) ) - 1 ;
		}
		else
		{
			
		}
	}

	return 0;
}