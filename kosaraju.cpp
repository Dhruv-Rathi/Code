#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void dfs(int nn, stack<int> &st, vector<int> &vis, vector<int> g[]){
	vis[nn] = 1;
	for(auto v: g[nn]){
		if(!vis[v]){
			dfs(v, st, vis, g);
		}
	}
	st.push(nn);
}

void revDfs(int nn, vector<int> &vis, vector<int> g[]){
	cout<<nn<<' ';
	vis[nn] = 1;
	for(auto v: g[nn]){
		if(!vis[v]){
			revDfs(v, vis, g);
		}
	}
}



void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> g[n];
	for(int i=0;i<m;i++){
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
	}

	stack<int> st;
	vector<int> vis(n,0);
	for(int i=0;i<n;i++){
		if(!vis[i]){
			dfs(i,st,vis,g);
		}
	}

	vector<int> transpose[n];

	for(int i=0;i<n;i++){
		vis[i] = 0;
		for(auto v: g[i]){
			transpose[v].push_back(i);
		}
	}

	while(!st.empty()){
		int nn = st.top();
		st.pop();
		if(!vis[nn]){
			cout<<"SCC: ";
			revDfs(nn, vis, transpose);
			cout<<'\n';
		}
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
    cin>>tc;
    for(int i=1;i<=tc;i++){
    //	cout<<"Case #"<<i<<": ";
    	solve();
    }
    
}