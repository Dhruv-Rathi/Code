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
ll n,m; 
vvll g;
vll indeg, topo, outdeg;

void kahn(){
	priority_queue<int> q;
	for(int i=1;i<=n;i++){
		if(indeg[i] == 0)
			q.push(-i);
	}
	while(!q.empty()){
		int cur = -q.top();
		q.pop();
		topo.pb(cur);
		for(auto v: g[cur]){
			indeg[v]--;
			if(indeg[v] == 0){
				q.push(-v);
			}
		}
	}
}

void kahn2(){
	int t=n;
	priority_queue<int> q;
	for(int i=1;i<=n;i++){
		if(outdeg[i]==0) q.push(i);
	}
	while(!q.empty()){
		int cur = q.top();
		q.pop();
		topo[cur] = t--;
		for(auto v: g[cur]){
			outdeg[v]--;
			if(outdeg[v]==0) q.push(v);
		}
	}
}

void solve(){
	cin>>n>>m;
	g.resize(n+1);
	indeg.assign(n+1,0);
	outdeg.assign(n+1,0);
	topo.assign(n+1,0);
	for(int i=0;i<m;i++){
		int a,b; cin>>a>>b;
		g[b].pb(a);
		outdeg[a]++;
	}
	kahn2();
	
	for(int i=1;i<=n;i++){
		cout<<topo[i]<<' ';
	}
	
    cout<<'\n';
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