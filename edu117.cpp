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

// void solve()
// {
// 	ll n,m; cin>>n>>m;
// 	if(n==1 && m==1){
// 		cout<<0<<'\n';
// 		return;
// 	}
// 	if(min(n,m) == 1){
// 		cout<<1<<'\n';
// 		return;
// 	}

// 	cout<<2<<'\n';
// }

vi b(200200,0), a(200200,0);ll n;
bool ans;

void check(ll x){
	ll m=0;
	for(ll i=1;i<=n;i++){
		if(a[i]!=x){
			b[++m] = a[i];
		}
	}
	for(ll i=1;i<=m;i++){
		if(b[i]!=b[m-i+1])
			return;
	}
	ans = true;
}

void solve2(){
	cin>>n;
	ans = true;
	
	rep(i,1,n+1) {
		cin>>a[i];
	}
	
	// cout<<a<<'\n';
	for(ll i=1;i<=n;i++){
		if(a[i]!=a[n-i+1]){
			ans = false;
			check(a[i]);
			check(a[n-i+1]);
			break;
		}
	}
	if(ans){
		cout<<"YES\n";
	}
	else
		cout<<"NO\n";
}

void solve3(){
	ll n; cin>>n;
	vi a(n), b(n);
	rep(i,0,n){
		cin>>a[i]>>b[i];
	}
	
}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    test(t)
    solve2();
    
    
    
}