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

map<ll,ll> fullIA,fullJB,partialJB;
map<ll,set<ll> > freqFullJB,freqpartialJB;
ll expo(ll x,ll a,ll modulo){
	if(a==0) return 1;
	else{
		ll t=expo(x,a/2,modulo);
		if(a%2==0){
			return (t*t)%modulo;
		}
		else{
			return (x*((t*t)%modulo))%modulo;
		}
	}
}
void printMap(map<ll,ll>a){
	cout<<"Printing Map"<<endl;
	for(map<ll,ll>::iterator it=a.begin();it!=a.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}cout<<endl;
}
void findFreq(map<ll,set<ll> > a){
	cout<<"printing freq\n";
	for(map<ll,set<ll> >::iterator it=a.begin();it!=a.end();it++){
		cout<<it->first<<" "<<it->second.size()<<endl;
	}cout<<endl;
}
int main(){
	int t;
	cin>>t;
	ll divisions;
	for(ll caseIter=1;caseIter<=t;caseIter++){
		fullIA.clear();
		fullJB.clear();
		partialJB.clear();
		freqFullJB.clear();
		freqpartialJB.clear();
		ll A,B,N,K,ans=0,toSub=0;
		cin>>A>>B>>N>>K;
		divisions=N/K;
		divisions=divisions%MOD;
		for(ll i=1;i<=min(K,N);i++){
			fullIA[i]=expo(i,A,K)%K;
			fullJB[i]=expo(i,B,K)%K;
			if((fullIA[i]+fullJB[i])%K==0){
				// cout<<i<<" "<<fullIA[i]<<" "<<fullJB[i]<<endl;
				if(N%K==0){
					toSub=divisions;
				}
				else{
					toSub+=(divisions+1);
				}
				
			}
			freqFullJB[fullJB[i]].insert(i);
			if(N%K && N>K){
				if(divisions*K+i<=N){
					// cout<<"divisions*K+i="<<divisions*K+i<<endl;
					partialJB[i]=expo(i,B,K);
					freqpartialJB[partialJB[i]].insert(i);
					if((fullIA[i]+partialJB[i])%K==0){
						toSub++;
						// cout<<fullIA[i]<<" "<<partialJB[i]<<endl;
					}
				}
			}
			if(N<K){
				partialJB=fullJB;
				freqpartialJB=freqFullJB;

			}
		}
		ll count=0;
		// cout<<"To subtract:"<<toSub<<endl; 
		// printMap(fullIA);
		// printMap(fullJB);
		// printMap(partialJB);
		// findFreq(freqFullJB);
		// findFreq(freqpartialJB);
		// cout<<"found till here\n";
		for(map<ll,ll>::iterator iter=fullIA.begin();iter!=fullIA.end();iter++){
			count++;
			ll val=iter->second;
			ll toFind=(K-val)%K;
			if(divisions*K+count<=N){
				ans+=(((((divisions+1)%MOD*(divisions%MOD))%MOD)*freqFullJB[toFind].size()%MOD)%MOD+((divisions+1)%MOD*freqpartialJB[toFind].size()%MOD)%MOD)%MOD;
			}
			else{
				ans+=(((((divisions%MOD)*(divisions%MOD))%MOD)*freqFullJB[toFind].size()%MOD)%MOD+((divisions%MOD)*freqpartialJB[toFind].size()%MOD)%MOD)%MOD;
			}
		}
		ans=ans-toSub;
		cout<<"Case #"<<caseIter<<": "<<ans<<endl;

	}


	return 0;
}