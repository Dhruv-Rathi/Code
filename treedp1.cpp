#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define F first 
#define S second
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// ll n, tot;
// ll a[100100], sum[100100], indp[100100], outdp[100100];
// vector<ll> g[100100];

// void dfs(int nn, int pp){
// 	sum[nn] = a[nn];
// 	for(auto v: g[nn]){
// 		if(v!=pp){
// 			dfs(v, nn);
// 			sum[nn] += sum[v];
// 		}
// 	}
// }

// void indfs(int nn, int pp){
// 	indp[nn] = 0;
// 	for(auto v: g[nn]){
// 		if(v!=pp){
// 			indfs(v, nn);
// 			indp[nn]+=indp[v]+sum[v];
// 		}
// 	}
// }

// void outdfs(int nn, int pp){
// 	if(nn == 1) outdp[nn] = 0; // outdp of root is 0
// 	else{
// 		outdp[nn] = outdp[pp]+indp[pp]-indp[nn]-2*sum[nn]+tot;
// 	}
// 	for(auto v: g[nn]){
// 		if(v!=pp){
// 			outdfs(v, nn);
// 		}
// 	}
// }

// void solve(){
// 	cin>>n;
// 	tot = 0;
// 	for(ll i=1;i<=n;i++){
// 		cin>>a[i];
// 		tot+=a[i];
// 	}
// 	for(ll i=0;i<n-1;i++){
// 		ll u,v; cin>>u>>v;
// 		g[u].push_back(v);
// 		g[v].push_back(u);
// 	}
// 	dfs(1,0);
// 	indfs(1,0); outdfs(1,0);

// 	ll ma = 0, mi = 1e18;
// 	for(ll i=1;i<=n;i++){
// 		ma = max(ma, indp[i]+outdp[i]);
// 		mi = min(mi, indp[i]+outdp[i]);
// 	}

// 	cout<<ma<<' '<<mi<<'\n';

// 	for(ll i=0;i<=n;i++){
// 		g[i].clear();
// 	}
// }


ll n, mi;
vector<ll> ans;
vector<vector<pair<ll,ll>>> g;

ll dfs(ll nn, ll pp){
	ll cnt = 0;

	for(auto v: g[nn]){
		if(v.F!=pp){
			cnt += dfs(v.F, nn) + v.S;

		}
	}
	return cnt;
}

void dfs2(ll nn, ll pp, ll w){
	if(pp == 0) mi = ans[nn];
	else{
		ans[nn] = ans[pp];
		if(w == 0) ans[nn]++;
		else ans[nn]--;
		mi = min(mi, ans[nn]);
	}
	for(auto v: g[nn]){
		if(v.F!=pp){
			dfs2(v.F, nn, v.S);
		}
	}
}

void solve(){
	g.clear();
	cin>>n;
	g.resize(n+1);
	ans.assign(n+1,0);

	for(ll i=1;i<n;i++){
		ll u,v; cin>>u>>v;
		g[u].push_back({v,0});
		g[v].push_back({u,1});
	}
	ans[1] = dfs(1,0);
	dfs2(1,0,0);
	cout<<mi<<'\n';
	for(ll i=1;i<=n;i++){
		if(ans[i] == mi) cout<<i<<' ';
	}
	cout<<'\n';
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