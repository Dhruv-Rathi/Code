#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second


typedef long long ll;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool comp(pair<ll,ll> &a, pair <ll,ll> &b){
	return a.S<b.S;
}

void solve(){
	ll n; cin>>n;
	vector<pair<ll,ll>> event(n);
	for(ll i=0;i<n;i++){
		cin>>event[i].F>>event[i].S;
	}
	sort(event.begin(),event.end(),comp);
	ll ans = 1, prev = event[0].S;
	for(ll i=1;i<n;i++){
		if(event[i].F>=prev) {
			ans++;
			prev = event[i].S;
		}
		// cout<<event[i].F<<' '<<event[i].S<<'\n';
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