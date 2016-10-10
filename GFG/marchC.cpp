#include <bits/stdc++.h>
using namespace std;

bool check(string s)
{
	//string must be double string
	if(s.length()%2==0)
	{
		for(int i=0;i<s.length()/2;i++)
		{
			if(s[i]!=s[i+s.length()/2])
				return false;
		}
		return true;
	}
	//Remove 1 letter from string
	else
	{	
		if(s.length()==1)
			return false;
		//First string is the real one
		int count = 0 ;
		int i=0;
		int j=s.length()/2;
		while(i < s.length()/2 && j < s.length())
		{
			if(s[i]==s[j])
			{
				// cout << s[i] << " " << s[j] << endl ;
				i++;j++;
			}
			else
			{
				// cout << "sdf" << endl;
				count++;j++;
			}
		}
		if(count<=1)
		{
			// cout <<"returnA"<<endl;
			return true;
		}	

		//Second string is the real one
		count = 0 ;
		i=0;
		j=s.length()/2+1;
		while(i < s.length()/2+1 && j<s.length())
		{
			if(s[i]==s[j])
			{
				// cout << s[i] << " " << s[j] << endl ;
				i++;j++;
			}
			else
			{
				// cout <<"in here"<<endl;
				count++;i++;
			}
		}
		if(count==1)
		{
			// cout <<"returnB"<<endl;
			return true;
		}
		return false;	
	}
}

int main()
{
	int d; 
	cin >> d ;
	for(int i=0;i<d;i++)
	{
		string s;
		cin >> s ;
		if(check(s))
			cout << "YES" << endl ;
		else
			cout << "NO" << endl ;
	}
}