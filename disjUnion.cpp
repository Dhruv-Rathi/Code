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

struct UnionFind {
	int n, set_size, *parent, *rank;
	UnionFind(){}
	UnionFind(int a){
		n = set_size =a;
		parent = new int[n+1];
		rank = new int[n+1];
		for(int i=1;i<=n;i++) parent[i]=i, rank[i]=1;}
	int find(int x){
		if(x!=parent[x]) return parent[x] = find(parent[x]);
		return x;
	}
	void merge(int x, int y){
		int xroot = find(x), yroot = find(y);
		if(xroot!=yroot){
			if(rank[xroot]>=rank[yroot]){
				parent[yroot] = xroot;
				rank[xroot] += rank[yroot];
			}else{
				parent[xroot] = yroot;
				rank[yroot] += rank[xroot];
			}
			set_size-=1;
		}
	}
	void reset(){
		set_size=n; for(int i=1;i<=n;i++)parent[i]=i,rank[i]=1;
	}
	int size(){return set_size;}
	void print(){for(int i=1;i<=n;i++) cout<<i<<"->"<<parent[i]<<'\n';}
};

void solve(){
	int n,q; cin>>n>>q;
	UnionFind S(n);

	while(q--){
		int com, x, y; cin>>com>>x>>y;
		if(com == 0){
			S.merge(x+1,y+1);
		}else{
			if(S.find(x+1) == S.find(y+1)){
				cout<<1<<'\n';
			}else{
				cout<<0<<'\n';
			}
		}
	}
}

void solve2(){
	int n,m,q; cin>>n>>m>>q;
	pii edge[m+1];
	bool vis[m+1];
	memset(vis,false, sizeof(vis));

	FOR(i,0,m){
		int u,v; cin>>u>>v;
		edge[i+1] = {u,v};
	}
	pii query[q]; 
	FOR(i,0,q){
		int ch; cin>>ch;
		if(ch == 1){
			int x; cin>>x;
			query[i] = {1,x};
			vis[x] = true;
		}else{
			query[i] = {2,-1};
		}
	}

	UnionFind U(n);
	FOR(i,1,m+1){
		if(!vis[i]){
			U.merge(edge[i].F, edge[i].S);
		}
	}
	vector<int> ans;

	FORr(i,q-1,0){
		if(query[i].F == 2) ans.PB(U.set_size);
		else {
			int u = query[i].S;
			U.merge(edge[u].F, edge[u].S);
		}
	}
	reverse(all(ans));
	for(int a: ans) cout<<a<<'\n';
}
 
signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    // test(t)
    solve2();
    
}