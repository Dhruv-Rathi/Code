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

int n,m;
vvii g;
vii vis;

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

*/

void solve(){
	cin>>n>>m;
	g.clear();
	g.resize(n+1);
	
	vis.assign(n+1,0);
	for(int i=0;i<m;i++){
		int a,b; cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	int compcnt = 0;
	vll compsz;
	f(node,1,n+1){
		if(!vis[node]){
			nodeVisited=0;
			compcnt++;
			dfs(node);
			compsz.pb(nodeVisited);
		}
	}
	cout<<"No. of components: "<<compcnt<<'\n';
	// ans is no. of connections between unconnected nodes which decrease the no. of connected components.
	ll ans = 0, preSum = 0;
	for(auto v: compsz){
		ans+=preSum*v;
		preSum+=v;
	}

	cout<<ans<<'\n';

}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    // test(t)
    solve();
    
    
    
}