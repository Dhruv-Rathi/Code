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


ll n,m,k;
vi arr, brr;

bool check(ll x){
	ll cnt = 0;
	rep(i,0,n) {
		cnt+=upper_bound(brr.begin(), brr.end(), (x-arr[i])) - brr.begin();
	}
	return (cnt>=k);
}

void solve(){
	cin>>n>>m>>k;
	arr.resize(n);
	brr.resize(m);
	rep(i,0,n) cin>>arr[i];
	rep(i,0,m) cin>>brr[i];
	if(n>m){
		swap(n,m);
		swap(arr,brr);
	}
	sort(arr.begin(),arr.end());
	sort(brr.begin(),brr.end());

	// cout<<arr<<' '<<brr;

	ll lo = arr[0] + brr[0];
	ll hi = arr[n-1]+brr[m-1];
	ll ans = -1;
	while(lo<=hi){
		ll mid = (lo+hi)/2;
		if(check(mid)){
			ans = mid;
			hi = mid-1;
		}
		else{
			lo = mid+1;
		}
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

 
    int _t; cin>>_t; while(_t--)
    solve();
    
    
    
}