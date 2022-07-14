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
#define int long long

ll n, k; 
vll g[200100];
ll p[200100];
int par[100100][21], depth[100100];


void dfs(int node, int prev, int dep){
	par[node][0] = prev;
	depth[node] = dep;

	for(int i=1;i<20;i++){
		par[node][i] = par[par[node][i-1]][i-1];
	}
	for(auto v: g[node]){
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


void solve(){
	cin>>n;
	f(i,1,n+1){
		g[i].clear();
	}
	f(i,0,n-1){
		ll u,v; cin>>u>>v;
		g[u].PB(v);
		g[v].PB(u);
	}
	// dfs(1,0,0);

	int q; cin>>q;
	while(q--){
		cin>>k;
		f(i,0,k){
			cin>>p[i];
		}
		if(k <= 2){
			yes; continue;
		}
		bool f = 1;
		dfs(p[0], 0, 0);
		f(i,1,k){
			ll x = lca(p[i], p[i-1]);
			if(x!=p[0] && p[i]!=x && p[i-1]!=x){
				no; f = 0; break;
			}
		}
		if(f) yes;
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