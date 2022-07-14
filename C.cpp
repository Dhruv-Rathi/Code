#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000009
#define vi vector<ll>
#define vvi vector<vi>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define ss second
#define ff first
#define all(arr) arr.begin(), arr.end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test(t) ll t;cin>>t;while(t--)
#define int long long int 
ll power(ll a, ll b){
	ll p=1;
	while(b>0){
		if(b&1) p = (p%mod * a%mod)%mod;
		a = (a%mod * a%mod)%mod;
		b/=2;

	}
	return p;
}
ll inv(ll a){
	a = a%mod;
	if(a<0) a+=mod;
	ll b = mod, u = 0, v = 1;
	while(a){
		ll t = b/a;
		b-=t*a; swap(a,b);
		u-=t*v; swap(u,v);

	}
	assert(b==1);
	if(u<0) u+=mod;
	return u;
}
ll mul(ll a, ll b){
	return (a%mod * b%mod)%mod;
}


void solve3(){
	ll a,b,n;
	cin>>a>>b>>n;
	ll ans = 0;
	ans = power(a,n)%mod;
	ll p = 0;
	p = mul((ans-1)%mod, inv((a-1)%mod));
	p = mul(p, b);
	ans = (ans+p%mod)%mod;
	cout<<(ans+mod)%mod<<'\n';
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