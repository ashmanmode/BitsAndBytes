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

map< pair<pii,pii> , vector<pii> > myMap;

vector<string> getCpy(vector<string> a)
{
  vector<string> b;
  fr(i,0,a.size())
    b.pb(a[i]);
  return b;
}

vector< pii > brute_path(vector<string> a,pii start,pii end)
{
  int n = a.size();
  int m = a[0].length();
  vector< pii > sol;

  if(start.F < 0 || start.S < 0)
  {
  // cout << "( " << start.F << "," << start.S << " )" << " -> " << "( " << end.F << "," << end.S << " )"  ;

  //   cout << "Outside " << endl ;
     return sol;
  }
  if(start.F == n || start.S == m)
  {
  // cout << "( " << start.F << "," << start.S << " )" << " -> " << "( " << end.F << "," << end.S << " )"    ;

  //   cout << "Outside " << endl ;
     return sol;
  }
  if(a[start.F][start.S]=='#')
  {
  // cout << "( " << start.F << "," << start.S << " )" << " -> " << "( " << end.F << "," << end.S << " )"  ;

  //   cout << "block" << endl ;
     return sol;
  }
  if(start.F==end.F && end.S==start.S)
  {
  // cout << "( " << start.F << "," << start.S << " )" << " -> " << "( " << end.F << "," << end.S << " )"    ;

  //   cout << "start=end" << endl;
     sol.pb(start);
     return sol;
  }

  // cout << "( " << start.F << "," << start.S << " )" << " -> " << "( " << end.F << "," << end.S << " )" << endl  ;

  
  //Other sols
  // vector<string> b = getCpy(a);
  a[start.F][start.S] = '#';
  vector< pii > next(4) ;
  next[0].F = start.F + 1 ; next[0].S = start.S ;
  next[1].F = start.F  ; next[1].S = start.S +1 ;
  next[2].F = start.F - 1 ; next[2].S = start.S ;
  next[3].F = start.F ; next[3].S = start.S - 1;
  int maxLen = -1 ;
  fr(i,0,4)
  {
    vector< pii > path ;
    if(myMap.find(mp(next[i],end))==myMap.end())
      myMap[mp(next[i],end)] = brute_path(a,next[i],end);
    
    path = myMap[mp(next[i],end)];
    // cout << " path " << ((int)path.size() > maxLen) << endl ;
    if(path.size()>0 && (int)path.size() >= maxLen)
    {
      maxLen = path.size();
      sol.clear();
      sol.pb(start);
      sol.insert(sol.end(),path.begin(),path.end());
      // cout << i << " " << maxLen << " | " << path.size() << endl ;
    }
    

  }
  a[start.F][start.S] = '.';
  // cout << "this call finished" << maxLen << endl;
  return sol;
}

char direction(pii a,pii b)
{
   if(a.F==b.F)
   {
      if(a.S+1 == b.S)
        return 'R';
      else
        return 'L';
   }
   else
   {
      if(a.F+1==b.F)
        return 'D';
      else
        return 'U';
   }
}

int main()
{   
  int n,m;
  cin >> n >> m ;
  vector<string> a(n);
  fr(i,0,n)
    cin >> a[i] ;
  pii start,end;
  fr(i,0,n)
  {
    fr(j,0,m)
    {
      if(a[i][j]=='S')
      {
        start = mp(i,j);
        a[i][j] = '.';
      }
      else if(a[i][j]=='F')
      {
        end = mp(i,j);
        a[i][j] = '.';
      }
    }
  }

  vector< pii> path = brute_path(a,start,end);
  fr(i,0,path.size()-1)
  {
    // cout << "( " << path[i].F << "," << path[i].S << " )" << endl ;
    cout << direction(path[i],path[i+1]) ;
  }
  cout << endl ;
	return 0;
}