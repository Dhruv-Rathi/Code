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

/*
6 6
S.#...
......
####.#
E.##.#
..#..#
#....#
*/


int n,m;
vector<string> arr;

// int dx[] = {1,0,-1,0};
// int dy[] = {0,1,0,-1};

int dx[] = {1,1,1,0,-1,-1,-1,0};
int dy[] = {1,0,-1,-1,-1,0,1,1};

// For horse:
// int dx[] = {2,1,-1,-2,-2,-1,1,2};
// int dy[] = {-1,-2,-2,-1,1,2,2,1};

bool inside(int x, int y){
	if(x<0 || x>=n || y<0 || y>=m || arr[x][y]=='#') return 0;
	else return 1;
}

int dist[1010][1010];
void bfs(pii st){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dist[i][j] = 1e9;
		}
	}
	dist[st.F][st.S] = 0;
	queue<pii> q;
	q.push(st);
	while(!q.empty()){
		pii cur = q.front();
		q.pop();
		int curd = dist[cur.F][cur.S];
		for(int k=0;k<8;k++){
			if(!inside(cur.F+dx[k], cur.S+dy[k])) continue;
			pii neigh = {cur.F+dx[k], cur.S+dy[k]};
			if(dist[neigh.F][neigh.S]>curd+1){ // Relaxing condition.
				dist[neigh.F][neigh.S] = curd+1;
				q.push(neigh);
			}
		}
	}
}



void solve(){
	cin>>n>>m;
	arr.resize(n);
	pii st,en;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		for(int j=0;j<m;j++){
			if(arr[i][j] == 'S'){
				st = {i,j};
			}else if(arr[i][j] == 'E'){
				en = {i,j};
			}
		}
	}
	bfs(st);
	cout<<dist[en.F][en.S];
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