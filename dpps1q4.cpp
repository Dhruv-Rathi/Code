#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define vi vector<ll>
#define vvi vector<vi>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define ss second
#define ff first
#define all(arr) arr.begin(), arr.end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test(t) ll t;cin>>t;while(t--)
 
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}
ll n,m,k;
ll dp[2020][2020];
ll rec(ll i, ll x){
	if(x>k) return 0;
	if(i==n){
		if(x==k) return 1;
		return 0;
	}
	if(dp[i][x] != -1)
		return dp[i][x];
	ll ans = rec(i+1, x)%mod;
	ans = ans + (((m-1)%mod) * (rec(i+1, x+1)%mod))%mod;
	ans = ans%mod;
	return dp[i][x] = ans;
}
void solve()
{
	memset(dp,-1,sizeof(dp));
	cin>>n>>m>>k;
	cout<<(((m%mod)*(rec(1,0)%mod))%mod + mod)%mod<<'\n';
}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    test(t)
    solve();
    
    
    
}