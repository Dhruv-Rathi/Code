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
#define frev(x,a,b) for(int x=a;x>=b;x--)
#define PB push_back
#define MP make_pair
#define S second
#define F first
#define all(a) (a).begin(), (a).end()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define yesorno(x) cout<<((x)?"YES":"NO")<<"\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <class T> ostream &operator<<(ostream &os, const vector<T> a){ for (auto ele : a) os << ele << " "; return os;} 
template <class T> istream &operator>>(istream &is, vector<T> &a){ for (auto &ele : a) is >> ele; return is; }


void solve(){
	ll n; cin>>n;
	vll a(n);
	cin>>a;
	ll ans = 0;
	vll pre(n+1,0);
	f(i,1,n+1){
		if(a[i-1]<i){
			if(a[i-1]){
				ans+=pre[a[i-1]-1];
			}
			pre[i] = 1;
		}
		pre[i] += pre[i-1];
	}

	cout<<ans<<'\n';

}

ll n,k;
ll a[100100];
ll dp[100100][31];
ll po2[32];

ll rec(ll l, ll cnt){
	if(l == n) return 0;
	if(cnt>30) return 0;
	if(dp[l][cnt]!=-1) return dp[l][cnt];

	ll ans = 0;
	ans = max(rec(l+1,cnt)+(a[l])/po2[cnt]-k, rec(l+1, cnt+1)+ (a[l])/po2[cnt+1]);

	return dp[l][cnt] = ans;

}

void solve2(){
	
	
	cin>>n>>k;
	f(i,0,n){
		cin>>a[i];
		f(j,0,31) dp[i][j] = -1;
	}

	cout<<rec(0,0)<<'\n';
}
 
signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif


 	po2[0] = 1;
	f(i,1,32){
		po2[i] = 2*po2[i-1];
	}

    ll tc = 1;
    cin>>tc;
    for(int i=1;i<=tc;i++){
    //	cout<<"Case #"<<i<<": ";
    	solve();
    }
    
}