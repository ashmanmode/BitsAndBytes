#include <bits/stdc++.h>
using namespace std;

int calc(vector<int> a,int n,bool type)
{
	//Base Cases
	if(n==1)
		return 1;
	
	if(type==0 && a[n-2]<a[n-1])
	{
		cout << "include " << a[n-1] << endl;
		return 1+calc(a,n-1,1);
	}
	else if(type==1 && a[n-2]>a[n-1])
	{
		cout << "include " << a[n-1] << endl;
		return 1+calc(a,n-1,0);
	}
	else
		return max(calc(a,n-1,0),calc(a,n-1,1));
}

int main()
{
	int n;
	cin >> n ; 

	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i] ;
	cout << max(calc(a,n,0),calc(a,n,1)) << endl;
}