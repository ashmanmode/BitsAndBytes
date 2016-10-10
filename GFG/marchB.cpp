#include <bits/stdc++.h>
using namespace std;
typedef signed long long int sll;

int main()
{
	int t ;
	cin >> t ;
	while(t--)
	{
		sll n;
		sll k;
		cin >> n >> k ; 
		vector<sll> a(n),b(n);
		sll maxb = 0 ;
		sll sum = 0 ;
		for(int i = 0 ; i < n ;i++)
			cin >> a[i];
		for(int i = 0 ; i < n ;i++)
		{
			cin >> b[i];
			if(abs(b[i])>maxb)
				maxb = abs(b[i]);
		}
		for(int i = 0 ; i < n ;i++)
			sum += a[i]*b[i];
		cout << sum+k*maxb << endl;
	}
}