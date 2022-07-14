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
string s;
ll n;
ll dp[1010][1010];

ll rec(ll level,ll sum){
	if(sum<0) return 0;
	if(level == n){
		if(sum==0)
			return 1;
		return 0;
	}
	if(dp[level][sum]!=-1) return dp[level][sum];
	ll ans = 0;
	if(s[level] == '?'){
		ans = (ans+rec(level+1,sum+1))%mod;
		if(sum>=1){
			ans = (ans+rec(level+1, sum-1))%mod;
		}
	}
	else if(s[level] == '('){
		ans = rec(level+1, sum+1)%mod;
	}
	else{
		if(sum>=1){
			ans = rec(level+1, sum-1)%mod;
		}
	}

	return dp[level][sum] = ans%mod;
}

void solve()
{
	cin>>s;
	n = s.length();
	

	// cout<<arr<<'\n';
	memset(dp,-1,sizeof(dp));
	cout<<((rec(0,0)%mod) + mod)%mod<<'\n';
	
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