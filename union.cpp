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

vector<pair<int,int>> g[100100];

void MST(){
	int n,m; cin>>n>>m;

	UnionFind uf(n);

	vector<pair<int,pair<int,int>>> edgelist;

	int a,b,c;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		edgelist.push_back({c,{a,b}});
	}

	sort(edgelist.begin(),edgelist.end());

	int mst_cost=0;
	int cnt=0;

	for(auto v:edgelist){
		int x = v.second.first;
		int y = v.second.second;

		if(uf.find(x)!=uf.find(y)){
			cnt++;
			mst_cost+=v.first;
			g[x].push_back({y,v.first});
			g[y].push_back({x,v.first});
			uf.merge(x,y);
		}
	}
	if(cnt!=n-1){
		cout<<"IMPOSSIBLE\n";
		return;
	}

	cout<<mst_cost<<'\n';
}


signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    // test(t)
    MST();
    
    
    
}