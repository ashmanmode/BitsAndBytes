#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b;
	cin >> a >> b ;
	int count = 0 ;
	if(a==1 && b==1)
	{
		cout << count << endl ;
		return 0;
	}
	while(a>0&&b>0)
	{
		if(a<b)
		{
			a++;
			b -= 2;
		}
		else
		{
			a -= 2;	
			b++;
		}
		count++;
	}
	cout << count << endl ;
	return 0;
}