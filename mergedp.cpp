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
ll n;
vector<ll> arr;

ll dp[501][501];

ll rec(ll l, ll r){
	if(l==r) return 0;
	if(dp[l][r]!=-1) return dp[l][r];

	ll ans = 1e9;
	ll sum = 0;
	for(ll i=l;i<=r;i++){
		sum+=arr[i];
	}
	ll tot=0;
	for(ll mid=l;mid<r;mid++){
		tot+=arr[mid];
		ans = min(ans, rec(l,mid)+rec(mid+1, r)+((tot)%100)*((sum-tot)%100));

	}
	return dp[l][r] = ans;

}

void solve()
{
	cin>>n;
	arr.resize(n);
	rep(i,0,n) cin>>arr[i];
	memset(dp,-1,sizeof(dp));
	cout<<rec(0, n-1)<<'\n';
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