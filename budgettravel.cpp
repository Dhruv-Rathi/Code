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

ll n,m,c,st,en,cap;
vector<pll> g[100100];

ll p[10010];
ll dist[10010][101];
bool vis[10010][101];

// {dist,{node, fuel}}

void dijkstra(ll s){

	f(i,1,n+1){
		f(j,0,cap+1){
			dist[i][j] = 1e18;
			vis[i][j] = 0;
		}
	}

	dist[s][0] = 0;
	priority_queue<pair<ll,pll>> pq;
	pq.push({0,{s,0}});


	while(!pq.empty()){
		ll cur = pq.top().S.F;
		ll fuel = pq.top().S.S;
		pq.pop();
		if(vis[cur][fuel]) continue;
		vis[cur][fuel] = 1;
		if(fuel<cap){
			if(dist[cur][fuel+1]>dist[cur][fuel]+p[cur]){
				dist[cur][fuel+1] = dist[cur][fuel]+p[cur];
				pq.push({-dist[cur][fuel+1],{cur,fuel+1}});
			}
		}
		for(auto v: g[cur]){
			ll neigh = v.F;
			ll req = v.S;
			if(fuel-req>=0){
				if(dist[neigh][fuel-req]>dist[cur][fuel]){
					dist[neigh][fuel-req]=dist[cur][fuel];
					pq.push({-dist[neigh][fuel-req],{neigh,fuel-req}});
				}
			}
		}
	}
}

void solve(){
	cin>>n>>m;
	f(i,0,m){
		ll a,b,c;
		cin>>a>>b>>c;
		g[a].pb({b,c});
		g[b].pb({a,c});

	}
	f(i,1,n+1){
		cin>>p[i];
	}
	cin>>st>>en>>cap;

	dijkstra(st);

	ll ans = 1e18;
	f(i,0,cap+1){
		ans = min(ans,dist[en][i]);
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

 
    solve();
    
	
}