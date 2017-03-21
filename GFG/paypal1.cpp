#include <bits/stdc++.h>
#include <bitset>
using namespace std;

typedef unsigned long long int ull;

bool divisible(ull a)
{
	ull s = 1 ;
	while(s <= a)
	{
		if(a==s)
			return true;
		s *= 5 ;
	}
	return false;
}

bool div(string a)
{
	ull num = 0 ;
	for(int i=0;i<a.length();i++)
		num += (ull)(a[i]-'0')*(1<<(a.length()-1-i));
	
	return divisible(num);
}

int getMin(string a)
{
	cout << "Call " << a << endl ;
	if(div(a))
		return 1 ;
	
	int minval = 2*a.length() ; 
	for(int i=0;i<a.length()-1;i++)
	{
		if( div( a.substr(0,i+1) ) && a[i+1]=='1')
		{
			int newval = 1 + getMin(a.substr(i+1));
			if(newval < minval)
				minval = newval;
		
		}
	}
	return minval;
}

int main()
{
	string a;
	cin >> a ;
	
	int ans = getMin(a);
	if(ans > a.length())
		cout << -1 << endl ;
	else
		cout << ans << endl ;
}