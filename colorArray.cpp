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
ll arr[101], p[101][101], dp[101][101][101];
pair<ll,ll> m1[101][101], m2[101][101];

void solve()
{
	cin>>n>>m>>k;
	rep(i,1,n+1) cin>>arr[i];
	rep(i,1,n+1){
		rep(j,1,m+1){
			cin>>p[i][j];
		}
		if(arr[i])
			p[i][arr[i]] = 0;
	}
	rep(i,0,n+1){
		rep(j,0,k+1){
			m1[i][j] = m2[i][j] = {1e18, 1e18};
			rep(l,0,m+1){
				dp[i][j][l] = 1e18;
			}
		}
	}
	m1[0][0] = m2[0][0] = {0,-1};
	rep(i,1,n+1){
		rep(j,1,min(i,k)+1){
			rep(l,1,m+1){
				if(arr[i] && arr[i]!=l) continue;
				ll cur = m1[i-1][j-1].ff;
				if(m1[i-1][j-1].ss == l){
					cur = m2[i-1][j-1].ff;
				}
				dp[i][j][l] = min(cur, dp[i-1][j][l])+p[i][l];
				if(dp[i][j][l]<m1[i][j].ff) {
					m2[i][j] = m1[i][j];
					m1[i][j] = {dp[i][j][l], l};
				}
				else if(dp[i][j][l] < m2[i][j].ff) {
					m2[i][j] = {dp[i][j][l], l};
				}
			}
		}
	}

	ll ans = 1e18;
	rep(i,1,m+1){
		ans = min(ans, dp[n][k][i]);
	}
	if(ans == (ll)1e18) ans = -1;
	cout<<ans<<'\n';

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