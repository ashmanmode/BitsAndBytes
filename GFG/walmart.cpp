#include <bits/stdc++.h>
using namespace std;

int dp[105][105];

void pre(string a)
{
	int n = a.length()+1;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			dp[i][j] = 0 ;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i-1]==a[j-1] && i!=j)
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
}

int main()
{
	string s;
	cin >> s ;

	pre(s);

	for(int i=0;i<s.length()+1;i++)
	{
		for(int j=0;j<s.length()+1;j++)
			cout << dp[i][j] << " ";
		cout << endl ;
	}
	return 0;
}