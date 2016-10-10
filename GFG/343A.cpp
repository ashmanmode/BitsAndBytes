#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n ;

	int sol = 0 ;
	vector< vector<char>  > chock ; 
	for(int i = 0 ; i < n ; i++ )
	{
		vector<char> temp(n);
		int countc = 0 ;
		for(int j = 0 ;j< n;j++)
		{
			cin >> temp[j] ; 
			if(temp[j]=='C')
				countc++ ;
		}
		chock.push_back(temp);
		//cout << "row " << countc << endl ; 
		sol += (countc*(countc-1))/2 ;
	}

	for(int i = 0 ; i < n ; i++ )
	{
		int countc = 0 ;
		for(int j = 0 ;j< n;j++)
		{
			if(chock[j][i]=='C')
				countc++ ;
		}
		//cout << "col " << countc << endl ;
		sol += (countc*(countc-1))/2 ;
	}

	cout << sol << endl ;
}