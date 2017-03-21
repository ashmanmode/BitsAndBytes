#include <bits/stdc++.h>
using namespace std;

int b_search(vector<int> a,int start,int end,int num)
{
	if(start > end)
		return -1;

	int mid = (start+end)/2;
	// cout << mid << endl ;
	if( (mid == 0 || (mid!=0 && a[mid-1]<num)) && a[mid]==num )
		return mid;
	else if(a[mid] >= num)
		return b_search(a,start,mid,num);
	else
		return b_search(a,mid+1,end,num); 
}

int main()
{
	int n;
	cin >> n ; 
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i];

	sort(a.begin(),a.end());

	int num;
	cin >> num ;
	cout << b_search(a,0,n-1,num) << endl ;
}