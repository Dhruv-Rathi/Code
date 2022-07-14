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

vll t;
ll n,m,c;

bool check(ll x){

	ll cnt = 1, prev = 0, cur = 0;
	for(int i=0;i<n;i++){
		ll wait_time = t[i] - t[prev];
		if(wait_time<=x && cur+1<=c){
			cur++;
		}else{
			cur = 1; prev = i;
			cnt++;
		}
	}

	return cnt<=m ;
}

void solve(){
	cin>>n>>m>>c;
	t.assign(n,0);
	f(i,0,n) cin>>t[i];
	sort(all(t));
	ll lo = 0, hi = t[n-1]-t[0];
	ll ans = hi;
	while(lo<hi){
		ll mid = (lo+hi)/2;
		if(check(mid)){
			ans = mid;
			hi = mid-1;
		}else {
			lo = mid+1;
		}
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
    // cin>>tc;
    for(int i=1;i<=tc;i++){
    //	cout<<"Case #"<<i<<": ";
    	solve();
    }
    
}