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

int lcs( string X, string Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;
  
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + (int)(X[i-1]-'0');
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
    
   return L[m][n];
}

int getsum(string a)
{
	int sum = 0 ; 
	fr(i,0,a.length())
		sum += (int)(a[i]-'0');
	return sum;
}

int main()
{
	int test;
	cin >> test ;
	while(test--)
	{
		string str1,str2;
		cin >> str1 >> str2 ;
	 
	   	int maxVal = lcs( str1 , str2 , str1.length(), str2.length()) ;

	   	int sum1 = getsum(str1);
	   	int sum2 = getsum(str2);
	    cout << sum1 - maxVal + sum2 - maxVal << endl ;	
	}
}