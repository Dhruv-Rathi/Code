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

int n;
vii g[100100];
int sz[100100];

int indp[100100];
int outdp[100100];

void indfs(int node, int par){
	indp[node] = 0;
	sz[node] = 1;
	for(auto v: g[node]){
		if(v!=par){
			indfs(v,node);
			sz[node]+=sz[v];
			indp[node] += indp[v]+sz[v];
		}
	}
}

void outdfs(int node, int par, int outpar){
	if(node==1) outdp[node] = 0;
	else
		outdp[node] = outdp[par]+indp[par]-(indp[node]+sz[node])+(n-sz[node]);
	for(auto v: g[node]){
		if(v!=par){
			outdfs(v, node);
		}
	}
}


void solve(){
	cin>>n;
	FOR(i,0,n-1){
		int a,b; cin>>a>>b;
		g[a].PB(b);
		g[b].PB(a);
	}
	indfs(1,0);
	outdfs(1,0);
	FOR(i,1,n+1){
		cout<<indp[i]+outdp[i]<<'\n';
	}
}

void dfsin(int node, int par){
	indp[node] = 0;
	for(auto ch: g[node]){
		if(ch!=par){
			dsfin(ch, node);
			indp[node] = max(indp[ch]+1, indp[node]);
		}
	}
}

void dfsout(int node, int par, int outVal){
	outdp[node] = outVal;
	int max1=-1, max2=-1;
	for(auto ch: g[node]){
		if(ch!=par){
			if(indp[ch]>max1){
				max2=max1;
				max1=indp[ch];
			}else if(indp[ch]>max2){
				max2 = indp[ch];
			}
		}
	}

	for(auto ch: g[node]){
		if(ch!=par){
			if(indp[ch] == max1){
				dfsout(ch,node,max(max2+2, outdp[node]+1));
			}else{
				dfsout(ch,node,max(max1+2, outdp[node]+1));
			}
		}
	}
}

void solve2(){
	dfsin(1,0);
	dfsin(1,0,0);
	FOR(i,1,n+1){
		ans[i] = max(indp[i],outdp[i]);
		cout<<ans[i]<<' ';
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