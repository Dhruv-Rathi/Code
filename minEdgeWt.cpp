#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define F first
#define S second

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
	int n; cin>>n;
	UnionFind U(n);
	vector<pair<ll,pair<ll,ll>>> edges;

	for(int i=1;i<n;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		edges.push_back({w,{u,v}});
	}
	sort(edges.rbegin(), edges.rend());
	
	ll ans = 0;
	for(int i=0;i<n-1;i++){
		int rootU = U.find(edges[i].S.F);
        int rootV = U.find(edges[i].S.S);
		ans+=1LL*(U.rank[rootU])*(U.rank[rootV])*(edges[i].F);
		U.merge(edges[i].S.F, edges[i].S.S);
	}
	cout<<ans<<'\n';
}
signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    ll tc = 1;
    cin>>tc;
    for(int i=1;i<=tc;i++){
    //	cout<<"Case #"<<i<<": ";
    	solve();
    }
    
}