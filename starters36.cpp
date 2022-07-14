#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define vi vector<ll>
#define vvi vector<vi>
#define f(x,a,b) for(int x=a;x<b;x++)
#define pb push_back
#define eb emplace_back //faster than push_back
#define mod1 1000000007
#define mod2 998244353
#define ss second
#define ff first
#define all(a) a.begin(), a.end()
#define vecpii vector<pair<int,int>>
#define test(t) int tc; cin>>tc; while(tc--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}
ll r;
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
bool comp(const pair<int,int> &a,const pair<int,int> &b){
	if((a.ff - a.second) == (b.ff - b.second)){
		return a.ff < b.ff;
	}
	return ((a.ff - a.second) < (b.ff - b.second));}
ll power(ll a, ll b, ll N){ ll p = 1;
    while (b > 0){
        if (b & 1) p = ((p % N) * (a % N)) % N;
        a = ((a % N) * (a % N)) % N; b /= 2;
    } return p;
}

const int N = 500010;

int fact[N];

void pre(){
	fact[0] = 1;
	for(int i=1;i<N;i++){
	fact[i] = 1LL*fact[i-1]*i%mod;
	}
}

int ncr(int n, int r){
	if(n<r) return 0;
	int ans = fact[n];
	ans = 1LL*ans*power(fact[n-r],mod-2,mod)%mod;
	ans = 1LL*ans*power(fact[r],mod-2,mod)%mod;
	ans = (ans+mod)%mod;
	return ans;
}

void solve(){
	ll n; cin>>n;
	ll ans = (n/5)*4;
		ans+=(n%5);
	cout<<ans<<'\n';

}

void solve2(){
	int n; cin>>n;
	int a[n];
	ll e = 0, o = 0;
	f(i,0,n) {
		cin>>a[i];	
	}
	sort(a,a+n);
	for(ll i=n-1;i>=0;i--){

	}
	cout<<max(e,o)<<'\n';

}

void solve3(){
	ll n; cin>>n>>r;
	ll a[n];
	f(i,0,n){
		cin>>a[i];
	}
	ll b[n];
	f(i,0,n) cin>>b[i];
	vector<pair<ll,ll>> v(n);
	f(i,0,n){
		v[i].ff = a[i];
		v[i].ss = b[i];
	}
	sort(all(v), comp);
	// reverse(all(v));
	ll sum = 0;
	f(i,0,n){
		if(r<v[i].ff) {
			i++; continue;
		}
		ll x;
		x = (r-v[i].ff)/(v[i].ff - v[i].ss);
		sum+=x;
		r = r - x*(v[i].ff - v[i].ss);
		while(r>=v[i].ff){
			r = r - v[i].ff + v[i].ss;
			sum++;
		}
		
	}
	
	cout<<sum<<'\n';

}

void solve4(){
	ll n; cin>>n;
	if(n == 1){
		cout<<0<<'\n'; return;
	}
	if(n%2){
		cout<<1<<'\n'; return;
	}
	ll d = 0;
	while(n%2 == 0){
		n/=2;
		d++;
	}
	if(d%2){
		cout<<-1<<'\n'; return;
	}
	cout<<2<<'\n';
}

	
 
signed main()
{
    fast
    

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    test(t)
    solve3();
    
    
    
}