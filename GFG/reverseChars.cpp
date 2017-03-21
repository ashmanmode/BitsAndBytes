#include <bits/stdc++.h>
using namespace std;

void read()
{
	int x;
	cin >> x ;
	if(x!=-1)
	{
		read();
		cout << x << endl ;
	}
}

int main()
{
	read();
}