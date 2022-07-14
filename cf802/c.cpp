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
	ll po = 0, ne = 0;
	vll a(n); cin>>a;
	ll mi = a[0], sum = 0;
	vpll b;
	f(i,0,n){

		mi = min(mi, a[i]);
		sum+=a[i];
		if(a[i]>0) po++;
		else if(a[i]<0) ne++;
	}
	if(po == 0 && ne == 0){
		cout<<0<<'\n'; return;
	}
	ll ans = 0;
	if(mi<0){
		mi = mi*(-1);
		f(i,0,n){
			a[i]+=mi;
			sum+=mi;
		}
		ans+=mi;
		if(sum == 0 && po == 0){
			cout<<mi<<'\n'; return;
		}
		mi = 0;
		// cout<<a<<'\n';
	}

	// cout<<a<<'\n';
	f(i,0,n){
		b.PB({a[i],i});
	}
	sort(all(b));
	ll pre = 0;
	f(i,0,n){
		// cout<<b[i].F<<' '<<b[i].S<<'\n';
		if(i == 0){
			pre = b[i].F;
			ans+=(b[i].F)*(b[i].S+1);
		}else{
			ans+=(b[i].F - pre)*(b[i].S+1);
			pre = (b[i].F - pre);
		}
	}
	cout<<ans<<'\n';

}

void solve2(){
	ll n; cin>>n;
	vll a(n); cin>>a;
	frev(i,n-1,1){
		a[i]-=a[i-1];
	}
	ll ans = 0;
	frev(i,n-1,1){
		if(a[i]<0){
			a[0]-=abs(a[i]);
			ans+=abs(a[i]);
		}else{
			ans+=a[i];
		}
	}
	ans+=abs(a[0]);
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
    	solve2();
    }
    
}