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
#define FOR(x,a,b) for(int x=a;x<b;x++)
#define FORr(x,a,b) for(int x=a;x>=b;x--)
#define PB push_back
#define MP make_pair
#define S second
#define F first
#define all(a) (a).begin(), (a).end()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define yesorno(x) cout<<((x)?"YES":"NO")<<"\n"
#define test(t) int tc; cin>>tc; while(tc--)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <class T> ostream &operator<<(ostream &os, const vector<T> a){ for (auto ele : a) os << ele << " "; return os;} 
template <class T> istream &operator>>(istream &is, vector<T> &a){ for (auto &ele : a) is >> ele; return is; }


// vector<vector<pii>> g;

// void solve(){
// 	int n; cin>>n;
// 	map<int, vector<int>> val;
// 	for(int i=1;i<=n;i++){
// 		int x; cin>>x;
// 		mp[x].pb(i);
// 	}
// 	g.resize(n+mp.size()+1);
// 	for(int i=1;i<n;i++){
// 		g[i].pb({i+1,a});
// 		g[i+1].pb({i,a});
// 	}

// 	int Dnode = n+1;
// 	for(auto &v: mp){
// 		for(auto u:v.S){
// 			g[Dnode].pb({u,b});
// 			g[u].pb({Dnode, 0});
// 		}
// 		Dnode++;
// 	}

// }

// int n,m;
// vii g[2510];


// void solve(){
// 	cin>>n>>m;
// 	FOR(i,0,m){
// 		int a,b; cin>>a>>b;
// 		g[a].PB(b);
// 		g[b].PB(a);
// 	}
// 	int ans = 1e9;
// 	FOR(i,1,n+1){
// 		vii dist(n+1,1e9);
// 		vii par(n+1,-1);
// 		dist[i] = 0;
// 		queue<int> q;
// 		q.push(i);
// 		while(!q.empty()){
// 			int x = q.front();
// 			q.pop();
// 			for(auto v: g[x]){
// 				if(dist[v] == 1e9){
// 					dist[v] = 1+dist[x];
// 					par[v] = x;
// 					q.push(v);
// 				}else if(par[x]!=v && par[v]!=x){
// 					ans = min(ans, dist[x]+dist[v]+1);
// 				}
// 			}
// 		}
// 	}
// 	if(ans == 1e9){
// 		cout<<-1<<'\n';
// 	}else{
// 		cout<<ans<<'\n';
// 	}
// }


// void solve(){

// 	int n, src; ll a,b;
// 	cin>>n>>a>>b;
// 	vii arr(n);
// 	cin>>arr;
// 	cin>>src;
// 	vii dis(n,0);



// }
 
void solve(){
	int h,w; cin>>h>>w;
	int s[h][w];
	FOR(i,0,h){
		FOR(j,0,w){
			cin>>s[i][j];
		}
	}
	
}

signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    // test(t)
    solve();
    
    
    
}