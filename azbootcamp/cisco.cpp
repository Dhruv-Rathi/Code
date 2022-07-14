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
#define frev(x,a,b) for(int x=a;x>=b;x--)
#define PB push_back
#define MP make_pair
#define S second
#define F first
#define all(a) (a).begin(), (a).end()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define yesorno(x) cout<<((x)?"YES":"NO")<<"\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <class T> ostream &operator<<(ostream &os, const vector<T> a){ for (auto ele : a) os << ele << " "; return os;} 
template <class T> istream &operator>>(istream &is, vector<T> &a){ for (auto &ele : a) is >> ele; return is; }


int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

int n,m;

bool check(int i, int j){
	if(i<0 || j<0 || i>=n || j>=m) return 0;
	return 1;
}

void solve(){
	cin>>n>>m;
	int g[n][m], vis[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) {
			cin>>g[i][j];
			vis[i][j] = 0;
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(g[i][j] == 0 && vis[i][j] == 0){
				vis[i][j] = 1;
				int sz = 0;
				queue<pair<int, int>> q;
				q.push({i,j});

				while(!q.empty()){
					int x = q.front().F, y = q.front().S;
					q.pop();
					// if(vis[x][y]) continue;
					vis[x][y] = 1;
					sz++;
					for(int k=0;k<4;k++){
						int nx = x+dx[k], ny = y+dy[k];
						if(check(nx, ny) && g[nx][ny] == 0 && vis[nx][ny] == 0){
							q.push({nx, ny});
							vis[nx][ny] = 1;
						}
					}
				}
				// cout<<i<<' '<<j<<' '<<sz<<'\n';
				if(sz == 1) continue;
				q.push({i,j});

				while(!q.empty()){
					int x = q.front().F, y = q.front().S;
					q.pop();
					g[x][y] = sz;
					for(int k=0;k<4;k++){
						int nx = x+dx[k], ny = y+dy[k];
						if(check(nx, ny) && g[nx][ny] == 0){
							q.push({nx, ny});
						}
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) {
			cout<<g[i][j]<<' ';
		}cout<<'\n';
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