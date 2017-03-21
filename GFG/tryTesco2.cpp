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

vector< vector<int> > preArr;
vector<int> parent;
vector<int> level;

void preprocess(vector<int> parent)
{
    int n = parent.size();
    
    fr(i,0,n)
    {
        vector<int> temp;
        for (int j = 0; 1 << j < n; j++)
            temp.pb(-1);
        preArr.pb(temp);
    }
   
  
    fr(i,0,n)
        preArr[i][0] = parent[i];
   
  
    for (int j = 1; 1 << j < n; j++)
        fr(i,0,n)
            if (preArr[i][j - 1] != -1)
                preArr[i][j] = preArr[preArr[i][j - 1]][j - 1];
}

int getAn(int p, int q)
{
   int n = parent.size();
   int tmp, log, i;

   // cout << level[p] << " " << level[q] << endl;
  if(level[p] < level[q])
      tmp = p, p = q, q = tmp;

  for (log = 1; 1 << log <= level[p]; log++);
  log--;


  for (i = log; i >= 0; i--)
      if (level[p] - (1 << i) >= level[q])
          p = preArr[p][i];

  if (p == q)
      return p;

  for (i = log; i >= 0; i--)
      if (preArr[p][i] != -1 && preArr[p][i] != preArr[q][i])
          p = preArr[p][i], q = preArr[q][i];

  return parent[p];
}


int main()
{   
	int n,q,x;
    cin >> n >> q ;
    parent.resize(n);
    level.resize(n);
    parent[0] = -1 ;
    level[0] = 0 ;
    fr(i,0,n-1)
    {
        cin >> x ;
        parent[i+1] = x-1 ; 
        level[i+1] = level[x-1]+1;
    }
    // printvect(parent,n);cout << endl ;
    // printvect(level,n);cout << endl ;

    preprocess(parent);
    // fr(i,0,preArr.size())
    // {
    //     fr(j,0,preArr[0].size())
    //         cout << preArr[i][j] << " ";
    //     cout << endl ;
    // }
    int k;
    while(q--)
    {
        cin >>  k  ;
        vector<int> qs(k);
        fr(i,0,k)
            cin >> qs[i] ;

        //Solution
        int ans = qs[0]-1; 
        fr(i,1,k)
            ans = getAn(ans,qs[i]-1);
        cout << ans+1 << endl;
    }
   
    return 0;
}