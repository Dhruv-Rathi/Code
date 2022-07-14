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

int n;

int dx[] = {1,1,1,0,-1,-1,-1,0};
int dy[] = {1,0,-1,-1,-1,0,1,1};

int dx2[] = {2,2,2,0,-2,-2,-2,0};
int dy2[] = {2,0,-2,-2,-2,0,2,2};

int dx3[] = {2,2,-2,-2,1,1,-1,-1};
int dy3[] = {1,-1,-1,1,2,-2,-2,2};

bool vis[3][3];
bool check(int r, int c){
	if(r<0 || r>2 || c<0 || c>2) return false;
	return true;
}


int rec(int level, int r, int c){
	if(level == n){
		return 1;
	}
	int ans = 0;
	vis[r][c] = 1;
	for(int i=0;i<8;i++){
		if(check(r+dx[i],c+dy[i]) && vis[r+dx[i]][c+dy[i]] == 0){
			vis[r+dx[i]][c+dy[i]] = 1;
			ans += rec(level+1, r+dx[i], c+dy[i]);
			vis[r+dx[i]][c+dy[i]] = 0;
		}
	}

	for(int i=0;i<8;i++){
		if(check(r+dx2[i],c+dy2[i]) && vis[r+dx2[i]][c+dy2[i]] == 0 && vis[r+dx[i]][c+dy[i]] == 1){
			
			vis[r+dx2[i]][c+dy2[i]] = 1;
			ans += rec(level+1, r+dx2[i],c+dy2[i]);
			vis[r+dx2[i]][c+dy2[i]] = 0;
		}
	}

	for(int i=0;i<8;i++){
		if(check(r+dx3[i],c+dy3[i]) && vis[r+dx3[i]][c+dy3[i]] == 0){
			vis[r+dx3[i]][c+dy3[i]] = 1;
			ans += rec(level+1, r+dx3[i], c+dy3[i]);
			vis[r+dx3[i]][c+dy3[i]] = 0;
		}
	}
	vis[r][c] = 0;
	return ans;
}



void solve(){
	cin>>n;
	f(i,0,3){
		f(j,0,3){
			vis[i][j] = 0;
		}
	}
	int ans = 0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			ans+=rec(1,i,j);
		}
	}
	
	cout<<ans<<'\n';
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