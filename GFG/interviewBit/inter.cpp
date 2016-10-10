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

 
struct Interval {
 int start;
 int end;
 Interval() : start(0), end(0) {}
 Interval(int s, int e) : start(s), end(e) {}
};
 
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) 
{
    vector< pair<int,int> > a;
    for(int i=0;i<intervals.size();i++)
    {
        a.push_back(make_pair(intervals.start,i));
        a.push_back(make_pair(intervals.end,i));
    }
    a.push_back(make_pair(newInterval.start,-1));
    a.push_back(make_pair(newInterval.end,-1));
    sort(a.begin(),a.end());

    bool start = false;
    int i=0;
    while(i<a.size())
    {
        if(a[i].second==-1)
        {
            if(!start)
            {
                start = true;
                if(a[i-1].second==a[i+1].second)
                {
                    a.erase(a.begin()+i);
                    a.erase(a.begin()+i);
                }
            }
            else
                start = false;
            if(a[i-1].second==a[i+1].second)
            {
                a[i-1].second = -1;
                a[i+1].second = -1;
            }
        }
        if(start)
            a[i].second = -1;
    }

    vector<Interval> sol;
    for(int i=0;i<a.size();i++)
    {
        if(currColor==a[i].second)
        {
            sol.push_back(Interval(currval,a[i].second));
        }
        currColor = a[i].second;
        currval = a[i].first;
    }
    
}

int main()
{
    int n;
    cin >> n ; 

}