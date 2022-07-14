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
	vll a(2*n);
	ll o = 0, e = 0;
	vll ev;
	f(i,0,2*n){
		cin>>a[i];
		if(a[i]%2) o++;
		else {e++; ev.PB(a[i]);}
	}
	if(o == e){
		cout<<"0\n"; return;
	}
	if(o>e){
		ll x = (o-e)/2;
		cout<<x<<'\n'; return;
	}
	

	ll ans = 0; 
	vll b;
	for(auto x: ev){
		ll cnt = 0;
		while(x%2 == 0){
			x/=2;  cnt++;
		}
		b.PB(cnt);
	}
	sort(all(b));
	ll z = (e-o)/2;
	f(i,0,z){
		ans+=b[i];
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