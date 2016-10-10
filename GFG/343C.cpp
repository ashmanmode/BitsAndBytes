#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m ;
	cin >> n >> m ; 

	char as ;
	int open  = 0;
	int close = 0;
	for(int i = 0 ; i < m;i++)
	{
		cin >> as ;
		if(as=='(')
			open++;
		else
			close++;
	}

	int req = open - close ;
	
	//Case1
	if(req < 0 || (n-m-req) < 0 || (n-m-req)%2 != 0)
	{
		cout << 0 << endl ;
		return 0 ;
	}

	//Possible case
	

}