#include <bits/stdc++.h>
using namespace std;

vector<int> flip(string A) {
    vector<int> arr;
    arr.push_back(0);
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='0')
            arr.push_back(1);
        else
            arr.push_back(-1);
    }
    for(int i=1;i<arr.size();i++)
        arr[i] = arr[i-1]+arr[i];

    for(int i=0;i<arr.size();i++)
        cout << arr[i] << " ";
    cout << endl;
    
    int min = arr[0]; int min_ind = 0 ;int mymin_ind = 0;
    int max_diff = arr[1]-arr[0]; int max_ind = 1 ;
    for(int i=1;i<arr.size();i++)
    {
        if(max_diff < arr[i]-min)
        {
            max_diff = arr[i]-min;
            max_ind = i;
            min_ind = mymin_ind ;
        }
        if(min > arr[i])
        {
            min = arr[i];
            mymin_ind = i ;
        }
    }

    // if(min_ind+1>max_ind)
    //     min_ind = max_ind-1;
    vector<int> sol;
    sol.push_back(min_ind+1);
    sol.push_back(max_ind);
    cout << min_ind+1 << " " << max_ind << endl ;
    return sol;
}

int main()
{
    string a = "010";
    flip(a);
    return 0;
}