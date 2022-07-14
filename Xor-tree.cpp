#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n;
int init[100100], goal[100100];
vector<int> g[100100], v;

void dfs(int nn,int p,int q, int pp=0){
	if(p^init[nn]) v.push_back(nn), p^=1;
	for(int i=0;i<g[nn].size();i++){
		if(g[nn][i]!=pp) dfs(g[nn][i], q, p, nn);
	}
}

void solve(){
	cin>>n;

	for(int i=1;i<n;i++){
		int u,v; cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}	
	for(int i=1;i<=n;i++){
		cin>>init[i];
	}
	for(int i=1;i<=n;i++){
		cin>>goal[i];
		init[i]^=goal[i];
	}
	dfs(1,0,0);
	cout<<v.size()<<'\n';
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<'\n';
	}


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