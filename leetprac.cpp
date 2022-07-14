#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define F first
#define S second
#define MP make_pair
typedef long long ll;
typedef pair<ll,ll> pll;


ll dijkstra(ll sc, int k, ll dst, int n, vector<vector<pll>> &g){
    vector<ll> dist(n+1), stops(n+1);
	for(int i=0;i<=n;i++){
		dist[i] = 1e18;
        stops[i] = 1e18;
	}
	
	priority_queue<pair<ll,pll>> pq;
	dist[sc] = 0;
    stops[sc] = 0;
	pq.push(MP(-0,MP(0,sc)));

	while(!pq.empty()){
		auto fs=pq.top(); 
		pq.pop();
		// cout<<fs.S.S<<' '<<fs.S.F<<' '<<-fs.F<<'\n';
        if(fs.S.S == dst) return -fs.F;
        if(fs.S.F == k+1) {
        	// cout<<"H";
        	// dist[]
        	continue;
        }
        
		for(auto &v: g[fs.S.S]){

			if((dist[v.F]>v.S+dist[fs.S.S] )|| (stops[v.F]>fs.S.F+1)){
				dist[v.F] = -fs.F+v.S;
                stops[v.F] = fs.S.F+1;
				pq.push(MP(-dist[v.F],MP(stops[v.F],v.F)));
			}
		}
	}
    return -1;
}

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    int m = (int)flights.size();
    vector<vector<pll>> g(n+1);
    for(int i=0;i<m;i++){
        g[flights[i][0]].push_back({flights[i][1], flights[i][2]});
    }
    return dijkstra(src, k, dst, n, g);
    
}

void solve(){
	int n, m; cin>>n>>m;
	vector<vector<int>>flights(m,vector<int>(3));
	for(int i=0;i<m;i++){
		for(int j = 0;j<3;j++) cin>>flights[i][j];
	}
	int src, dst, k;
	cin>>src>>dst>>k;
	cout<<findCheapestPrice(n, flights, src, dst, k);
}

// 9 10
// 0 1 1
// 1 2 1
// 2 3 1
// 3 7 1
// 0 4 3
// 4 5 3
// 5 7 3
// 0 6 5
// 6 7 100
// 7 8 1
// 0
// 8
// 3
 
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