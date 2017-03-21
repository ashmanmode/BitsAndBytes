#include <bits/stdc++.h>
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

int findCount(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int a = binary_search(A.begin(),A.end(),B);
    int b = binary_search(A.begin(),A.end(),B+1);
    cout << a << " " << b << endl;
    return b-a;
}

int main()
{
	int n,b;
	cin >> n ; 
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i] ;
	cin >> b ;
	cout << findCount(a,b);
	return 0;
}
