#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> sol,some;
    int power = 1 ;
    for(int i=A.size()-1;i>=0;i--)
    {
        if(power+A[i]==10)
            sol.push_back(0); 
        else
        {
            sol.push_back(A[i]+power);
            power = 0 ;
        }
    }
    if(power==1)
        sol.push_back(1);
    bool start = true;
    for(int i=0;i<sol.size();i++)
        cout << sol[i] << " " ;
    cout << endl ;
    for(int i=sol.size()-1;i>=0;i--)
    {
    	if(sol[i]!=0)
    		start = false;
        if(!start)
        	some.push_back(sol[i]);
    }
    for(int i=0;i<some.size();i++)
        cout << some[i] << " " ;
    cout << endl ;
    return some; 
}

int main()
{
	
	int n;
	cin >> n ; 
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i];
	plusOne(a);
}