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


vii g[300100];
int dep[300100];
int par[300100];
int subtreeSz[300100];
int numChild[300100];

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
	
}

int rec(int node){
	int ans = 0;
	if(g[node].size()==1){
		return 0;
	}
	if(g[node].size() == 2){
		int x;
		for(auto v: g[node]){
			if(v!=par[node]) x = v;
		}
		return subtreeSz[x]-1;
	}
	if(g[node].size()==3){
		int x,y; bool f = 0;
		for(auto v: g[node]){
			if(v == par[node]) continue;
			if(f == 0) {
				x = v; f = 1;
			}else y = v;
		}
		return max(subtreeSz[x]-1+rec(y), subtreeSz[y]-1+rec(x));
	}
}


void solve(){
	memset(g,0,sizeof(g));
	int n; cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b; cin>>a>>b;
		g[a].PB(b);
		g[b].PB(a);
	}
	dfs(1,0,0);
	if(g[1].size() == 1){
		cout<<subtreeSz[g[1][0]]-1<<'\n';
		return;
	}else if(g[1].size() == 2){
		cout<<max(subtreeSz[g[1][0]]-1+rec(g[1][1]), subtreeSz[g[1][1]]-1+rec(g[1][0]))<<'\n';
	}
}
 
signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    test(t)
    solve();
    
}