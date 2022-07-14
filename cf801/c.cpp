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
	int n,m; 
	cin>>n>>m;
	int a[n][m];
	f(i,0,n){
		f(j,0,m){
			cin>>a[i][j];
		}
	}
	if((n+m)%2 == 0){
		no; return;
	}
	ll dp1[n][m], dp2[n][m];
	f(i,0,n){
		if(i) dp1[i][0] = a[i][0]+dp1[i-1][0];
		else dp1[i][0] = a[i][0];
		dp2[i][0] = dp1[i][0];
	}
	f(i,0,m){
		if(i) dp1[0][i] = a[0][i]+dp1[0][i-1];
		else dp1[0][i] = a[0][i];
		dp2[0][i] = dp1[0][i];

	}

	f(i,1,n){
		f(j,1,m){
			dp1[i][j] = a[i][j]+max(dp1[i-1][j], dp1[i][j-1]);
			dp2[i][j] = a[i][j]+min(dp2[i-1][j], dp2[i][j-1]);
		}
	}
	// cout<<dp2[n-1][m-1]<<' '<<dp1[n-1][m-1]<<'\n';
	if(dp2[n-1][m-1]>0 || dp1[n-1][m-1]<0)
		no;
	else yes;

}
 
signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    ll tc = 1;
    cin>>tc;
    for(int i=1;i<=tc;i++){
    //	cout<<"Case #"<<i<<": ";
    	solve();
    }
    
}