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
#define f(x,a,b) for(ll x=a;x<b;x++)
#define frev(x,a,b) for(ll x=a;x>=b;x--)
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
	int n; cin>>n;
	vii a(n+1); 
	f(i,1,n+1) cin>>a[i];
	int mxp[n+1], mnp[n+1];
	mxp[n] = n, mnp[n] = n;
	for(int i=n-1;i>=0;i--) {
		mxp[i] = a[i]>a[mxp[i+1]]?i:mxp[i+1];
		mnp[i] = a[i]<a[mnp[i+1]]?i:mnp[i+1];
	}

	int ans = 0;

	for(int i=1;i<n;){
		if(a[i+1]>a[i]){
			int p = i+1;
			if(mnp[i]!=i){
				for(int j=i+1;j<=n && a[j]>a[i]; j++) 
					if(a[j]>a[p])p=j;
			}else p=mxp[i+1];
			i = p;
		}else{
			int p = i+1;
			if(mxp[i]!=i){
				for(int j=i+1;j<=n && a[j]>a[i];j++){
					if(a[j]<a[p])p=j;
				}
			}else p=mnp[i+1];
			i=p;
		}
		ans++;
	}
	cout<<ans<<'\n';
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