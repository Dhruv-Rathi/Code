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

int h,w;
char arr[1010][1010];
ll dp[1010][1010];

ll rec(int i, int j){

	if(i>=h || j>=w || arr[i][j]=='#') return 0;

	if((i==h-1)&&(j==w-1)) return 1;

	if(dp[i][j]!=-1) return dp[i][j];

	ll ans = 0;
	if(arr[i][j] == '.'){
		if(i+1<h && arr[i+1][j]=='.'){
			ans = ((ans)%mod+(rec(i+1,j)%mod))%mod;
		}
		if(j+1<w && arr[i][j+1]=='.'){
			ans = ((ans)%mod+(rec(i,j+1)%mod))%mod;
		}
	}

	return dp[i][j] = ans;

}


void solve(){

	cin>>h>>w;
	f(i,0,h){
		f(j,0,w){
			cin>>arr[i][j];
			dp[i][j] = -1;
		}
	}

	ll ans = rec(0,0)%mod;

	cout<<(ans+mod)%mod;
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