#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

long long MOD=1000000007;     long double EPS=1e-9;
#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
ll binpow(ll b,ll p,ll M){ll ans=1;b%=M;for(;p;p>>=1){if(p&1)ans=ans*b%M;b=b*b%M;}return ans;}

#define MAXN 100100

vector<int> g[MAXN];
int inTime[MAXN], loTime[MAXN];
int timer = 0;
int numSplit[MAXN];

void dfs(int node, int par){
	timer++;
	inTime[node] = loTime[node] = timer;
	bool isArti = false;
	int child = 0;

	numSplit[node] = 1;

	for(auto v: g[node]){
		if(v == par) continue;
		if(!inTime[v]){
			child++;
			dfs(v,node);
			loTime[node] = min(loTime[node], loTime[v]);
			if(loTime[v]>=inTime[node]){
				isArti = true;
				numSplit[node]++;
			}
			if(loTime[v]>inTime[node]){
				// node-v is a bridge.
				pr(node, v);
			}
		}else{
			loTime[node] = min(loTime[node], inTime[v]);
		}
	}
	if(par == 0){
		numSplit[node] = child;
	}
	if((par == 0 && child>=2) || (par!=0 && isArti)){
		// This node is an articulation point.
		
		pr("Art", node);
	}
}

void solve(){
	int n,m; cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v; cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int comp = 0;
	for(int i=1;i<=n;i++){
		if(!inTime[i]){
			dfs(i,0);
			comp++;
		}
	}

	for(int i=1;i<=n;i++){
		if(g[i].size()==0){
			cout<<comp-1<<' ';
		}else{
			cout<<comp-1+numSplit[i]<<' ';
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	solve();
}