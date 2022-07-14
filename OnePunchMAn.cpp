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

int h, w;
string s[1010];

void BFS01(){
	vector<vector<int>> dist(h+1, vector<int>(w+1,1e9));
	deque<pii> dq;
	dist[0][0] = 0;
	dq.push_front({0,0});

	while(!dq.empty()){
		pii x = dq.front();
		dq.pop_front();
		for(int i=0;i<4;i++){
			int nx = x.F+dx[i];
			int ny = x.S+dy[i];
			if(nx>=0 && ny>=0 && nx<h && ny <w){
				if(s[nx][ny] == '.'){
					// cout<<dist[x.F][x.S]<<'\n';
					if(dist[nx][ny]>dist[x.F][x.S]){
						dist[nx][ny] = dist[x.F][x.S];
						dq.push_front({nx, ny});
					}
				}else{
					for(int p=nx-1;p<=nx+1;p++){
						for(int q=ny-1;q<=ny+1;q++){
							if(p>=0 && p<h && q>=0 && q<w){
								if(dist[p][q]>dist[x.F][x.S]+1){
									dist[p][q]=dist[x.F][x.S]+1;
									dq.push_back({p,q});
								}
							}
						}
					}
				}
			}
		}
	}

	cout<<dist[h-1][w-1];

}

void solve(){
	cin>>h>>w;
	
	for(int i=0;i<h;i++){
		cin>>s[i];
	}

	BFS01();

}

int n,m;
int g[1001][1001];

void One_Piece(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) cin>>g[i][j];
	}
	vector<vector<int>> dist(n+1, vector<int>(m+1,1e9));
	deque<pii> dq;
	dist[0][0] = 0;
	dq.push_back({0,0});

	while(!dq.empty()){
		pii p = dq.front(); dq.pop_front();
		int x = p.F, y = p.S;
		int px, py;
		if(g[x][y] == 1){
			px = x; py = y+1;
		}else if(g[x][y] == 2){
			px = x; py = y-1;
		}else if(g[x][y] == 3){
			px = x+1; py = y;
		}else{
			px = x-1; py = y;
		}

		for(int i=0;i<4;i++){
			int nx = x+dx[i], ny = y+dy[i];
			if(nx>=0 && nx<n && ny>=0 && ny<m){
				if(nx == px && ny == py){
					if(dist[nx][ny]>dist[x][y]){
						dist[nx][ny] = dist[x][y];
						dq.push_front({nx, ny});
					}
				}else{
					if(dist[nx][ny]>1+dist[x][y]){
						dist[nx][ny] = 1+dist[x][y];
						dq.push_back({nx,ny});
					}
				}
			}
		}
	}

	cout<<dist[n-1][m-1]<<'\n';


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
    	One_Piece();
    }
    
}