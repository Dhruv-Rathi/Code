#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef vector<int> vii;
typedef vector<vector<int>> vvii;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pll>> vvpll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
#define mod 1000000007
#define mod2 998244353
#define f(x,a,b) for(int x=a;x<b;x++)
#define pb push_back
#define mp make_pair
#define S second
#define F first
#define all(a) a.begin(), a.end()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define yesorno(x) cout<<((x)?"YES":"NO")<<"\n"
#define test(t) int tc; cin>>tc; while(tc--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}


vvii g;
vii vis;
vii topo;

void dfs(int node){
	vis[node] = 1;
	for(auto v: g[node]){
		if(!vis[v]){
			dfs(v);
		}
	}
	topo.pb(node);

}

int dp[100100];

int rec(int node){ // longest path starting at node.
    if(dp[node]!=-1) return dp[node];
    int ans = 1;
    for(auto v: g[node]){
        ans = max(ans, 1+rec(v));
    }
    return dp[node] = ans;
}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 	int n,m; cin>>n>>m;
 	g.resize(n+1);
    vis.assign(n+1,0);
 	for(int i=0;i<m;i++){
 		int a,b;
 		cin>>a>>b;
 		g[a].pb(b);

 	}

    memset(dp,-1,sizeof(dp));
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans, rec(i));
    }

    cout<<ans<<'\n'; // Longest path in a DAG.
    
    for(int i=1;i<=n;i++){
    	if(!vis[i]){
    		dfs(i);
    	}
    }
    reverse(all(topo));  // Topological ordering.
    for(auto v: topo){
    	cout<<v<<' ';
    }    	

    cout<<'\n';
    // Iterative method for longest path in a DAG.
    reverse(all(topo));
    int final = 0;
    for(auto node: topo){
        int ans = 1;
        for(auto v: g[node]){
            ans = max(1,1+dp[v]);
        }
        dp[node] = ans;
        final = max(final, dp[node]);
    }

    cout<<final<<'\n';
    
}