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
	int n;
	cin>>n;
	vector<pair<ll,ll>> a;
	for(int i=0;i<n;i++){
		ll l,r;
		cin>>l>>r;
		a.pb({l,r});

	}
	sort(a.begin(), a.end());
	ll L=0;
	ll R=0;
	bool flag=false;
	vector<pair<ll,ll>> unionA;
	for(auto it:a){
		ll st = it.ff;
		ll en = it.ss;
		// Only for 1st element.
		if(!flag){
			L = st;
			R = en;
			flag=true;
			continue;
		}
		if(st>R){
			// [L, R] is one union, and we need to start new union
			unionA.pb({L, R});
			L = st;
			R = en;
		}
		else{
			// Current range [st, en] is still in current union 
			R = max(R, en);
		}
	}
	unionA.pb({L, R});
	ll ans = 0;
	for(auto it: unionA){
		ans+=(it.ss - it.ff + 1);
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

 
    test(t)
    solve();
    
    
    
}