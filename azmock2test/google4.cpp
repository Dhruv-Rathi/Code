#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool check(ll x, vector<ll> &a, ll n, ll s, ll m){
	ll cnt = 0;
	for(ll i=0;i<n;i++){
		if(a[i]<x){
			if((x-a[i])>m) return false;
			cnt+=(x-a[i]);
		}
	}
	return (cnt<=s*m);
}

void solve(){
	ll n,s,m;
	cin>>n>>s>>m;
	vector<ll> a(n);
	ll lo = 1e9;
	for(ll i=0;i<n;i++) {
		cin>>a[i];
		lo = min(lo, a[i]);
	}
	sort(a.begin(), a.end());

	ll hi = 1e18;
	ll ans = lo;
	while(lo<=hi){
		ll mid = lo+(hi-lo)/2;
		if(check(mid, a, n, s, m)){
			ans = mid;
			lo = mid+1;
		}else{
			hi = mid-1;
		}
	}

	cout<<ans<<'\n';


}
 
signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    ll tc = 1;
    cin>>tc;
    for(int i=1;i<=tc;i++){
    //	cout<<"Case #"<<i<<": ";
    	solve();
    }
    
}