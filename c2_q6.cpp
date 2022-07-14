#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007
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

ll fact[1000100]={0};
void factorial(){
	ll p = 1;
	fact[0] = 1;
	for(ll i=1;i<1000001;i++){
		fact[i] = ((fact[i-1]%mod)*(i%mod))%mod;
	}
}
ll power(ll a,ll b){
	ll p=1;
	while(b>0){
		if(b&1) p = ((p%mod)*(a%mod))%mod;
		a = ((a%mod)*(a%mod))%mod;
		b/=2;
	}
	return p;
}
void solve()
{
	ll n,m,k;
	cin>>n>>m>>k;

	if(n<=m){
		if(k<n){
			cout<<"0\n";
			return;
		}
		if(n == m && n == k){
			cout<<fact[k]<<'\n';
			return;
		}
		ll f = fact[k]%mod;
		ll inv  = power(fact[k-n], mod-2)%mod;

		// cout<<fact[k-n]<<'\n'<<inv<<'\n';
		f = (f*inv)%mod;
		cout<<((f+mod)%mod)<<'\n';
		return;
	}
	else{
		if(k<=m){
			cout<<"0\n";
			return;
		}
		
		ll ans = fact[k];
		ans = ((ans%mod)*(power((k-m)%mod, (n-m)%mod) %mod))%mod;
		ans = ((ans%mod)*(power(fact[k-m], mod-2)%mod))%mod;
		cout<<(ans+mod)%mod<<'\n';

	}
}

void solve3(){
	ll x,y;
	cin>>x>>y;
	rep(i,0,y){
		ll a,b;
		cin>>a>>b;
		
	}
}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    factorial();
 
    test(t)
    solve();
    
    
    
}