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
	ll n,m,k;
	ll tot = 0;
	cin>>n;
	ll a[n];
	f(i,0,n){
		cin>>a[i];
		tot+=a[i];
	}
	ll p1[n+1]={0};
	p1[0] = 0;
	f(i,1,n+1){
		p1[i] = p1[i-1]+a[i-1];
		// cout<<p1[i]<<' ';
	}
	
	cin>>m;
	ll b[m];
	f(i,0,m){
		cin>>b[i];
		tot+=b[i];
	}
	ll p2[m+1]={0};
	p2[0] = 0;
	f(i,1,m+1){
		p2[i] = p2[i-1]+b[i-1];
		
	}
	
	cin>>k;
	if(k == n+m){
		cout<<tot<<'\n'; return;
	}
	ll mi = 1e18;
	k = (n+m-k);
	f(i,0,k+1){
		if(i>n) break;
		ll mi1 = p1[i];
		f(j,i+1,n+1){
			mi1 = min(mi1, p1[j]-p1[j-i]);
		}
		if(k-i > m) continue;
		ll mi2 = p2[k-i];
		f(j,k-i+1,m+1){
			mi2 = min(mi2, p2[j] - p2[j-(k-i)]);
		}
		mi = min(mi, mi1+mi2);
	}
	cout<<(tot-mi)<<'\n';
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
    	cout<<"Case #"<<i<<": ";
    	solve();
    }
    
}