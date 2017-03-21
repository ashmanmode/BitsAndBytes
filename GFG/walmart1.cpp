#include <bits/stdc++.h>
using namespace std;

int calc(vector<int> a,int n,int state)
{
	if(n<0)
		return 0;
			
	if(state==2)
	{
		if(a[n]==1||a[n]==3)
			return 1+max(calc(a,n-1,3),calc(a,n-1,1));
	}
	else if(state==3)
	{
		if(a[n]==2||a[n]==3)
			return 1+max(calc(a,n-1,2),calc(a,n-1,1));
	}
	return max(calc(a,n-1,1),max(calc(a,n-1,2),calc(a,n-1,3)));
}

int main()
{
	int n;
	cin >> n ;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i] ;

	//1 - rest //2 - yoga  //3 - contest
	cout << n-calc(a,n,1) << endl;
}