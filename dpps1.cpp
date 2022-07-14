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
ll n, m;
ll arr[1010][1010];
ll dp[1010][1010];

bool check(int x, int y){
	if(x>=n || y>=m) return 0;
	return 1;
}

ll rec(ll r, ll c){
	if(r==n-1 && c==m-1 )
		return arr[r][c];
	if(dp[r][c]!=-1) return dp[r][c];
	ll ans = 0;
	if(check(r+1,c)){
		ans = max(ans, rec(r+1,c)+arr[r][c]);
	}
	if(check(r,c+1)){
		ans = max(ans, rec(r,c+1)+arr[r][c]);
	}
	return dp[r][c] = ans;
}

void solve()
{
	cin>>n>>m;
	rep(i,0,n){
		rep(j,0,m) {
			cin>>arr[i][j];
			dp[i][j] = -1;
		}
	}

	cout<<rec(0,0)<<'\n';

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