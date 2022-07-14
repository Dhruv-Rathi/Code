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



void solve(){
	int n,k; cin>>n>>k;
    vll a(n);

    f(i,0,n){
        cin>>a[i];
    }

    // cout<<odd<<'\n'<<eve<<'\n';

    ll ans = 0;

    ll dp[2][k+1];
    // dp[0][i] -> count of odd element is even and size of the subset is i
    // dp[1][i]-> count is odd elements is odd and size of the subset is i
    

    for(int i=0;i<=k;i++){
        dp[0][i] = dp[1][i] = 0;
    }

    // Base case
    dp[0][0] = 1;
    // count of odd elements is even(i.e. equal to zero) and set size is 0

    for(int i=0;i<n;i++){
        for(int j=k;j>=1;j--){
            if(a[i]%2){
                if(dp[1][j-1]!=0){
                    dp[0][j] += dp[1][j-1]*a[i];
                }
                if(dp[0][j-1]!=0){
                    dp[1][j] += dp[0][j-1]*a[i];
                }
            }else{
                if(dp[0][j-1]!=0){
                    dp[0][j] += dp[0][j-1]*a[i];
                }
                if(dp[1][j-1]!=0){
                    dp[1][j] += dp[1][j-1]*a[i];
                }
            }
            dp[0][j]%=mod;
            dp[1][j]%=mod;
        }
    }

    cout<<dp[0][k]<<'\n';

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