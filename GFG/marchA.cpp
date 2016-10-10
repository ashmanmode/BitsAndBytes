#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n ; 
	cin >> n ; 
	string s1,s2;
	for(int i = 0 ; i < n ;i++)
	{
		cin >> s1 >> s2 ;
		bool a1[26],a2[26];
		bool sol = false;
		for(int j=0;j<26;j++)
		{
			a1[j] = false;
			a2[j] = false;
		}
		for(int j = 0 ; j< s1.length();j++)
			a1[(int)(s1[j]-'a')] = true;

		for(int j = 0 ; j< s2.length();j++)
			a2[(int)(s2[j]-'a')] = true;\


		for(int j = 0 ; j< 26;j++)
		{
			if(a1[j]==true&&a2[j]==true)
			{
				sol = true;
				break;
			}
		}
		if(sol)
			cout << "Yes" << endl;
		else
			cout << "No" << endl ;
	}
	return 0;
}
