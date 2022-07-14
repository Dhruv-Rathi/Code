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

ll n,m,b;
ll dp[2][505][505];

void solve(){
	cin>>n>>m>>b;
	ll a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	f(i,0,2){
		f(j,0,m+1){
			f(k,0,b+1){
				dp[i][j][k] = 0;
			}
		}
	}

	dp[0][0][0] = 1;

	f(i,1,n+1){
		f(j,0,m+1){
			f(k,0,b+1){
				dp[i&1][j][k] = dp[(i-1)&1][j][k];
				if(j && k>=a[i-1]){
					dp[i&1][j][k] = (dp[i&1][j][k]+dp[i&1][j-1][k-a[i-1]])%mod;
				}
			}
		}
	}

	ll ans = 0;
	f(i,0,b+1){
		ans = (ans+dp[n&1][m][i])%mod;
	}

	cout<<(ans+mod)%mod<<'\n';

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