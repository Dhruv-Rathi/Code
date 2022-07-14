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

map<pair<int, int >, int> dp;
int w,h,n;

bool check(int i, int j){
    if(i<0 || j<0 || i>=w || j>=h) return 0;
    return 1;
}

int bfs(int mask){
    int dist[w][h];
    memset(dist,-1,sizeof(dist));

    int ma = 0;
    queue<pair<int, int>> q;

    for(int i=0;i<w; i++){
        for(int j=0;j<h;j++){
            if(mask&(1<<(w<=h?(i+w*j):(h*i+j)))){
                dist[i][j] = 0;
                q.push({i,j});
            }
        }
    }

    while(!q.empty()){
        int x = q.front().F;
        int y = q.front().S;
        ma = max(ma, dist[x][y]);
        q.pop();
        for(int d=0; d<4; d++){
            int nx = x+dx[d], ny = y+dy[d];
            if(check(nx,ny) && dist[nx][ny] == -1){
                dist[nx][ny] = 1+dist[x][y];
                q.push({nx, ny});
            }
        }
    }

    return ma;
}

int rec(int mask, int left){
    if(left == 0){
        return bfs(mask);
    }

    if(dp.find({mask, left})!=dp.end()){
        return dp[{mask, left}];
    }
    int minD = INT_MAX;
    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            if(!(mask&(1<<(w<=h?(i+w*j):(h*i+j))))){
                int t = rec((mask|(1<<(w<=h?(i+w*j):(h*i+j)))),left-1);
                minD = min(minD, t);
            }
        }
    }

    return dp[{mask, left}] = minD;
}

void solve(){
    dp.clear();
    cin>>w>>h>>n;

    cout<<rec(0,n);

}

void solve2(){
    int n; cin>>n;
    map<string, string> mp;
    for(int i=0;i<n;i++){
        string a; string s;

        cin>>a>>s;
        // cout<<a<<' '<<s<<'\n';
        mp[s] = a;
    }

    string st; cin>>st;
    int len = st.length();
    string nline = "[newline]";
    string s="";
    for(int i=0;i<len;i++){
        s+=st[i];
        if(mp.find(s) != mp.end()){
            if(mp[s] == nline) cout<<'\n';
            else cout<<mp[s];
            s = "";
        }
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
    // cin>>tc;
    for(int i=1;i<=tc;i++){
    //  cout<<"Case #"<<i<<": ";
        solve();
    }

}