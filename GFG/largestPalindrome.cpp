#include <bits/stdc++.h>
using namespace std;

string largestpalin(string s)
{
	string answer = "";
	int size = s.length();

	bool dp[size][size];
	memset(dp,0,sizeof(dp));

	//Initial palindromes of size 1
	for(int i=0;i<size;i++)
		dp[i][i] = true ;

	//Of Size 2
	for(int i=0;i<size-1;i++)
	{
		if(s[i]==s[i+1])
		{
			dp[i][i+1] = true;
			answer = s.substr(i,2);
		}
	}

	//All others
	for(int i = 2;i < size ;i++ ) //For palin of size i
	{
		for(int j=0;j<size-i;j++)
		{
			if(dp[j+1][i+j-1] && s[j]==s[i+j])
			{
				dp[j][i+j] = true;
				answer = s.substr(j,i+1);
			}
		}
	}

	return answer=="" ? s.substr(0,1) : answer ;
}

int main()
{
	string s;
	cin >> s ;
	cout << largestpalin(s) << endl ;
}