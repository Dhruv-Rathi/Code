#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef long long ll;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool comp(pair<pair<ll,ll>,ll> &a, pair<pair<ll,ll>,ll> &b){
	return a.F.S<b.F.S;
}
ll n; 
ll dp[200100];
ll start[200100], en[200100], profit[200100];

ll rec(ll l){
	if(l >= n) return 0;
	if(dp[l]!=-1) return dp[l];
	ll ans = 0;
	ans = rec(l+1);
	ll x = en[l];
	ll y = upper_bound(start, start+n,x) - start;
	ans = max(ans, profit[l]+rec(y));
	return dp[l] = ans;
}

void solve(){

	cin>>n;
	vector<pair<pair<ll,ll>,ll>> job(n);
	for(ll i=0;i<n;i++){
		cin>>job[i].F.F>>job[i].F.S>>job[i].S;
		dp[i] = -1;
	}
	sort(job.begin(), job.end(), comp);
	for(ll i=0;i<n;i++){
		start[i] = job[i].F.F;
		en[i] = job[i].F.S;
		profit[i] = job[i].S;
	}
	cout<<rec(0)<<'\n';
}
 
signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    ll tc = 1;
    // cin>>tc;
    for(int i=1;i<=tc;i++){
    //	cout<<"Case #"<<i<<": ";
    	solve();
    }
    
}