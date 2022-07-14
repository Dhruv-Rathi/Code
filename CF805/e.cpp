#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll n;
vector<ll> g[200100];
bool vis[200100];

void dfs(ll nn, ll &cnt){
	vis[nn] = true;
	++cnt;
	for(auto v: g[nn]){
		if(!vis[v]){
			dfs(v, cnt);
		}
	}
}

void solve(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		g[i].clear();
		vis[i] = false;
	}
	ll freq[n+1] = {0};
	for(ll i=0;i<n;i++){
		ll u,v; cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		freq[u]++;
		freq[v]++;
	}
	for(ll i=1;i<=n;i++){
		if(freq[i]>2){
			cout<<"NO\n"; return;
		}
	}
	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			ll cnt = 0;
			dfs(i,cnt);
			if(cnt&1){
				cout<<"NO\n";
				return;
			}
		}
	}
	cout<<"YES\n";

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