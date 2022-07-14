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

ll n,m; 
vvii g,back;

void solve(){
	cin>>n>>m;
	ll indeg[n+1]={0};
	ll dp[n+1]={0};
	g.resize(n+1);
	back.resize(n+1);
	f(i,0,m){
		ll a,b; cin>>a>>b;
		g[a].pb(b);
		back[b].pb(a);
		indeg[b]++;
	}

	dp[1] = 1;

	queue<ll> q;
	f(i,1,n+1){
		if(indeg[i] == 0) q.push(i);
	}
	while(!q.empty()){
		ll node = q.front();
		q.pop();
		for(auto v: g[node]){
			indeg[v]--;
			if(indeg[v]==0) q.push(v);
		}

		for(auto v: back[node]){
			dp[node] = ((dp[node]%mod)+(dp[v]%mod))%mod;
		}
	}

	cout<<(dp[n]+mod)%mod<<'\n';

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