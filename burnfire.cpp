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

ll n,m;
vvpll g;

vll dist;
vector<bool> vis;

void dijkstra(ll sc){
	f(i,1,n+1){
		dist[i] = 1e18;
		vis[i] = 0;
	}
	dist[sc] = 0;
	priority_queue<pll> pq;
	pq.push(mp(-0,sc));

	while(!pq.empty()){
		pll fs=pq.top(); pq.pop();
		if(vis[fs.S]) continue;
		vis[fs.S] = 1;

		for(auto v: g[fs.S]){
			int neigh = v.F;
			int wt=v.S;
			if(dist[neigh]>wt+dist[fs.S]){
				dist[neigh]=dist[fs.S]+wt;
				pq.push(mp(-dist[neigh],neigh));
			}
		}
	}
}

void solve(){
	cin>>n>>m;
	vector<pair<pair<ll,ll>,ll>> edges;
	g.resize(n+1);
	vis.assign(n+1,0);
	dist.assign(n+1,0);
	f(i,0,m){
		ll u,v,d; cin>>u>>v>>d;
		g[u].pb({v,d}); g[v].pb({u,d});
		edges.push_back({{u,v},d});

	}
	ll A; cin>>A;

	dijkstra(A);

	ll ans = -1e18;

	f(i,1,n+1) assert(vis[i]);

	for(auto e: edges){
		ll u=e.F.F;
		ll v=e.F.S;
		ll d = e.S;

		ans = max(ans, (dist[u]+dist[v]+d)*5);
	}

	assert(ans>0);

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