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

vii g[100100];
int dep[100100];
int par[100100];
bool isLeaf[100100];
int subtreeSz[100100];
int numChild[100100];

ll ans = 0;

void dfs(int node, int parent, int depth){
	dep[node] = depth;
	par[node] = parent;


	numChild[node] = 0;
	subtreeSz[node] = 1;
	for(auto v: g[node]){

		if(v!=parent){
			numChild[node]++;
			dfs(v,node,depth+1);
			subtreeSz[node] += subtreeSz[v];
		}
	}
	if(numChild[node] == 0){
		isLeaf[node]=1;
	}
}

ll dfs2(int node, int parent, int n){
	ll sum = 0;
	for(auto v: g[node]){
		if(v==parent) continue;
		sum += dfs2(v,node,n);
	}
	sum++;
	ans+=1LL*sum*(n-sum);
	return sum;
}

void solve(){
	int n; cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b; cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1,0,0);
	// dfs2(1,-1,n);
	// cout<<ans<<'\n';
	ll i=1;
	// f(i,1,n+1){
	// 	cout<<subtreeSz[i]<<' ';
	// }
	while(1){
		ll f = 1;
		for(auto v: g[i]){
			if(v==par[i]) continue;
			if(subtreeSz[v]>(n/2)){
				f=0; i = v; break;
			}
		}
		if(f) break;
	}

	cout<<i<<'\n';
}


void solve2(){
	int n; cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b; cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1,0,0);
	int x = numChild[1];
	f(i,2,n+1){
		x  = max(x, 1+numChild[i]);
	}

	cout<<x+1<<'\n';
}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    // test(t)
    solve2();
    
    
    
}