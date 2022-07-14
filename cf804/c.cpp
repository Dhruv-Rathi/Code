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


const ll N = 100010;

ll fact[N];

void pre(){
	fact[0] = 1;
	for(ll i=1;i<N;i++){
	fact[i] = 1LL*fact[i-1]*i%mod;
	}
}


void solve(){
	ll n; cin>>n;
	vll a(n);
	cin>>a;
	vll b = a;
	sort(all(b));
	if(a == b){
		cout<<1<<'\n'; return;
	}
	ll po=-1;
	vll c, d;
	f(i,0,n){
		if(a[i] == 0){
			po = i; continue;
		}
		if(po == -1){
			c.PB(a[i]);
		}else{
			d.PB(a[i]);
		}
	}

	// cout<<c<<'\n'<<d<<'\n';
	map<ll,ll> mp;
	vll me1(c.size());
	ll mex=1;
	for(ll i=c.size()-1;i>=0;i--){
		mp[c[i]]++;
		if(c[i] == mex){
			while(mp[mex]) mex++;
			me1[i] = mex;
		}else{
			me1[i] = mex;
		}
	}

	

	vll me2(d.size());
	mex = 1;
	mp.clear();
	for(ll i=0;i<d.size();i++){
		mp[d[i]]++;
		if(d[i] == mex){
			while(mp[mex]) mex++;
			me2[i] = mex;
		}else{
			me2[i] = mex;
		}
	}

	// cout<<me1<<'\n'<<me2<<'\n';
	bool f = 0;
	for(ll i=0;i<c.size();i++){
		if(me1[i]!=1){
			f = 1;
		}
	}
	if(f == 0){
		swap(me1, me2);
		swap(c,d);
	}

	// cout<<me1<<'\n'<<me2<<'\n';
	
	sort(all(me1));
	ll x = me1[me1.size()-1];
	sort(all(d));
	ll cnt = 0;
	ll i = 0;
	while(me1[i] == 1){
		cnt++; i++;
	}

	// cout<<x<<' '<<y<<'\n';
	ll ans = (fact[cnt]*(cnt))%mod;
	cout<<(ans+mod)%mod<<'\n';

}

void solve2(){
	ll n, l, r, ans = 1;
	cin>>n;

	vll v(n), pos(n);

	for(ll i=0;i<n;i++){
		cin>>v[i];
		pos[v[i]] = i;
	}
	l = r = pos[0];
	for(ll i=1;i<n;i++){
		if(pos[i]<l) l = pos[i];
		else if(pos[i]>r) r = pos[i];
		else ans = ans*(r-l+1 - i) % mod;
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
 		
 	pre();

    ll tc = 1;
    cin>>tc;
    for(int i=1;i<=tc;i++){
    //	cout<<"Case #"<<i<<": ";
    	solve2();
    }
    
}