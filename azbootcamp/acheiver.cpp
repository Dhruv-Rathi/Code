#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define F first
#define S second

// ll n, m;
// ll g[1001][1001];
// int dx[] = {1,0,-1,0};
// int dy[] = {0,-1,0,1};

// void solve(){
// 	cin>>n>>m;
// 	queue<pair<ll,ll>> q;
// 	ll dist[n][m];
// 	bool vis[n][m];
// 	for(ll i=0;i<n;i++){
// 		for(ll j=0;j<m;j++){
// 			cin>>g[i][j];
// 			vis[i][j] = 0;
// 			dist[i][j] = 1e9;
// 			if(g[i][j] == 2){
// 				dist[i][j] = 0;
// 				q.push({i,j});
// 				vis[i][j] = 1;
// 			}
// 		}
// 	}

// 	while(!q.empty()){
// 		ll x = q.front().F;
// 		ll y = q.front().S;
// 		q.pop();
// 		for(int i=0;i<4;i++){
// 			ll nx = x+dx[i], ny = y+dy[i];
// 			if((!vis[nx][ny]) && (nx>=0 && nx<n && ny>=0 && ny<m)){
// 				if(dist[nx][ny]>dist[x][y]+1 && g[nx][ny]!=0){
// 					dist[nx][ny] = 1+dist[x][y];
// 					vis[nx][ny] = 1;
// 					q.push({nx,ny});
// 				}
// 			}
// 		}
// 	}

// 	ll ma = 0;
// 	for(ll i=0;i<n;i++){
// 		for(ll j=0;j<m;j++){
// 			if(g[i][j] == 1){
// 				ma = max(ma, dist[i][j]);
// 			}
// 		}
// 	}

// 	if(ma == 1e9){
// 		cout<<-1<<'\n';
// 	}else{
// 		cout<<ma<<'\n';
// 	}
// }

// string x, y, z;
// int dp[1001][1001];
// int n,m;
// int rec(int i, int j){
// 	if(dp[i][j]!=-1) return dp[i][j];
// 	if(i == n && j == m) return dp[i][j]=1;
// 	if(i == n){
// 		int ans;
// 		if(y[j] == z[i+j]){
// 			ans = rec(i,j+1);
// 		}else{
// 			ans = 0;
// 		}
// 		return dp[i][j] = ans;
// 	}
// 	if(j==m){
// 		int ans;
// 		if(x[i] == z[i+j]){
// 			ans = rec(i+1,j);
// 		}else{
// 			ans = 0;
// 		}
// 		return dp[i][j] = ans;
// 	}

// 	int ans = 0;
// 	if(x[i] == z[i+j]){
// 		ans = rec(i+1,j);
// 	}
// 	if(y[j] == z[i+j]){
// 		ans |= rec(i,j+1);
// 	}
// 	return dp[i][j] = ans;
// }
// void solve(){
	
// 	cin>>x>>y>>z;
// 	int i=0, j=0;
// 	n = x.size(), m = y.size();
// 	while(i<n && j<(n+m)){
// 		if(x[i] == z[j]){
// 			i++; j++;
// 		}else{
// 			j++;
// 		}
// 	}
// 	if(i!=n){
// 		cout<<"No\n"; return;
// 	}
// 	i = 0, j = 0;
// 	while(i<m && j<(n+m)){
// 		if(y[i] == z[j]){
// 			i++; j++;
// 		}else{
// 			j++;
// 		}
// 	}
// 	if(i!=m){
// 		cout<<"No\n"; return;
// 	}
// 	cout<<"Yes\n";
// }

// void solve2(){
// 	cin>>x>>y>>z;
// 	memset(dp,-1,sizeof(dp));
// 	n = x.size(), m = y.size();

// 	if(rec(0,0)){
// 		cout<<"Yes\n";
// 	}else{
// 		cout<<"No\n";
// 	}
// }

// void solve(){
// 	ll n,k; cin>>n>>k;
// 	vector<ll> v(n);
// 	multiset<ll> s;

// 	for(ll i=0;i<n;i++){
// 		cin>>v[i];
// 		s.insert(v[i]);
// 	}

// 	if(n%k){
// 		cout<<"No\n"; return;
// 	}

// 	bool ok = true;
// 	while(!s.empty()){
// 		ll x = *(s.begin());
// 		s.erase(s.begin());
// 		for(int i=1;i<k;i++){
// 			if(s.find(x+1)!=s.end()){
// 				s.erase(s.find(x+1));
// 				x++;
// 			}else{
// 				ok = false;
// 				break;
// 			}
// 		}
// 		if(ok == false) break;
// 	}
// 	if(ok){
// 		cout<<"Yes\n";
// 	}else{
// 		cout<<"No\n";
// 	}
// }

template <class T> ostream &operator<<(ostream &os, const vector<T> a){ for (auto ele : a) os << ele << " "; return os;} 

ll n, m;

vector<ll> g[100100];
ll indeg[100100];
vector<ll> topo;

bool isCycle;

void kahn(){
	priority_queue<ll> pq;

	for(ll i=0;i<n;i++){
		if(indeg[i] == 0){
			pq.push(-i);
		}
	}
	while(!pq.empty()){
		ll cur = -pq.top();
		pq.pop();
		topo.push_back(cur);
		for(auto v: g[cur]){
			indeg[v]--;
			if(indeg[v] == 0){
				pq.push(-v);
			}
		}
	}
}

void solve(){
	isCycle = false;
	cin>>n>>m;
	for(ll i=0;i<m;i++){
		ll u,v; cin>>u>>v;
		g[u].push_back(v);
		indeg[v]++;
		if(u == v){
			isCycle = true;
		}
	}
	if(isCycle){
		cout<<"No\n"; return;
	}
	kahn();
	cout<<topo<<'\n';
	if(topo.size() == n){
		cout<<"Yes\n";
	}else{
		cout<<"No\n";
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