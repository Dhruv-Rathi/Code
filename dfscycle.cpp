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

vvii g;
vii col;
vii parent;
bool is_cycle;
vii any_cycle;

vii cntcycle;
vii prefixorder;

void dfs(int node, int par){  // O(N+M)
	parent[node] = par;
	col[node] = 2;
	for(auto v: g[node]){
		if(v == parent[node]) continue; // Case For undirected graphs.
		if(col[v] == 1){
			// node - v is a forward edge
			dfs(v, node);
		}else if(col[v] == 2){
			// node - v is a back edge
			// We found a cycle.
			cout<<"Hit: "<<node<<'\n';
			if(is_cycle == 0){
				int temp = node;
				while(temp!=v){
					any_cycle.pb(temp);
					temp=parent[temp];
				}
				any_cycle.pb(temp);
				reverse(all(any_cycle));
			}
			cntcycle[node]++;
			cntcycle[parent[v]]--;
			is_cycle = 1;

		}else if(col[v] == 3){
			// node - v is a cross edge
		}
	}
	col[node] = 3;
	prefixorder.pb(node);
}

void solve(){
	int n,m; 
	cin>>n>>m;
	g.resize(n+1);
	col.assign(n+1,1);
	parent.assign(n+1,0);
	cntcycle.assign(n+1,0);

	map<pii, int> edgecnt;
	for(int i=0;i<m;i++){
		int x,y; cin>>x>>y;
		if(x == y){
			// self loop.
		}
		if(x>y) swap(x,y);
		edgecnt[mp(x,y)]++;
		if(edgecnt[mp(x,y)]>1){
			// multiple edge cycle.
		}else{
			g[x].pb(y);
			g[y].pb(x);// For undirected.
		}

	}
	for(int i=1;i<=n;i++)
		if(col[i]==1)
			dfs(i,0);
	for(auto v: any_cycle){
		cout<<v<<' ';
	}
	cout<<'\n';
	for(auto v: prefixorder){
		cntcycle[parent[v]]+=cntcycle[v];
	}
	int cntnode = 0;
	for(int i=1;i<=n;i++){
		if(cntcycle[i]>0) cntnode++;
	}
	cout<<cntnode;
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