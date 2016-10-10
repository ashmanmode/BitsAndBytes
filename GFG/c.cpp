//FB-01
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

char a = '0';
char b = '0';

int lps(string str)
{
   int n = str.length();
   int i, j, cl;
   int L[n][n];  // Create a table to store results of subproblems
   vector<bool> temp(n);
   fr(i,0,n)
   		temp[i] = false;
 
 
    // Strings of length 1 are palindrome of lentgh 1
    for (i = 0; i < n; i++)
       L[i][i] = 1;
 
    for (cl=2; cl<=n; cl++)
    {
        for (i=0; i<n-cl+1; i++)
        {
            j = i+cl-1;
            if (str[i] == str[j] && cl == 2)
               L[i][j] = 2;
            else if (str[i] == str[j])
            {
               L[i][j] = L[i+1][j-1] + 2;
               temp[i] = true;
               temp[j] = true;
           	}
            else
            {
               L[i][j] = max(L[i][j-1], L[i+1][j]);
               if(L[i][j-1] > L[i+1][j])
               	temp[j] = true ;
               else
               	temp[i] = true ;
           }
        }
    }

    cout << "print " << endl ;
    fr(i,0,n)
    {
    	fr(j,0,n)
    	{
    		if(L[i][j] <= n && L[i][j] > 0)
    			cout << L[i][j] << " " ;
    		else
    			cout << 0 << " ";
    	}
    	cout << endl ;
    }
 	cout << endl ;

 	printvect(temp,temp.size());
 	cout << endl ;

    return L[0][n-1];
}
 
int main()
{
	int n;
	cin >> n ;
	string a,b;
	fr(i,0,n)
	{
		cin >> a >> b; 
		int lena = lps(a) ;
		int lenb = lps(b) ;

		cout << lena << " " << lenb << endl ;
		if(lena%2==1 && lenb%2==1)
			cout << lena+lenb-1 << endl ;
		else
			cout << lena+lenb << endl ;
	}
}
