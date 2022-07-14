#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n, m;
int g[110], dist[110], vis[110];

bool check(int i){
	if(i<1 || i>100 || vis[i]) return false;
	return true;
}

int bfs(int sc){
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(sc);
	dist[sc] = 0;
	vis[sc] = 1;

	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i=1;i<=6;i++){
			int nx = g[cur+i];
			if(check(nx)){
				q.push(nx);
				vis[nx]=1;
				dist[nx] = dist[cur]+1;
			}
		}
	}
	if(!vis[100]){
		return -1;
	}else{
		return dist[100];
	}
}

void solve(){
	cin>>n;
	for(int i=1;i<=100;i++){
		g[i] = i;
	}
	for(int i=1;i<=n;i++){
		int u,v; cin>>u>>v;
		g[u] = v;
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		int u, v; 
		cin>>u>>v;
		g[u] = v;
	}

	cout<<bfs(1)<<'\n';
}


void solve2(){
	ll n; cin>>n;
	vector<ll> a(n);
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ll ans = -1e18, ma=1, mi=1;
	for(ll i=0;i<n;i++){
		ll x = mi;
		mi = min({a[i], mi*a[i], ma*a[i]});
		ma = max({a[i], x*a[i], ma*a[i]});
		ans = max(ans,ma);
	}
	cout<<ans<<'\n';
}

void solve3(){
	ll n, k; cin>>n>>k;
	vector<ll> a(n);
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	if(n == 1){
		cout<<"0\n"; return;
	}
	sort(a.begin(), a.end());

	ll ans = a[n-1]-a[0];
	ll ma, mi;

	for(ll i=1;i<n;i++){
		ma = max(a[n-1]-k, a[i-1]+k);
		mi = min(a[0]+k, a[i]-k);
		ans = min(ans, ma-mi);
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
    	solve3();
    }
    
}