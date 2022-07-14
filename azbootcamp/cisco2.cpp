#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define F first
#define S second

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {2,1,-1,-2,-2,-1,1,2};

vector<pair<int, int>> pos;
vector<vector<int>> dist;
vector<vector<int>> dp;

bool check(int i, int j){
	if(i<0 || j<0 || i>=8 || j>=8) return 0;
	return 1;
}

void bfs(int sc){
	vector<vector<int>> D(8, vector<int>(8,1e9));

	D[pos[sc].F][pos[sc].S] = 0;

	queue<pair<int, int>> q;
	q.push(pos[sc]);
	while(!q.empty()){
		int x = q.front().F, y = q.front().S;
		q.pop();
		for(int i=0;i<8;i++){
			int nx = x+dx[i], ny = y+dy[i];
			if(check(nx, ny) && D[nx][ny]>D[x][y]+1){
				D[nx][ny] = D[x][y]+1;
				q.push({nx,ny});
			}
		}
	}
	for(int i=0;i<dist.size();i++){
		dist[sc][i] = D[pos[i].F][pos[i].S];
	}
}

int rec(int mask,int cur){
	int m = pos.size()-1;
	if(mask == ((1<<m)-1)) return 0;
	if(dp[mask][cur]!=-1) return dp[mask][cur];

	int ans = 1e9;
	for(int i=0;i<m;i++){
		if(mask&(1<<i)) continue;
		ans = min(ans, dist[cur][i]+rec(mask|(1<<i), i));
	}
	return dp[mask][cur] = ans;
}

void solve(){
	pos.clear();

	int kx, ky;
	cin>>kx>>ky;
	int m; cin>>m;
	for(int i=0;i<m;i++){
		int x,y; cin>>x>>y;
		pos.push_back({x,y});
	}
	pos.push_back({kx, ky});
	dist = vector<vector<int>>(m+1, vector<int>(m+1));
	for(int i=0;i<=m;i++){
		bfs(i);
	}
	dp = vector<vector<int>>((1<<m), vector<int>(m+1, -1));

	cout<<rec(0,m)<<'\n';
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