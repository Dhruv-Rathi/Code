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
ll n,k;
vi arr;
void solve()
{
	cin>>n>>k;
	arr.resize(n);
	rep(i,0,n){
		cin>>arr[i];
	}
	sort(arr.begin(), arr.end());
	rep(i,0,k){
		if(arr[n-1] == 1)
			break;
		ll x = arr[n-1]/2;
		ll y = (arr[n-1] - x);
		arr.erase(arr.begin()+n-1);
		if(x>y) swap(x,y);
		arr.pb(x);
		arr.pb(y);
		sort(arr.begin(), arr.end());
		n++;
		// cout<<arr<<'\n';
	}
	cout<<arr[n-1]<<'\n';
	
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