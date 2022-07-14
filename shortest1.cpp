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
#define pb push_back
#define mp make_pair
#define S second
#define F first
#define all(a) a.begin(), a.end()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define yesorno(x) cout<<((x)?"YES":"NO")<<"\n"
#define test(t) int tc; cin>>tc; while(tc--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}
const int N = 1010;

int n,m;
bool g[N][N];
int distA[N][N];
int distM[N][N];

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

queue<pii> Mocc, Aocc;
pii par[N][N];

void solve(){
	cin>>n>>m;
	memset(g,false,sizeof(g));
	memset(distA,-1,sizeof(distA));
	memset(distM,-1,sizeof(distM));

	for(int i=0;i<n;i++){
		string s; cin>>s;
		for(int j=0;j<m;j++){
			g[i][j] = true;
			if(s[j] == '#') g[i][j] = false;
			else if(s[j] == 'M'){
				distM[i][j] = 0;
				Mocc.push({i,j});
			}else if(s[j] == 'A'){
				distA[i][j] = 0;
				Aocc.push({i,j});
				par[i][j] = {-1,-1};
			}
		}
	}

	while(!Mocc.empty()){
		auto it  = Mocc.front();
		Mocc.pop();
		int x = it.F, y = it.S;

		for(int i=0;i<4;i++){
			int xx = x+dx[i], yy = y+dy[i];
			if(xx<0 || xx>=n || yy<0 || yy>=m) continue;
			if(g[xx][yy] && distM[xx][yy]==-1){
				distM[xx][yy] = distM[x][y]+1;
				Mocc.push({xx, yy});
			}
		}
	}
	while(!Aocc.empty()){
		auto it = Aocc.front();
		Aocc.pop();
		int x = it.F, y = it.S;

		for(int i=0;i<4;i++){
			int xx = x+dx[i], yy = y+dy[i];
			if(xx<0 || xx>=n || yy<0 || yy>=m) continue;
			if(g[xx][yy] && distA[xx][yy]==-1){
				distA[xx][yy] = distA[x][y]+1;
				Aocc.push({xx, yy});
				par[xx][yy] = {x,y};
			}
		}
	}

	int finx = -1, finy = -1,findist = 1e9;

	for(int i=0;i<n;i++){
		if(g[i][0] && distA[i][0]>=0 && (distA[i][0]<distM[i][0] || distM[i][0]==-1)){
			finx=i; finy=0;
			findist = min(findist, distA[i][0]);
		}
		if(g[i][m-1] && distA[i][m-1]>=0 && (distA[i][m-1]<distM[i][m-1] || distM[i][m-1]==-1)){
			finx=i; finy=m-1;
			findist = min(findist, distA[i][m-1]);
		}
	}

	for(int i=0;i<m;i++){
		if(g[0][i] && distA[0][i]>=0 && (distA[0][i]<distM[0][i] || distM[0][i]==-1)){
			finx=0; finy=0;
			findist = min(findist, distA[0][i]);
		}
		if(g[n-1][i] && distA[n-1][i]>=0 && (distA[n-1][i]<distM[n-1][i] || distM[n-1][i]==-1)){
			finx=n-1; finy=i;
			findist = min(findist, distA[n-1][i]);
		}
	}

	if(finx == -1) cout<<"NO\n";
	else{
		cout<<"YES\n";
		cout<<findist<<'\n';
	}

}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    // test(t)
    solve();
    
    
    
}