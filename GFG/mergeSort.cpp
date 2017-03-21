#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> a,vector<int> b)
{
	int n = a.size();
	int m = b.size();
	vector<int> sol;

	int i=0,j=0;
	while(i<n && j<m)
	{
		if(a[i] < b[j])
		{
			sol.push_back(a[i]);
			i++;
		}
		else
		{
			sol.push_back(b[j]);
			j++;
		}
	}

	for(int k = i ; k < n ;k++)
		sol.push_back(a[k]);
	for(int k = j ; k < m ;k++)
		sol.push_back(b[k]);

	return sol;
}
	
int main()
{
	int n,m;
	cin >> n >> m ;
	vector<int> a(n);
	vector<int> b(m);
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<m;i++)
		cin >> b[i];
	vector<int> sol = merge(a,b);
	for(int i=0;i<sol.size();i++)
		cout << sol[i] << " " ;
	cout << endl; 
}