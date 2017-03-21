ll myExp(ll b,ll a){
	if(b==0) return 1;
	else{
		ll t=myExp(b,a/2);
		if(a%2==1){
			return t*t*a;
		}
		else return t*t;
	}
}
ll Satisfies(ll a,ll l,ll h,ll n){
	cout<<"Power:"<<a<<", l:"<<l<<", h:"<<h<<", n:"<<n<<endl;
	if(h<l) return -1;

	ll m=(l+h)/2;

	cout<<"max base:"<<log(n)<<" "<<log(m)<<" "<<floor(log(n)/log(m))<<endl;
	if(a>floor(log(n)/log(m))) Satisfies(m,l,m-1,n);
	
	if(myExp(m,a)-n*m+n-1<0) return Satisfies(m,m+1,h,n);
	else if(myExp(m,a)-n*m+n-1>0) return Satisfies(m,l,m-1,n);
	else if(myExp(m,a)-n*m+n-1==0) return m;
}
ll returnBase(ll n){
	
	for(ll a=59;a>=1;a--){
		ll t=Satisfies(a,2,n,n);
		if(t!=-1) return t;
	}
	return n-1;
}