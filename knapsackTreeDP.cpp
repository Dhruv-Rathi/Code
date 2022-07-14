#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n, k;
vector<int> g[101];
int arr[101];
int dp[101][2][101];
int sz[101];

void dfs(int node, int pp){
	for(int i=0;i<=k;i++){
		dp[node][1][i] = (i == 1?arr[node]:-1e9);
		dp[node][0][i] = (i == 0?0:-1e9);
	}
	//
	for(auto v: g[node]){
		if(v!=pp){
			dfs(v, node);
			sz[node]+=sz[v];
			for(int a=k;a>=0;a--){
				for(int b=k;b>=0;b--){
					dp[node][0][a+b] = max(dp[node][0][a+b],dp[node][0][a]+max(dp[v][0][b], dp[v][1][b]));
					dp[node][1][a+b] = max(dp[node][1][a+b], dp[node][1][a]+dp[v][0][b]);
				}
			}
		}
	}

}

void solve(){
	cin>>n>>k;
	g.resize(n+1);
	for(int i=0;i<n-1;i++){
		int a,b; cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1,0);
	cout<<max(dp[1][0][k], dp[1][1][k]);
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