#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
#define point pair<int,int>
#define pii pair<int,int>
#define pib pair<int,bool>
#define arr vector<int> 
#define vectin(a,n) fr(i,0,n) { cin >> a[i] ; }
typedef unsigned long long int ull;

int kthsmallest(const vector<int> &A, int k) {
   int min ;
   int globalmin = -1;
   int count = 0 ;
   int commCount ;
   while(count < k)
   {
     min = INT_MAX;
     commCount = 0 ;
     for(int j=0;j<A.size();j++)
     {
        if(A[j]>globalmin)
        {
            if(A[j]<min)
            {
                min = A[j];
                commCount = 0 ;
            }
            else if(A[j]==min)
                commCount++;
        }
        cout << commCount << "," << A[j] << " " ;
     }
     cout << endl ;
     globalmin = min ;
     count = count + 1 + commCount ; 
   }
   return globalmin;
}

int brute(vector<int> a,int k)
{
    sort(a.begin(),a.end());
    return a[k-1];
}


int main()
{
    int n,b;
    cin >> n ;
    vector<int> a(n) ;
    fr(i,0,n)
        cin >> a[i];
    cin >> b ; 
    cout << kthsmallest(a,b) << endl;
   
    return 0;
}

