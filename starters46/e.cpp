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
	vector<pair<ll,ll>> a(2*n); 
	for(ll i=0;i<2*n;i++){
		ll x; cin>>x;
		a[i].F = x; a[i].S = i;
	}
	sort(all(a));

	ll ans = 2*n;
	ll x = 0, cnt = n;
	map<ll,ll> mp;
	for(ll i = 0; i<2*n; i++){
		if(a[i].S+1 == a[i+1].S){
			ll z = a[i].F-1;
			while(z>=1 && mp[z]>0){
				cnt--; z--;
			}
			x+=2*(cnt-1); i++;
			cnt--;
		}else{
			if(mp[a[i].F]){
				x+=(cnt-1);
				cnt--;
			}else{
				mp[a[i].F]++;
			}
		}
	}
	// cout<<x<<'\n';
	if(x>0)
		ans+=2*x;
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