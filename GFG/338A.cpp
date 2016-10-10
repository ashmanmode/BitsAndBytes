#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m ; 

	int k,a ; 
	vector<bool> arr(m);
	for(int i = 0 ; i < m ;i++)
		arr[i] = false ; 
	for(int i = 0 ; i < n ; i++ )
	{
		cin >> k ; 
		for(int j = 0 ; j < k ; j++)
		{
			cin >> a ;
			arr[a-1] = true; 
		}
	}

	bool poss = true ;
	for(int i= 0 ; i < m ;i++)
	{
		if(arr[i]==false)
		{
			poss = false;
			break;
		}
	}

	if(poss)
		cout << "YES" << endl;
	else
		cout << "NO" << endl ;
}