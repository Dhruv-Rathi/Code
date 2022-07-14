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

// int dx[] = {1,0,-1,0};
// int dy[] = {0,-1,0,1};

// int n,m; 

// bool check(int i, int j){
// 	if(i<0 || j<0 || i>=n || j>=m) return 0;
// 	return 1;
// }

// ll maxD(int i, int j){
// 	return max({n+m-i-j, i+j-2,n-i+j-1, m-j+i-1});
// }

// void solve(){
// 	cin>>n>>m;
// 	string g[n];

// 	queue<pii> q;
// 	ll dis[n][m];
// 	ll ma = 0;
// 	FOR(i,0,n){
// 		cin>>g[i];
// 		FOR(j,0,m){
// 			dis[i][j] = 0;
// 			if(g[i][j] == 'B'){
// 				q.push({i,j});
// 				ma = max(ma,maxD(i,j));
// 				// dis[i][j] = 0;
// 			}
// 		}
// 	}

// 	while(!q.empty()){
// 		int x = q.front().F;
// 		int y = q.front().S;
// 		q.pop();
// 		for(int i=0;i<4;i++){
// 			if(check(x+dx[i], y+dy[i])){
// 				if(dis[x+dx[i]][y+dy[i]]<(1+dis[x][y]) && dis[x+dx[i]][y+dy[i]]<ma){
// 					dis[x+dx[i]][y+dy[i]] = (1+dis[x][y]);
// 					q.push({x+dx[i], y+dy[i]});
// 				}
// 			}
// 		}
// 	}
// 	ll ans = 1e18;
// 	int x,y;
// 	FOR(i,0,n){
// 		FOR(j,0,m){
// 			if(dis[i][j]<ans){
// 				ans = dis[i][j];
// 				x = i+1; y=j+1;
// 			}
			
// 		}
// 	}
// 	cout<<x<<' '<<y<<'\n';

// }

// void solve2(){
// 	// int n,m;
// 	cin>>n>>m;
// 	ll dis[n][m];
// 	string g[n];
// 	vpii B;
// 	FOR(i,0,n){
// 		cin>>g[i];
// 		FOR(j,0,m){
// 			dis[i][j] = 0;
// 			if(g[i][j] == 'B'){
// 				B.PB({i,j});
// 			}
// 		}
// 	}
// 	ll ans = 1e18;
// 	for(auto v: B){
// 		map<pii,int> m;
// 		queue<pii> q;
// 		q.push({v.F, v.S});

// 		while(!q.empty()){
// 			int x = q.front().F;
// 			int y = q.front().S;
// 			m[MP(x,y)] = 1;
// 			q.pop();
// 			for(int i=0;i<4;i++){
// 				if(check(x+dx[i], y+dy[i])){
// 					if(dis[x+dx[i]][y+dy[i]]<(1+dis[x][y]) && m[MP(x+dx[i], y+dy[i])] == 0){
// 						dis[x+dx[i]][y+dy[i]] = (1+dis[x][y]);
// 						m[MP(x+dx[i], y+dy[i])] = 1;
// 						q.push({x+dx[i], y+dy[i]});
// 					}
// 				}
// 			}
// 		}
// 	}
	
// 	int x,y;
// 	FOR(i,0,n){
// 		FOR(j,0,m){
			
// 			if(dis[i][j]<ans){
// 				x = i+1; y=j+1;
// 				ans = dis[i][j];
// 			}
// 			// ans = min(ans, dis[i][j]);
// 		}
// 	}
// 	cout<<x<<' '<<y<<' '<<ans<<'\n';
// }


int n,m; 
set<int> s1, s2;
pll ans;

bool check(int x){
	FOR(i,0,n){
		FOR(j,0,m){
			if(*s1.begin()>=(i-x+j) && *s1.rbegin()<=(i+x+j) && *s2.rbegin()<=(i-j+x) && *s2.begin()>=(i-j-x)){
				ans = {i+1,j+1};
				return true;
			}
		}
	}
	return false;
}

void solve(){
	s1.clear(); s2.clear();
	cin>>n>>m;
	string g[n];
	

	FOR(i,0,n){
		cin>>g[i];
		FOR(j,0,m){
			if(g[i][j] == 'B'){
				s1.insert(i+j); s2.insert(i-j);
			}
		}
	}
	ll lo=0, hi=n*m;
	ans = {0,0};
	while(lo<=hi){
		ll mid = (lo+hi)/2;
		if(check(mid)){
			hi = mid-1;
		}else{
			lo = mid+1;
		}
	}
	cout<<ans.F<<' '<<ans.S<<'\n';
}

signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    test(t)
    solve();
    
}