#include <bits/stdc++.h>
using namespace std ;

int findKth(vector<int> a,int low,int high,int k)
{
	int pivot = low;
	int i = low+1;
	int j = low+1;
	while(j <= high )
	{
		if(a[j] < a[pivot])
		{
			swap(a[i],a[j]);
			i++;
		}
		j++;
	}
	swap(a[i-1],a[pivot]);

	if(i==k)
		return a[i-1];
	else if(i>k) //Smaller
		return findKth(a,low,i-2,k);
	else
		return findKth(a,i,high,k);
}

int main()
{
	int n,k;
	cin >> n ; 
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i] ;
	cin >> k;
	for(int i=0;i<n;i++)
		cout << findKth(a,0,n-1,i+1) << endl;
}