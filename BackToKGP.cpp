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

// ll n,m,a,b;
// vpll g[100100];
// ll dist[100100];
// int vis[100100];
// ll num[100100], minf[100100], maxf[100100];

// void dijkstra(ll sc){
// 	f(i,1,2*n+10){
// 		dist[i] = 1e18;
// 		vis[i] = 0;
// 		num[i] = 0; minf[i] = 0; maxf[i] = 0;
// 	}
// 	dist[sc] = 0;
// 	num[sc] = 1;
// 	priority_queue<pll> pq;
// 	pq.push(MP(-0,sc));

// 	while(!pq.empty()){
// 		pll fs=pq.top(); pq.pop();
// 		if(vis[fs.S]) continue;
// 		vis[fs.S] = 1;

// 		for(auto v: g[fs.S]){
// 			int neigh = v.F;
// 			int wt=v.S;
// 			if(dist[neigh]>wt+dist[fs.S]){
// 				dist[neigh]=dist[fs.S]+wt;
// 				pq.push(MP(-dist[neigh],neigh));
// 				num[neigh] = num[fs.S];
// 				minf[neigh] = minf[fs.S]+1;
// 				maxf[neigh] = maxf[fs.S]+1;
// 			}else if(dist[neigh] == dist[fs.S]+wt){
// 				(num[neigh]+=num[fs.S])%=mod;
// 				minf[neigh] = min({minf[neigh], minf[fs.S]+1, maxf[fs.S]+1});
// 				maxf[neigh] = max({maxf[neigh], minf[fs.S]+1, maxf[fs.S]+1});
// 			}
// 		}
// 	}
// }


// void solve(){
	
// 	cin>>n>>m;
// 	f(i,0,m){
// 		ll a,b,c; 
// 		cin>>a>>b>>c;
// 		g[a].PB({b,c});
// 	}
// 	dijkstra(1);
// 	if(dist[n] == 1e18){
// 		cout<<-1<<'\n';
// 	}else{
// 		cout<<dist[n]<<' '<<num[n]<<' '<<minf[n]<<' '<<maxf[n]<<'\n';
// 	}
// 	f(i,1,n+1) g[i].clear();
// }
const int N = 2*1e5+10;
ll n,a,b; 
vpll g[2*N];
map<ll,vll> mp;
ll dist[2*N];
int vis[2*N];

void dijkstra(ll sc){
	for(int i=1;i<=(2*n+10);i++){
		dist[i] = 1e18;
		vis[i] = 0;
	}
	
	priority_queue<pll> pq;
	// pq.push({sc,-0});
	dist[sc] = 0;
	pq.push(MP(-0,sc));

	while(!pq.empty()){
		pll fs=pq.top(); pq.pop();
		if(vis[fs.S]) continue;
		vis[fs.S] = 1;

		for(auto v: g[fs.S]){
			int neigh = v.F;
			int wt=v.S;
			if(dist[neigh]>wt+dist[fs.S]){
				dist[neigh]=dist[fs.S]+wt;
				pq.push(MP(-dist[neigh],neigh));
			}
		}
	}
}


void jumpGame(){

	cin>>n>>a>>b;
	vll arr(n+1,0);
	f(i,1,n+1){
		cin>>arr[i];
		mp[arr[i]].PB(i);
		if(i!=n) g[i].PB({i+1, b});
		if(i!=1) g[i].PB({i-1, b});
	}
	ll super = n+1;
	for(auto x: mp){
		for(auto v: x.S){
			g[super].PB({v,a});
			g[v].PB({super,0});
		}
		super++;
	}
	ll src; cin>>src;
	dijkstra(src);
	for(int i=1;i<=n;i++) cout<<dist[i]<<' ';

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
    	jumpGame();
    }
    
}