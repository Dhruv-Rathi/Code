#include<bits/stdc++.h>
using namespace std;

int n,m;

vector<vector<int>> g;

vector<int> vis;

int nodeVisited = 0;

void dfs(int node){
	vis[node] = 1;
	nodeVisited++;
	for(auto v:g[node]){
		if(!vis[v]){
			dfs(v);
		}
	}
}	
/*
5 3
1 2
1 3
4 5
*/

void solve(){
	// N,M <= 10^5	
	cin>> n >> m ;
	g.clear(); // for testcase
	g.resize(n+1);
	
	vis.assign(n+1,0);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector<long long> compsz;

	for(int node=1;node<=n;node++){
		if(!vis[node]){
			nodeVisited = 0;
			dfs(node);
			compsz.push_back(nodeVisited);
		}
	}
	
	long long ans = 0,preSum = 0;
	for(auto v:compsz){
		ans+=preSum*v;
		preSum+=v;
	}
	cout<<ans<<endl;
}		

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	//int _t;cin>>_t;while(_t--)
	solve();
}