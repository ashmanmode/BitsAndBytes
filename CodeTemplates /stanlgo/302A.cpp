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
typedef unsigned long long int ull;

int main()
{
	int k,m,r;
	string s;
	cin >> k >> s ;
	bool c[26];
	fr(i,0,26)
		c[i] = false;

	vector< vector<char> > st;
	vector<char> temp; 
	for(m=0;m< s.length();m++)
	{
		if(!c[(int)(s[m])-97])
		{
			c[(int)(s[m])-97] = true ;
			st.pb(temp);
			temp.clear();
			k--;
			if(k==0)
			{
				r = m ;
				break;
			}
		}
		temp.pb(s[m]) ;
	}
	if(k!=0)
		cout << "NO" << endl ;
	else
	{
		cout << "YES" << endl ; 
		fr(i,1,st.size())
		{
			fr(j,0,st[i].size())
				cout << st[i][j] ;
			cout << endl;
		}
		fr(j,r,s.length())
			cout << s[j] ;
		cout << endl ;
				
	}
}