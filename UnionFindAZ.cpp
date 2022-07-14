#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define PB push_back
#define MP make_pair
#define S second
#define F first
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// struct UnionFind {
// 	int n, set_size, *parent, *rank, *value;
// 	vector<vector<int>> g;

// 	UnionFind(){}
// 	UnionFind(int a){
// 		n = set_size =a;
// 		parent = new int[n+1];
// 		rank = new int[n+1];
// 		value = new int[n+1];
// 		g.resize(n+1);
// 		for(int i=1;i<=n;i++) 
// 			parent[i]=i, rank[i]=1, value[i]=0;
// 	}
// 	int find(int x){
// 		if(x!=parent[x]) return parent[x] = find(parent[x]);
// 		return x;
// 	}

// 	void dfs(int nn, int pp, int diff){
// 		value[nn] += diff;
// 		for(int v: g[nn]){
// 			if(v!=pp){
// 				dfs(v, nn, diff);
// 			}
// 		}
// 	}
// 	void merge(int x, int y, int val){
// 		int xroot = find(x), yroot = find(y);
// 		if(xroot!=yroot){
// 			if(rank[xroot]>=rank[yroot]){
// 				parent[yroot] = xroot;
// 				rank[xroot] += rank[yroot];
// 				int diff = value[x]-value[y];
// 				diff-=val;
// 				dfs(yroot, -1, diff);
// 			}else{
// 				parent[xroot] = yroot;
// 				rank[yroot] += rank[xroot];
// 				int diff = value[y]-value[x];
// 				diff+=val;
// 				dfs(xroot, -1, diff);
// 			}
// 			g[x].PB(y); g[y].PB(x);
// 			set_size-=1;
// 		}
// 	}
// 	int value1(int x, int y){
// 		if(find(x)!=find(y)){
// 			return 1e9;
// 		}
// 		return value[x]-value[y];
// 	}
// 	void reset(){
// 		set_size=n; for(int i=1;i<=n;i++)parent[i]=i,rank[i]=1;
// 	}
// 	int size(){return set_size;}
// 	void print(){for(int i=1;i<=n;i++) cout<<i<<"->"<<parent[i]<<'\n';}
// };

// void solve(){
// 	int n, q;
// 	cin>>n>>q;
// 	UnionFind U(n);

// 	for(int i=0;i<q;i++){
// 		int ch,x,y; cin>>ch>>x>>y;
// 		if(ch == 0){
// 			int z; cin>>z;
// 			U.merge(x,y,z);
// 		}else{
// 			int z = U.value1(x,y);
// 			if(z == 1e9){
// 				cout<<"?\n";
// 			}else{
// 				cout<<z<<'\n';
// 			}
// 		}
// 	}
// }

// TWO KINGDOMS


// int n,m;
// int name[1001][1001], col[1001][1001];

// int dx[] = {1,0}; int dy[] = {0,1};

// bool isValid(int i, int j){
// 	return (i>=0 && i<n && j>=0 && j<m);
// }

// struct UnionFind  //no path comp, only rank comp
// {
//     int n, sz, *par, *rank;
//     multiset<int> compSz;
//     UnionFind() {}
//     UnionFind(int csz)
//     {
//         n = sz = csz;
//         compSz.clear();
//         par = new int[n + 1], rank = new int[n + 1];
//         for (int i = 0; i <= n; i++)
//             par[i] = i, rank[i] = 1, compSz.insert(rank[i]);
//     }
//     int find(int x)
//     {
//         if (x != par[x]) return find(par[x]);
//         return x;
//     }

//     vpii st;
//     void merge(int x, int y)
//     {
//         int xroot = find(x), yroot = find(y);
//         if (xroot == yroot)return;
//         if (rank[xroot] < rank[yroot])
//         	swap(x, y), swap(xroot, yroot);
//         compSz.erase(compSz.find(rank[xroot]));
//         compSz.erase(compSz.find(rank[yroot]));
//         rank[xroot] += rank[yroot];
//         par[yroot] = xroot;
//         st.PB({yroot, xroot});
//         compSz.insert(rank[xroot]);
//         sz--;
//     }
//     void reset() {
//         while (!st.empty()) {
//             int yroot = st.back().F, xroot = st.back().S;
//             st.pop_back();
//             par[yroot] = yroot;
//             compSz.erase(compSz.find(rank[xroot]));
//             rank[xroot] -= rank[yroot];
//             compSz.insert(rank[xroot]);
//             compSz.insert(rank[yroot]);
//         }
//     }
//     int getMaxSz() {
//         return *(compSz.rbegin());
//     }
//     void print()
//     {
//         for (int i = 1; i <= n; i++)
//         {
//             cout << "rank: " << i << " -> " << rank[i] << endl;
//         }
//     }
// };


// void solve(){
// 	cin >> n >> m;
//     int cnt = 0;
//     f(i, 0, n) {
//         f(j, 0, m) {
//             cin >> col[i][j];
//             name[i][j] = ++cnt;
//         }
//     }
//     UnionFind U(cnt);
//     map<pii, vpii> edg;
//     f(i, 0, n) {
//         f(j, 0, m) {
//             f(k, 0, 2) {
//                 int ni = i + dx[k], nj = j + dy[k];
//                 if (isValid(ni, nj)) {
//                     //cout << ni << ' ' << nj << endl;
//                     int c1 = col[i][j], c2 = col[ni][nj];
//                     if (c1 > c2)swap(c1, c2);
//                     if (c1 == c2)U.merge(name[i][j], name[ni][nj]);
//                     else {
//                         edg[ {c1, c2}].PB({name[i][j], name[ni][nj]});
//                     }
//                 }
//             }
//         }
//     }
//     U.st.clear();
//     // uf.print();
//     int ans = 0;
//     for (auto &v : edg) {
//         for (auto x : v.S) {
//             U.merge(x.F, x.S);
//         }
//         // cout << "for " << v.ff.ff << ' ' << v.ff.ss << ' ' << uf.getMaxSz() << endl;
//         ans = max(ans, U.getMaxSz());
//         U.reset();
//     }
//     cout << ans << endl;
// }

vector<vector<pair<ll,pair<ll,ll>>>> g;

void solve(){
    g.clear();
    int n;
    cin>>n;
    g.resize(n+1);
    for(int i=1;i<n;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
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
    cin>>tc;
    for(int i=1;i<=tc;i++){
    //	cout<<"Case #"<<i<<": ";
    	solve();
    }
    
}