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
#define test(t) int tc; cin>>tc; while(tc--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <class T> ostream &operator<<(ostream &os, const vector<T> a){ for (auto ele : a) os << ele << " "; return os;} 
template <class T> istream &operator>>(istream &is, vector<T> &a){ for (auto &ele : a) is >> ele; return is; }

// int dx[] = {1,1,0,-1,-1,-1,0,1};
// int dy[] = {0,1,1,1,0,-1,-1,-1};

// bool check(int i, int j, int n, int m){
// 	if(i<0 || i>=n || j<0 || j>=m) return 0;
// 	return 1;
// }

// void solve(){

// 	int n, m;
	
// 	cin>>n>>m;
// 	string s[n][m];

// 	f(i,0,n){
// 		f(j,0,m){
// 			cin>>s[i][j];
// 		}
// 	}
// 	int a,b,c,d; cin>>a>>b>>c>>d;
// 	if(s[c][d] == "#"){
// 		cout<<-1<<'\n'; return;
// 	}
// 	int dist[n+1][m+1];
// 	f(i,0,n){
// 		f(j,0,m){
// 			dist[i][j] = 1e9;
// 		}
// 	}
// 	dist[a][b] = 0;
// 	queue<pii> q;
// 	q.push({a,b});
// 	while(!q.empty()){
// 		int x = q.front().F;
// 		int y = q.front().S;
// 		q.pop();
// 		for(int i=0;i<8;i++){
// 			if(check(x+dx[i], y+dy[i], n, m) && s[x+dx[i]][y+dy[i]] == "."){
// 				if(dist[x+dx[i]][y+dy[i]]>(1+dist[x][y])){
// 					dist[x+dx[i]][y+dy[i]] = 1+dist[x][y];
// 					q.push({x+dx[i], y+dy[i]});
// 				}
// 			}
// 		}
// 	}
// 	if(dist[c][d] == 1e9){
// 		cout<<-1<<'\n';
// 	}else{
// 		cout<<dist[c][d]<<'\n';
// 	}
// }

// void solve2(){
// 	ll n,x,r1,r2; cin>>n>>x>>r1>>r2;
// 	ll ans = 0;
// 	vll prime(n+1,1);
// 	// memset(prime,1, sizeof(prime));
// 	for(int p=2;p*p<=n;p++){
// 		if(prime[p] == 1){
// 			for(int i = p*p;i<=n;i+=p){
// 				prime[i] = 0;
// 			}
// 		}
// 	}
	
// 	prime[1] = 0;

// 	f(i,2,n+1){
// 		prime[i]+=prime[i-1];
// 	}
// 	int i=1;
// 	while(i<n){
// 		// cout<<i<<"->"<<prime[i]<<'\n';
// 		if(r2*prime[i]>=i*r1){
// 			// cout<<i<<' ';
// 			if(i+x<=n){
// 				i+=x;
// 			}else{
// 				i++;
// 			}
// 		}else{
// 			i++;
// 		}
// 		ans++;
// 	}
// 	cout<<ans;
// }

// vii g[100100];

// int dep[100100];
// int par[100100];
// int numChild[100100];
// vii leafNodes;
// void dfs(int node, int depth, int parent){
// 	dep[node] = depth;
// 	par[node] = parent;
// 	numChild[node] = 0;

// 	for(auto v: g[node]){
// 		if(v!=parent){
// 			numChild[node]++;
// 			dfs(v, depth+1,node);	
// 		}
// 	}
// 	if(numChild[node] == 0){
// 		leafNodes.PB(node);
// 	}
// }

// void solve3(){
// 	int n; cin>>n;
// 	f(i,1,n){
// 		int a,b; 
// 		cin>>a>>b;
// 		g[a].PB(b);
// 		g[b].PB(a);
// 	}
// 	dfs(1,0,0);
// 	int maxch = 1;
// 	f(i,2,n+1){
// 		if(dep[i]>dep[maxch]){
// 			maxch = i;
// 		}
// 	}

// 	dfs(maxch,0,0);
	
// 	f(i,1,n+1){
// 		if(dep[i]>dep[maxch]){
// 			maxch = i;
// 		}
// 	}
// 	// cout<<maxch<<'\n';
// 	int dia = dep[maxch];
// 	// cout<<dia<<'\n';
// 	int ans[n+1] = {0};
// 	for(auto v: leafNodes){
// 		// cout<<v<<' '<<dep[v]<<'\n';
// 		if(dep[v] == dia){
// 			ans[v] = 1;
// 		}
// 	}
// 	dfs(maxch,0,0);
// 	for(auto v: leafNodes){
// 		if(dep[v] == dia){
// 			ans[v] = 1;
// 		}
// 	}
// 	for(auto v: leafNodes){
// 		if(ans[v] == 0){
// 			cout<<"YES\n"; return;
// 		}

// 	}
// 	cout<<"NO\n";
// }

// void solve4(){
// 	int dx[] = {1,0,-1,0};
// 	int dy[] = {0,1,0,-1};

// 	int n,m,q1;
// 	cin>>n>>m>>q1;
// 	int g[n][m];
// 	int cnt = 0;
// 	f(i,0,n) {
// 		f(j,0,m) {
// 			cin>>g[i][j];
// 			if(g[i][j] == 1) cnt++;
// 		}
// 	}

// 	while(q1--){
// 		int x,y; cin>>x>>y;
// 		x--; y--;
// 		if(g[x][y] == 1){
// 			int sz = 1;
// 			queue<pii> q;
// 			q.push({x,y});
// 			while(!q.empty()){
// 				int a = q.front().F;
// 				int b = q.front().S;
// 				g[a][b] = 0;
// 				q.pop();
				
// 				f(i,0,4){
// 					if(check(a+dx[i],b+dy[i],n,m) && (g[a+dx[i]][b+dy[i]] == 1)){
// 						q.push({a+dx[i],b+dy[i]});
// 						g[a+dx[i]][b+dy[i]] = 0;
// 						sz++;
// 					}
// 				}
// 			}
// 			cnt-=sz;
// 		}
		
// 		cout<<cnt<<'\n';
		
// 	}
// }


// vll g[100100];
// ll vis[100100];

// void dfs(ll node){
// 	vis[node] = 1;
// 	for(auto v:g[node]){
// 		if(!vis[v]){
// 			dfs(v);
// 		}
// 	}
// }


// void solve5(){
// 	ll N, R, c, r;
// 	cin>>N>>R>>c>>r;
// 	// vis.assign(N+1,0);
// 	// g.resize(N+1);
// 	memset(g,0,sizeof(g));
// 	memset(vis,0,sizeof(vis));
// 	f(i,0,R){
// 		ll a,b; cin>>a>>b;
// 		g[a].PB(b);
// 		g[b].PB(a);
// 	}
	
// 	ll compcnt = 0;
	
// 	f(node,1,N+1){
// 		if(!vis[node]){
// 			compcnt++;
// 			dfs(node);
// 		}
// 	}
	
// 	cout<<min(c*compcnt+(N-compcnt)*r, c*N)<<'\n';

// }



class prioritize {
	public: bool operator ()(pii &p1, pii &p2) {
		return p1.S > p2.S;
	}
};

int m, h, n,k; 
vpii grid[1010];

pll dist[1010];
int vis[1010];


void dijkstra(int sc){
	for(int i=1;i<=n;i++){
		dist[i].F = 1e18;
		dist[i].S = 1e18;
		vis[i] = 0;
	}
	dist[sc].F = 0;
	dist[sc].S = 0;
	priority_queue<pii,vector<pii>,prioritize> pq;
	pq.push(MP(sc,0));

	while(!pq.empty()){
		pii fs = pq.top(); pq.pop();

		if(vis[fs.F]) continue;

		vis[fs.F] = 1;

		for(auto v:grid[fs.F]){
			int neigh = v.F;
			int wt = v.S;
			if(dist[neigh].F>dist[fs.F].F+wt && (dist[fs.F].S+1<=k)){
				dist[neigh].F = dist[fs.F].F+wt;
				dist[neigh].S = dist[fs.F].S+1;
				pq.push(MP(neigh, dist[neigh].F));
			}else if(dist[fs.F].S+1<=k){
				dist[neigh].F = dist[fs.F].F+wt;
				dist[neigh].S = dist[fs.F].S+1;
				pq.push(MP(neigh, dist[neigh].F));
			}
		}
	}
}

ll rec(ll node, ll tickits){

	for(auto v: grid[node]){
		
	}
}

void solve7(){
	cin>>n>>h>>m;
	f(i,0,m){
		int a,b; ll c;
		cin>>a>>b>>c;
		grid[a].PB({b,c});
	}
	cin>>k;
	dijkstra(1);
	if(dist[h].F == 1e18 || dist[h].S>k){
		cout<<-1<<'\n';
	}else{
		cout<<dist[h].F<<'\n';
	}
}

// vll gr[100100];

// void solve9(){
// 	int n,m,q;
// 	cin>>n>>m>>q;
// 	vii c(n);
// 	cin>>c;
// 	f(i,0,m){
// 		int u,v; cin>>u>>v;
// 		gr[u].PB(v);
// 		gr[v].PB(u);
// 	}
// 	while(q--){
// 		int ch; cin>>ch;
// 		ll x; cin>>x;

// 		if(ch == 1){

// 		}else{

// 		}
// 	}
// }

signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    // test(t)
    solve7();
    
}