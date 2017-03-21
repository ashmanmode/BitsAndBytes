#include <bits/stdc++.h>
using namespace std;

int b_search(vector<int> a,int low,int high,int key)
{
	 if(low > high)
		return -1; 
     int mid = (low+high)/2;
     if(a[mid]==key)
     	return mid;
     else if(key < a[mid])
     	return b_search(a,low,mid-1,key);
     else
     	return b_search(a,mid+1,high,key);   
}

int main() {
	int t;
	cin >> t ;
	while(t--)
	{
		int n,k;
		cin >> n ; 
		vector<int> a(n);
		for(int i=0;i<n;i++)
			cin >> a[i];
		sort(a.begin(),a.end());
		for(int i=0;i<n;i++)
			cout << a[i] << " ";
		cout << endl;
		cin >> k ;
		cout << b_search(a,0,n-1,k) << endl ;
	}
	return 0;
}