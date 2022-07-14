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

struct edge{
	ll u,v,w;
};

void solve(){
	ll n,m;
	cin>>n>>m;
	edge e[m];
	f(i,0,m){
		ll a,b,c;
		cin>>a>>b>>c;
		e[i].u = a;
		e[i].v = b;
		e[i].w = -c;
	}
	ll dist[n+1];
	for(ll i=1;i<=n;i++){
		dist[i] = 1e18;
	}
	dist[1] = 0;
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<m;j++){
			ll u=e[j].u;
			ll v=e[j].v;
			ll w=e[j].w;
			dist[v] = min(dist[v], dist[u]+w);
		}
	}

	bool ok = false;
	for(ll i=0;i<m;i++){
		ll u=e[i].u;
		ll v=e[i].v;
		ll w=e[i].w;
		if(dist[v]>dist[u]+w){
			ok = true; break;
		}
	}
	if(ok){cout<<-1<<'\n'; return;}
	cout<<(-dist[n])<<'\n';
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