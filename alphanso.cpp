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


int m,n;
vii g[100100];

int gcd(int a, int b){
	if(a==0||b==0) return a^b;
	else return gcd(b, a%b);
}

int dp[100100][20];



int dfs(int node, int gc, int par){

	if(dp[node][gc]!=-1) return dp[node][gc];


	int ans = 0;
	for(int col=1;col<=m;col++){
		int temp = 1;
		int cntch = 0;

		for(auto v: g[node]){
			if(v!=par){
				cntch++;
				temp*=dfs(v, gcd(gc,col), par);
			}
		}
		if(cntch == 0){
			if(gcd(temp,col) == 1){
				ans++;
			}
		}else{
			ans+=temp;
		}
	}
	return dp[node][gc] = ans;
}

void solve(){
	
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