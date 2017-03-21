#include<bits/stdc++.h>
using namespace std;

void arrange(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int start = -1 ;
    int index = -1;
    int temp;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]!=A[A[i]] && A[i] < A.size())
        {
            //Start of the loop
            start = A[i];
            index = i;
            int iter = index;
            while(1)
            {
                cout << iter << " -> " << A[iter] << endl ;
              temp = A[iter];
              if(A[iter]==index)
              {
                A[iter] = A.size()+start;
                break;
              }
              A[iter] = A.size()+A[A[iter]];
              iter = temp;
            }
            for(int j=0;j<A.size();j++)
                cout << A[j]<< " ";
            cout << endl ;
        }
    }
    for(int j=0;j<A.size();j++)
    {
        if(A[j]!=A[A[j]])
            A[j] -= A.size();
        cout << A[j]<< " ";
    }
    cout << endl ;
}

int main()
{
    int n;
    cin >> n ;
    vector<int> a(n)  ;
    for(int i=0;i<n;i++)
        cin >> a[i];
    arrange(a);

    return 0 ;
}