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

vector<int> getMult(int s,int n)
{
	vector<int> a(n);
	int current = 0 ;

	a[n-1] = current ;
	int i = n-2;
	while(s!=0 || i >= 0)
	{
		if(s%2==1) //+
			current = 0 ;
		else //No +
			++current;
		a[i] = current  ;
		i--;
		s /= 2;
	}
	return a;
}


int main()
{
	string s;
	cin >> s ;
	vector<int> a(s.length());

	fr(i,0,s.length())
		a[i] = (int)(s[i]-'0') ; 

	ull total = 0;
	fr(i,0,pow(2,s.length()-1))
	{
		ull tmp = 0 ;
		vector<int> curr = getMult(i,s.length());
		fr(j,0,s.length())
			tmp += a[j]*pow(10,curr[j]);
		total += tmp;
	}
	cout << total << endl ;
}