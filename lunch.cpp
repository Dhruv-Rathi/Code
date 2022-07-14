#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// #define mod 1000000007
#define vi vector<ll>
#define vvi vector<vi>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define ss second
#define ff first
#define all(arr) arr.begin(), arr.end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test(t) ll t;cin>>t;while(t--)
 
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}


ll fact[10000000]={0};

void factorial(){
	ll mod = 998244353;
	ll p = 1;
	fact[0] = 1;
	for(ll i=1;i<=(10000000-1);i++){
		fact[i] = ((fact[i-1]%mod)*(i%mod))%mod;
	}
}

ll power(ll a,ll b){
	ll mod = 998244353;
	ll p=1;
	while(b>0){
		if(b&1) p = ((p%mod)*(a%mod))%mod;
		a = ((a%mod)*(a%mod))%mod;
		b/=2;
	}
	return p;
}

void solve3(){
	ll n;
	cin>>n;
	if(n==1){
		cout<<1<<'\n';
		return;
	}
    
	ll mod = 998244353 ;
	n = n%mod;
	
	ll ans = ((n%mod)*(n%mod))%mod;
	ans = ((ans%mod)*((n+1)%mod))%mod;
	ans = ((ans%mod)*((n+1)%mod))%mod;
	ll den = (4)%mod;
	ll inv = power(den, mod-2)%mod;
	ans = ((ans%mod)*(inv%mod))%mod;
	ans = (((n-1)%mod)*(ans%mod))%mod;
	cout<<(ans+mod)%mod<<'\n';

}
signed main()
{
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    // factorial();
 
    test(t)
    solve3();
    
    
    
}