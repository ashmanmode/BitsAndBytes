#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll; 
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
double dp[2001][2001];
int main(){


int t;
cin>>t;
int m,n;



for(ll caseIter=1;caseIter<=t;caseIter++){
cin>>n>>m;

int x=n;
int y=m;
for(int i=1;i<=n;i++){
for(int j=0;j<=min(m,i-1);j++){
if(i==1&&j==0){
dp[i][j]=((double)(n))/(n+m);
}
else if(j==0){
dp[i][j]=dp[i-1][j]*((double)(n-i+1))/(n-i+1+m);
}
else{
dp[i][j]=dp[i][j-1]*((double)m-j+1)/(m-j+1+n-i);
if(j!=i-1){
dp[i][j]+=dp[i-1][j]*((double)n-i+1)/(m-j+1+n-i);
}
}
// cout<<dp[i][j]<<" ";

}//cout<<endl;

}


cout<<"Case #"<<caseIter<<": "<<fixed<<setprecision(10)<<dp[n][m]<<endl;

}


return 0;
}