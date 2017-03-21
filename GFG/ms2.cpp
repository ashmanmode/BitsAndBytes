#include <bits/stdc++.h>
using namespace std;

string reverse(string a)
{
	if(a.length()==1)
		return a;
	return a[a.length()-1]+reverse(a.substr(0,a.length()-1));
}

string get(int n)
{
	string ans ="";
	while(n!=0)
	{
		char a = 'A';
		if(n%26==0)
			a='Z';
		else
			a='A'+(n%26)-1;
		ans += a;
		n--;
		n /= 26;
	}
	
	string rev = reverse(ans);
	return rev;
}

int main()
{
	int n;
	cin >> n ;
	cout << get(n)<<endl;
}