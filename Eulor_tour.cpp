#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


#define MAXN 100100

vector<int> g[MAXN];
int inTime[MAXN], outTime[MAXN];
int timer = 0;

void dfs(int nn, int pp){
	inTime[nn] = ++timer;
	for(auto v: g[nn]){
		if(!inTime[nn]){
			dfs(v,nn);
		}
	}
	outTime[nn] = ++timer;
}

bool isUAncestorofV( int u, int v ){
	if(inTime[u]<=inTime[v] && outTime[u]>=outTime[v]){
		return 1;
	}
	return 0;
}

void solve(){
	int n,m; cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v; cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	solve();
}
