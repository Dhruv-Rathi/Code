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

string s;
vll a;
ll ans;
ll dp[3010][3010];

void add_self(ll& a, ll b){
	a+=b;
	if(a>=mod){
		a-=mod;
	}
}

void solve(){
	ll n; cin>>n;
	cin>>s;
	ans = 0;
	dp[1][1] = 1;
	for(ll len=2;len<=n;len++){
		for(ll i=1;i<=len-1;i++){
			dp[len-1][i] = (dp[len-1][i]+dp[len-1][i-1])%mod;
		}
		for(ll b=1;b<=len;b++){
			ll L, R;
			if(s[len-2] == '<'){
				L = 1, R = b-1;
			}
			else{
				L = b, R = len-1;
			}
			if(L<=R){
				add_self(dp[len][b],(dp[len-1][R]-dp[len-1][L-1]+mod)%mod);
			}
		}
	}
	for(ll b=1;b<=n;b++){
		add_self(ans, dp[n][b]);
	}

	cout<<ans;

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