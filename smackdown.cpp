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
	ll n; cin>>n;
	vi a(n), v(n);
	rep(i,0,n) cin>>a[i];
	v = a;
	sort(all(a));

	if(a[n-1] == v[n-1]){
		for(ll i=n-2; i>=0;i--){
			cout<<v[i]<<' ';
		}
		cout<<v[n-1];
	}
	else if(a[n-1] == v[0]){
		cout<<v[0]<<' ';
		for(ll i=n-1;i>0; i--) cout<<v[i]<<' ';
	}
	else{
		cout<<-1;	
	}
	cout<<'\n';
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