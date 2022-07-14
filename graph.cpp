#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define vi vector<ll>
#define vvi vector<vi>
#define f(x,a,b) for(int x=a;x<b;x++)
#define pb push_back
#define eb emplace_back //faster than push_back
#define mod1 1000000007
#define mod2 998244353
#define ss second
#define ff first
#define all(a) a.begin(), a.end()
#define vecpii vector<pair<int,int>>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}
const int N=100100;

int n,m,q;

vector<vector<int>> g;
bool visited[N]; int sz[N], id[N];
int CUR_ID = 1;

void dfs(int node){
	if(visited[node]) return;
	visited[node] = 1;
	id[node] = CUR_ID;
	sz[CUR_ID]++;
	for(auto i: g[node]){
		dfs(i);
	}
}

void solve()
{
	cin>>n>>m>>q;
	g.resize(n+1);

	f(i,0,m){
		int x,y; cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}	
	f(i,1,n+1){
		if(!visited[i]){
			dfs(i);
			CUR_ID++;
		}
	}

	while(q--){
		int t; cin>>t;
		if(t==1){
			int x; cin>>x;
			cout<<sz[id[x]]<<'\n';
		}
		else {
			int x, y; cin>>x>>y;
			if(id[x] == id[y]) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}


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