//binary search algo
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int b_search(vector<int> vect,int first,int last,int s)
{
	int index;
	if(first > last)
		index = -1 ;
	else
	{
		int mid = (first+last)/2;
		if(vect[mid] == s)
			index = mid;
		else if(s < vect[mid])
			index = b_search(vect,first,mid,s);
		else
			index = b_search(vect,mid+1,last,s);			
	}
	return index;
}

int main()
{
	int n,a,b;
	cin >> n ;
	vector<int> vect(n);
	for(int i = 0 ; i < n ; i++ )
		cin >> vect[i] ;
	cin >> a >> b;
	sort(vect.begin(),vect.end());
	for(int i = 0 ; i < n ; i++ )
		cout <<  vect[i]  << " ";
	cout << endl ; 
	cout << a << " found at " << b_search(vect,0,n,a) + 1 << endl;
	cout << b << " found at " << b_search(vect,0,n,b) + 1 << endl;
	return 0;
}