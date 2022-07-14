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

int n,m;

vector<vector<int>> g;

vector<int> vis;


void dfs(int node){
	vis[node] = 1;
	for(auto v:g[node]){
		if(!vis[v]){
			dfs(v);
		}
	}
}	

void solve()
{
	cin>>n>>m;
	g.clear(); // for testcase
	g.resize(n+1);
	
	vis.assign(n+1,0);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	ll count = 0;
	for(int node=1;node<=n;node++){
		if(!vis[node]){
			count++;
			dfs(node);
		}
	}
	cout<<(count-1);
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