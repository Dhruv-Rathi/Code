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
#define int long long
 
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}
ll n,m,k;
ll arr[101][101];
ll dp[101][101][11];
vector<string> v;

ll rec(ll i, ll j, ll r){
	if(i == 0){
		if((r+arr[i][j])%k==0)
			return arr[i][j];
		return -1e9;
	}
	if(dp[i][j][r]!=-1) return dp[i][j][r];
	ll ans = INT_MIN;
	if(i-1>=0 && j-1>=0){
		ans = max(ans, rec(i-1, j-1, ((r+arr[i][j])%k))+arr[i][j]);
	}
	if(i-1>=0 && j+1<m){
		ans = max(ans, rec(i-1, j+1, ((r+arr[i][j])%k))+arr[i][j]);
	}

	return dp[i][j][r] = ans;

}
void solve()
{
	cin>>n>>m>>k;
    memset(dp, -1, sizeof(dp));
    v.resize(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
        for(int j=0; j<m; j++){
            arr[i][j]=v[i][j]-'0';
        }
    }

    int ans=-1e9;
    for(int i=0; i<m; i++){
        ans=max(ans, rec(n-1, i, 0));
    }

    if(ans<0){
        cout<<"-1";
    }

    else cout<<ans;
    cout<<'\n';

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