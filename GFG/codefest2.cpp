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
	string s;
	ull n;
	cin >> s >> n ;

	ull k = n ; 
	fr(i,0,s.length())
	{
		if( k >= (int)('z'-s[i])+1 )
		{
			k = k - (int)('z'-s[i]) - 1 ;
			s[i] = 'a';
		}
		cout << s << k << endl ;
	}
	
	int a = (int)(s[s.length()-1]-'a') ;  
	a = (a+k%26)%26 ;
	s[s.length()-1] = (char)('a'+a) ;
	cout << s << endl ;
}