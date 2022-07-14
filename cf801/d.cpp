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

vii g[200100];

int dfs(int node, int p){
	int s = 0, z = 0;
	for(auto v: g[node]){
		if(v!=p){
			int x = dfs(v,node);
			s+=x;
			if(x == 0) z++;
		}
	}
	return s+max(0,z-1);
}

void solve(){
	int n; cin>>n;
	f(i,1,n){
		int u,v; cin>>u>>v;
		u++; v++;
		g[u].PB(v);
		g[v].PB(u);
	}
	int ma_deg = 0;
	for(int i=1;i<=n;i++){
		ma_deg = max(ma_deg, (int)g[i].size());
	}
	if(ma_deg == 0){
		cout<<"0\n";
	}else if(ma_deg<3){
		cout<<"1\n";
	}else{
		for(int i=1;i<=n;i++){
			if(g[i].size()>=3){
				cout<<dfs(i,0)<<'\n';
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		g[i].clear();
	}
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
    	solve();
    }
    
}