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

vll a;
ll ans = 0;
ll dp[3010][3010][2];

ll rec(ll i, ll j, ll turn){
	if(i>j) return 0;
	if(dp[i][j][turn]!=-1) return dp[i][j][turn];
	if(turn == 1){
		return dp[i][j][turn] = max(a[i]+rec(i+1,j,0), a[j]+rec(i,j-1,0));
	}else{
		return dp[i][j][turn] = min(rec(i+1,j,1), rec(i,j-1,1));
	}
}

void solve(){
	ll n;                                                                                                                           
	cin>>n; ll s = 0;
	a.resize(n);
	f(i,0,n){
		cin>>a[i];
		s+=a[i];
	}

	memset(dp,-1,sizeof(dp));

	ll ans = rec(0,n-1,1);

	cout<<(2*ans-s);

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