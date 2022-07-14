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
	ll n,l,x;
	cin>>n>>l>>x;
	ll ans = min(l,n-l);
	cout<<(ans*x)<<'\n';
	
}

void solve2(){
	ll n; cin>>n;
	ll a[n];
	rep(i,0,n) cin>>a[i];
	ll ans = 0;
	for(ll i=0;i<n;i++)
	{
		ll cnt = 0;
		for(ll j=0;j<n;j++){

			if(i!=j){
				if(a[i]>=a[j])
					cnt++;
			}
		}
		if(cnt>=n/2)
			ans++;
	}
	cout<<ans<<'\n';
}

void solve3(){
	ll n; cin>>n;
	if(n == 1 || n == 2){
		cout<<1<<'\n';
		return ;
	}
	ll ans = 1;
	ans+=(n-2)*(n-1);
	cout<<ans<<'\n';	
}

void solve4(){
	ll n; cin>>n;
	ll c[n];
	rep(i,0,n) cin>>c[i];
	vi zero, one;
	for(ll i = 0;i<n;i+=2){
		zero.pb(c[i]);
	}
	for(ll i = 1;i<n;i+=2){
		one.pb(c[i]);
	}
	sort(zero.rbegin(), zero.rend());
	sort(one.begin(), one.end());
	ll sum = 0;
	rep(i,0,n)
	{
		if(i%2 == 0){
			cout<<zero[i/2]<<' ';
		}else{
			sum+=one[i/2];
			cout<<one[i/2]<<' ';
		}
	}

	ll ans = 0;
	for(ll i = 0; i<one.size();i++){
		ans+=zero[i]*sum;
		sum-=one[i];
	}
	cout<<'\n';
	cout<<ans<<'\n';
}

void solve5(){
	ll n; cin>>n;
	ll x,y;
	map<ll,ll> m;
	rep(i,1,n+1){
		cin>>x>>y;
		m[x] = y;
	}
	ll cnt = 0;
	x = 1, y = m[1];
	bool flag = true;
	for(ll i=2;i<=n;i++){
		if(abs(m[i] - m[i-1])!=1){
			flag = false;
		}

	}
	if(flag){
		cout<<"NO\n";
		return;
	}
	flag = true;
	
	
}

void solve6(){
	ll n; cin>>n;
	ll x,y;
	vi cnt(2*n+1);
	rep(i,0,n){
		cin>>x>>y;
		cnt[x+y]++;
	}
	for(ll i=2; i<=n; i++){
		if(cnt[i] == i-1){
			cout<<"NO\n";
			return;
		}
	}
	ll c = n;
	for(ll i = n+1; i<=(2*n) ;i++, c--){
		if(cnt[i] == c){
			cout<<"NO\n";
			return;
		}
	}

	cout<<"YES\n";
}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    test(t)
    solve6();
    
    
    
}