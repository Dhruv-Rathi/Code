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

// LCA TWIST

// vvii neigh;
// int par[100100][21], depth[100100];

// void dfs(int node, int prev, int dep){
// 	par[node][0] = prev;
// 	depth[node] = dep;

// 	for(int i=1;i<20;i++){
// 		par[node][i] = par[par[node][i-1]][i-1];
// 	}
// 	for(auto v: neigh[node]){
// 		if(v!=prev){
// 			dfs(v, node, dep+1);
// 		}
// 	}
// }

// int lca(int u, int v){
// 	if(depth[u]<depth[v]) swap(u,v);
// 	for(int i=19;i>=0;i--){
// 		if((depth[u]-depth[v])&(1<<i)){
// 			u = par[u][i];
// 		}
// 	}
// 	if(u == v) return u;

// 	for(int i=19;i>=0;i--){
// 		if(par[v][i]!=par[u][i]){
// 			v = par[v][i];
// 			u = par[u][i];
// 		}
// 	}
// 	return par[u][0];
// }

// void solve(){
// 	neigh.clear();
// 	int n; cin>>n;
// 	neigh.resize(n+1);

// 	for(int i=1;i<n;i++){
// 		int u,v; cin>>u>>v;
// 		neigh[u].PB(v);
// 		neigh[v].PB(u);
// 	}
// 	dfs(1,0,0);
// 	int q; cin>>q;
// 	for(int i=0;i<q;i++){
// 		int x,y,z; cin>>x>>y>>z;
// 		ll p1 = lca(x,z);
// 		ll p2 = lca(y,z);
// 		if(p1==p2){
// 			cout<<lca(x,y)<<'\n';
// 		}else{
// 			if(depth[p1]>depth[p2]){
// 				cout<<p1<<'\n';
// 			}else{
// 				cout<<p2<<'\n';
// 			}
// 		}

// 	}
// }

// PATH GCD

// int gcd(int a, int b){
//     return (b == 0)? a: gcd(b, a%b) ;
// }

// vvii g;
// int n;
// int val[100100];
// int par[100100][21], depth[100100], dp[100100][21];

// void dfs(int nn, int pp, int dep){
//     par[nn][0] = pp;
//     depth[nn] = dep;
//     dp[nn][0] = val[nn];
//     for(int i=1;i<20;i++){
//         par[nn][i] = par[par[nn][i-1]][i-1];
//         dp[nn][i] = gcd(dp[nn][i-1], dp[par[nn][i-1]][i-1]);
//     }
//     for(auto v: g[nn]){
//         if(v!=pp){
//             dfs(v, nn, dep+1);
//         }
//     }
// }

// int path_GCD(int u, int v){
//     if(depth[u]<depth[v]) swap(u,v);

//     int ans = 0;
//     for(int i=19;i>=0;i--){
//         if((depth[u]-depth[v])&(1<<i)){
//             ans = gcd(ans, dp[u][i]);
//             u = par[u][i];
//         }
//     }
//     if(u == v) return gcd(ans, val[u]);

//     for(int i=19;i>=0;i--){
//         if(par[v][i]!=par[u][i]){
//             ans = gcd(ans, dp[v][i]);
//             v = par[v][i];
//             ans = gcd(ans, dp[u][i]);
//             u = par[u][i];
//         }
//     }
//     ans = gcd(ans, gcd(val[u], val[v]));
//     return gcd(ans, val[par[u][0]]);
// }

// void solve(){
// 	g.clear();
// 	cin>>n;
// 	g.resize(n+1);
// 	for(int i=1;i<=n;i++){
//         cin>>val[i];
//     }
//     for(int i=1;i<n;i++){
//         int u, v; cin>>u>>v;
//         g[u].PB(v); g[v].PB(u);
//     }
//     dfs(1,0,0);
//     int q; cin>>q;
//     while(q--){
//         int x,y; cin>>x>>y;
//         cout<<path_GCD(x,y)<<'\n';
//     }
// }

// PARTIAL SUM ON TREE
vvii g;
int n; int dep[100100], par[100100][20];
ll partial[100100];

void dfs(int nn, int pp, int dd){
    par[nn][0] = pp;
    dep[nn] = dd;
    for(int i=1; i<20;i++){
        par[nn][i] = par[par[nn][i-1]][i-1];
    }
    for(auto v: g[nn]){
        if(v!=pp){
            dfs(v, nn, dd+1);
        }
    }
}

int lca(int u, int v){
    if(dep[u]<dep[v]) swap(u,v);

    for(int i=19;i>=0;i--){
        if((dep[u]-dep[v])&(1<<i)){
            u = par[u][i];
        }
    }

    if(u == v) return u;

    for(int i=19;i>=0;i--){
        if(par[u][i]!=par[v][i]){
            u = par[u][i]; v = par[v][i];
        }
    }
    return par[u][0];
}

void addX(int u, int v, int x){
    partial[u]+=x; partial[v]+=x;
    int lc = lca(u,v);
    partial[lc]-=x;
    partial[par[lc][0]]-=x;
    // cout<<u<<' '<<v<<' '<<lc<<'\n';
}

void pushAll(int nn, int pp){
    for(auto v: g[nn]){
        if(v!=pp){
            pushAll(v, nn)  ;
        }
    }
    partial[pp] += partial[nn];
    // cout<<pp<<' '<<partial[pp]<<'\n';
}

void solve(){
    g.clear();
    cin>>n;
    for(int i=0;i<=n;i++) partial[i] = 0;

    g.resize(n+1);
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        g[u].PB(v);
        g[v].PB(u);
    }
    dfs(1,0,0);

    int q; cin>>q;
    while(q--){
        int x,y,z; cin>>x>>y>>z;
        addX(x,y,z);
    }
    pushAll(1,0);
    for(int i=1;i<=n;i++){
        cout<<partial[i]<<' ';
    }cout<<'\n';

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