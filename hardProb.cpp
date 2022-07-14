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

void solve(){
	cin>>n>>s;
	ll a[n];
	rep(i,0,n) cin>>a[i];
	ll dp[4]={0};
	for(int i=0;i<n;i++){
		if(s[i] == 'h') dp[0] += a[i];
		else if(s[i] == 'a') dp[1] = min(dp[0], dp[1]+a[i]);
		else if(s[i] == 'r') dp[2] = min(dp[1], dp[2]+a[i]);
		else if(s[i] == 'd') dp[3] = min(dp[2], dp[3]+a[i]);
	}

	cout<<dp[3]<<'\n';
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