//Knuth–Morris–Pratt Algo to search for a substring in a string
#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
typedef unsigned long long int ull;

int main()
{
	string s,m;
	getline(std::cin,s);
	getline(std::cin,m);

	//precomputation of T array
	int t[m.length()+1];
	t[0] = -1 ; t[1] = 0 ;
	fr(i,2,m.length()+1) 
	{
		if( m[ t[i-1] ] == m[i-1] ) //if the letter at i is suffice to some substring
			t[i] = t[i-1] + 1 ;
		else
			t[i] = 0 ;
	}
	printvect(t,m.length()+1);
	cout << endl ;

	//search starts now
	int counter = 0 ;
	int k = 0 ; int i = 0 ;
	while(k+i < s.length())
	{
		counter++;
		if(s[k+i] == m[i])
		{
			if(i == m.length()-1)
			{
				cout << "Found at -> " << k << endl; 
				k = k + i - t[m.length()] + 1;
				i = t[m.length()];
			}
			else
				i++;
		}
		else
		{
			if(t[i] > -1)
			{
				k = k + i - t[i];
				i = t[i];
			}
			else
			{
				k++; i = 0 ;
			}
		}
	}
	cout << "steps " << counter << endl ;
	return 0;
}