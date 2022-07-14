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


ll dist[100100];
int vis[100100];

void dijkstra(int sc){
	for(int i=1;i<=n;i++){
		dist[i] = 1e18;
		vis[i] = 0;
	}
	dist[sc] = 0;
	priority_queue<pll> pq;
	pq.push(mp(-0,sc));

	while(!pq.empty()){
		pll fs = pq.top(); pq.pop();

		if(vis[fs.S]) continue;

		vis[fs.S] = 1;

		for(auto v:g[fs.S]){
			int neigh = v.F;
			int wt = v.S;
			if(dist[neigh]>dist[fs.S]+wt){
				dist[neigh] = dist[fs.S]+wt;
				pq.push(mp(-dist[neigh], neigh));
			}
		}
	}
}


void solve(){
	cin>>n>>m;
	g.resize(n+1);
	for(int i=0;i<m;i++){
		ll a,b,c; cin>>a>>b>>c;
		g[a].pb({b,c});
		// g[b].pb({a,c});
	}
	dijkstra(1);
	for(ll i=1;i<=n;i++){
		cout<<dist[i]<<' ';
	}

}
 
signed main()
{
    fast
   #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();
    
    
    
}