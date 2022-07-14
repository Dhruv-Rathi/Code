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

// int a[101];
// int dp[101][100100];


// void solve(){
// 	int n,k; cin>>n>>k;
// 	for(int i=0;i<n;i++) {
// 		cin>>a[i];
// 	}

// 	for(int i=0;i<=a[0];i++){
// 		dp[0][i] = 1;
// 	}

// 	for(int i=1;i<n;i++){
// 		vll prefix_sum(k+1);
// 		prefix_sum[0] = dp[i-1][0];
// 		for(int j=1;j<k+1;j++){
// 			prefix_sum[j] = ((prefix_sum[j-1]%mod)+(dp[i-1][j]%mod))%mod;
// 		}
// 		for(int j=0;j<k+1;j++){
// 			if(j>a[i])
// 				dp[i][j] = ((prefix_sum[j]%mod) - (prefix_sum[j-a[i]-1]%mod))%mod;
// 			else
// 				dp[i][j] = prefix_sum[j]%mod;

// 			dp[i][j] = (dp[i][j]+mod)%mod;
// 		}
// 	}

// 	cout<<(dp[n-1][k]+mod)%mod;

// }

ll dp[404][404]; // dp[l][r] = answer for [l....r];

ll sum[404][404];

// dp[i][i] = 0 for all i
// sum[i][i] = a[i];

// transitions:
// dp[l][r] = min(dp[l][x]+dp[x+1][r]+size of [l....r]);

void solveN(){
	ll n; cin>>n;
	ll a[n];
	f(i,0,n){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		dp[i][i] = 0;
		sum[i][i] = a[i];
	}

	for(int width=2;width<=n;width++){
		for(int l=0,r = width-1;r<n;l++,r++){
			sum[l][r] = a[l]+sum[l+1][r];
			dp[l][r] = 1e18;
			for(int x = l;x<r;x++){
				dp[l][r] = min(dp[l][r], dp[l][x]+dp[x+1][r]+sum[l][r]);
			}
		}
	}

	cout<<dp[0][n-1];

}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    // test(t)
    solveN();
    
    
    
}