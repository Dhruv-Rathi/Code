#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N = 100010;

vector<int> g[N], groups[N];

bool vis[N] = {false};

void dfs(int nn, int idx){
	if(vis[nn]) return;
	vis[nn] = true;
	groups[idx].push_back(nn);
	for(int u: g[nn]){
		dfs(u, idx);
	}
	return;
}

void solve(){
	int n, m; cin>>n>>m;
	for(int i=0;i<=n;i++){
		g[i].clear();
		groups[i].clear();
		vis[i] = false;
	}
	int A[n], B[n];
	for(int i=0;i<n;i++) cin>>A[i];
	for(int i=0;i<n;i++) cin>>B[i];

	for(int i=0;i<m;i++){
		int u, v; cin>>u>>v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int cnt = 0;
	for(int i=0;i<n;i++){
		if(!vis[i]){
			dfs(i,cnt);
			cnt++;
		}
	}
	int ans = 0;
	for(int i=0;i<cnt;i++){
		multiset<int> mt;
		for(int u: groups[i]){
			mt.insert(A[u]);
		}
		for(int u: groups[i]){
			int x = B[u];
			if(mt.find(x)!=mt.end()){
				mt.erase(mt.find(x));
			}
		}
		ans+=(int)mt.size();
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