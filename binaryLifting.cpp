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
typedef vector<vector<pii>> vvpii;
typedef vector<vector<pll>> vvpll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
#define mod 1000000007
#define mod2 998244353
#define f(x,a,b) for(int x=a;x<b;x++)
#define frev(x,a,b) for(int x=a;x>=b;x--)
#define PB push_back
#define MP make_pair
#define S second
#define F first
#define all(a) (a).begin(), (a).end()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define yesorno(x) cout<<((x)?"YES":"NO")<<"\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <class T> ostream &operator<<(ostream &os, const vector<T> a){ for (auto ele : a) os << ele << " "; return os;} 
template <class T> istream &operator>>(istream &is, vector<T> &a){ for (auto &ele : a) is >> ele; return is; }

vector<int> neigh[100100];
int par[100100][21], depth[100100];

void dfs(int node, int prev, int dep){
	par[node][0] = prev;
	depth[node] = dep;

	for(i=1;i<20;i++){
		par[node][i] = par[par[node][i-1]][i-1];
	}
	for(auto v: neigh[node]){
		if(v!=prev){
			dfs(v, node, dep+1);
		}
	}
}

int lca(int u, int v){
	if(depth[u]<depth[v]) swap(u,v);
	for(int i=19;i>=0;i--){
		if((depth[u]-depth[v])&(1<<i)){
			u = par[u][i];
		}
	}
	if(u == v) return u;

	for(int i=19;i>=0;i--){
		if(par[v][i]!=par[u][i]){
			v = par[v][i];
			u = par[u][i];
		}
	}
	return par[u][0];
}

void gcd_dfs(int node, int prev, int dep){
	par[node][0] = prev;
	depth[node] = dep;
	dp[nn][0] = val[nn];
	for(int i=1;i<20;i++){
		par[node][i] = par[par[node][i-1]][i-1];
		dp[node][i] = gcd(dp[node][i-1], dp[par[node][i-1]][i-1]);
	}
	for(auto v: neigh[node]){
		if(v!=prev){
			gcd_dfs(v, node, dep+1);
		}
	}
}


int pathGCD(int u, int v){
	if(depth[u]<depth[v]) swap(u,v);

	int ans = 0; // gcd(0,x) = x;
	for(int i=19;i>=0;i--){
		if((depth[u]-depth[v])&(1<<i)){
			ans = gcd(ans, dp[u][i]);
			u = par[u][i];
		}
	}
	if(u == v) return gcd(ans, val[u]);
	for(int i=19;i>=0;i--){
		if(par[v][i]!=par[u][i]){
			ans = gcd(ans, dp[v][i]);
			v = par[v][i];
			ans = gcd(ans, dp[u][i]);
			u = par[u][i];
		}
	}
	ans = gcd(ans, gcd(val[u], val[v]));
	return gcd(ans, val[par[u][0]]);
}

void prefix_tree_sum_dfs(int node, int dep, int par, int val){
	prefix[node] = val+prefix[par];
	depth[node] = dep;
	// build things needed for LCA
	for(i=1;i<20;i++){
		par[node][i] = par[par[node][i-1]][i-1];
	}

	for(auto v: neigh[node]){
		if(v.F!=par){
			dfs(v.F, dep+1,node,v.S);
		}
	}
}


// Partial sums on Tree
int partial[100100];

void addX(int u, int v, int x){
	partial[u]+=x;
	partial[v]+=x;
	int lc = lca(u,v);
	partial[lc]-=x;
	partial[par[lc][0]]-=x;
}

void pushAll(int node, int pp){
	for(auto v: neigh[node]){
		if(v!=pp) pushAll(v, node);
	}
	partial[par[node][0]]+=partial[node];
}

void solve(){
	
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