#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod (ll)1e8
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
int k1,k2;
int dp[101][101][2];

int rec(int n1, int n2, int f){
	if(n1 + n2 == 0)
       return 1;
   if(dp[n1][n2][f] != -1)
       return dp[n1][n2][f];

   dp[n1][n2][f]=0;
	if(f==0){
       for(int i = 1; i <= min(n1,k1); ++i) {
           dp[n1][n2][f] = (dp[n1][n2][f] + rec(n1-i,n2,1-f))%mod;
       }
   }
   else{
       for (int i = 1; i <= min(n2,k2); ++i) {
           dp[n1][n2][f] = (dp[n1][n2][f] + rec(n1,n2-i,1-f))%mod;
       }
   }
   return dp[n1][n2][f];
}

void solve()
{
	int n1,n2;
	cin>>n1>>n2>>k1>>k2;
	for(int i=0;i<=n1;++i){
		for(int j=0;j<=n2;++j){
			dp[i][j][0] = dp[i][j][1] = -1;
		}
	}
	cout<<((rec(n1,n2,0)+rec(n1,n2,1)))%mod<<"\n";
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