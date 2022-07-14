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

void solve()
{
	ll n,y; cin>>n>>y;
	vi a(n);
	ll ans = 0;
	vi cnt(21,0);
	rep(i,0,n) {
		cin>>a[i];
		for(ll j=0;j<=20;j++){
			if(a[i]&(1<<j)){
				cnt[j]++;
			}
		}
	}

	for(ll i=0;i<=20;i++){
		if(cnt[i]%2==0 && cnt[i]!=0){
			ans+=(1<<i);
		}
	}

	cout<<ans<<'\n';
	

}

void solve2(){
	ll n,y; cin>>n>>y;
	vi a(n);
	ll ans = 0;
	rep(i,0,n) {
		cin>>a[i];
		ans = ans^a[i];
	}


	if(n%2 == 0){
		cout<<0;
		return;
	}

	ll sum = 0;
	for(ll i=0;i<y;i++){
		if(!(ans&(1<<i))){
			sum+=(1<<i);
		}
	}

	cout<<sum<<'\n';

}

void solve1(){
	ll n,m;
	cin>>n>>m;
	ll ans = 0;
	rep(i,0,m){
		ll b;
		cin>>b;
		ans = ans^b;
	}
	if(n%2){
		cout<<(ans+mod)%mod;
	}
	else{
		cout<<0;
	}
}

void solve3(){
	ll l,r;
	cin>>l>>r;
	ll div[r+1]={0};
	for(ll i=1; i<=r;i++){
		for(ll j=1;j*i<=r;j++){
			div[i*j]++;
		}
	}
	ll ans = 0;
	for(ll i=l;i<=r;i++){
		ans+=div[i];
	}
	cout<<ans<<'\n';
}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    // test(t)
    solve2();
    
    
    
}