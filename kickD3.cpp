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

ll n;
map<ll,vll> mp;
vll a;
ll dp[2501][2501];

ll rec(ll l, ll pre){
	if(l == n) return 0;

	if(dp[l][pre]!=-1) return dp[l][pre];
	ll ans = 1e9;
	auto it = upper_bound(all(mp[a[l]]),pre);
	if(it!=mp[a[l]].end()){
		ll x = *it;
		ans = min(ans, abs(x-pre)+rec(l+1, x));
	}
	if(it!=mp[a[l]].begin()){
		it--;
		ll x = *it;
		ans = min(ans, abs(x-pre)+rec(l+1, x));
	}
	// for(auto e: mp[a[l]]){
	// 	ans = min(ans, abs(e-pre)+rec(l+1,e));
	// }
	return dp[l][pre] = ans;
}

void solve(){
	mp.clear();
	cin>>n;
	a.assign(n,0);
	cin>>a;
	ll m; cin>>m;
	f(i,0,m){
		ll b; cin>>b;
		mp[b].PB(i);
	}
	f(i,0,n){
	    f(j,0,m) dp[i][j]=-1;
	}
	ll ans = 1e9;
	for(auto e: mp[a[0]]){
		ans = min(ans, rec(1,e));
	}
	cout<<ans<<'\n';
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
    	cout<<"Case #"<<i<<": ";
    	solve();
    }
    
}