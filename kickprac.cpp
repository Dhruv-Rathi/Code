#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define F first
#define S second

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
	ll n,q; cin>>n>>q;
	string s; cin>>s;
	ll pre[26][n+1];
	for(int i=0;i<26;i++){
		pre[i][0] = 0;
	}
	for(ll i=1;i<=n;i++){
		for(int j=0;j<26;j++){
			if((s[i-1]-'A') == j){
				pre[j][i]=(1+pre[j][i-1]);
			}else{
				pre[j][i]=pre[j][i-1];
			}
		}
	}

	ll ans = 0;
	while(q--){
		ll l, r;
		cin>>l>>r;
		int cnt = 0;
		for(int i=0;i<26;i++){
			ll x = pre[i][r] - pre[i][l-1];
			if(x%2) cnt++;
		}
		if(cnt<=1) ans++;
	}
	cout<<ans<<'\n';
}

const int inf = 1e9+1;

string s[251];
int r, c;
int dist[251][251];
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

bool isValid(int i, int j){
	return (i>=0 && i<r && j>=0 && j<c);
}

void bfs(){
	queue<pair<int, int>> q;

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			dist[i][j] = inf;
			if(s[i][j] == '1'){
				q.push({i,j});
				dist[i][j] = 0;
			}
		}
	}
	while(!q.empty()){
		int x = q.front().F;
		int y = q.front().S;
		q.pop();
		for(int i=0;i<4;i++){
			int nx = x+dx[i], ny = y+dy[i];
			if(isValid(nx, ny)){
				if(dist[nx][ny]>dist[x][y]+1){
					dist[nx][ny] = 1+dist[x][y];
					q.push({nx,ny});
				}
			}
		}
	}
}

bool check(int x){
	vector<int> sum={inf, -inf}, diff={inf, -inf};
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(dist[i][j] > x){
				sum = {min(sum[0],i+j),max(sum[1],i+j)};
				diff= {min(diff[0],i-j),max(diff[1],i-j)};
			}
		}
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			int distFromHere = max(abs(sum[0]-(i+j)), abs(sum[1]-(i+j)));
			distFromHere = max(distFromHere, max(abs(diff[0]-(i-j)), abs(diff[1]-(i-j))));
			if(distFromHere<=x) return true;
		}
	}
	return false;

}

void solve2(){
	cin>>r>>c;
	for(int i=0;i<r;i++){
		cin>>s[i];
	}
	bfs();
	int pi = 0, pj = 0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(dist[i][j]>dist[pi][pj]){
				pi=i; pj=j;
			}
		}
	}
	int lo = 0, hi = dist[pi][pj], ans=hi;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(check(mid)){
			ans = mid;
			hi = mid-1;
		}else{
			lo = mid+1;
		}
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
    	cout<<"Case #"<<i<<": ";
    	solve2();
    }
    
}
