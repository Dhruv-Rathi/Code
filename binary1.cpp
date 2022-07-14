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

ll n,q,k;
vi arr;

// bool check(ll x){
// 	if(arr[x]<arr[0])return 1;
// 	else return 0;
// }

// void solve()
// {
// 	cin>>n;
// 	arr.resize(n);
// 	rep(i,0,n) cin>>arr[i];
// 	ll lo=0, hi = n-1, ans=0;
// 	while(lo<=hi)
// 	{
// 		ll mid = (lo+(hi-lo)/2) ;
// 		if(check(mid))
// 		{
// 			ans = mid;
// 			hi  = mid-1;
// 		}
// 		else{
// 			lo = mid+1;
// 		}
// 	}
// 	cout<<ans<<'\n';

// }

bool check2(ll x)
{
	if(arr[x]>arr[x-1]) return 1;
	else return 0;
}

void solve2()
{
	cin>>n>>q;
	arr.resize(n);
	rep(i,0,n) cin>>arr[i];
	ll lo = 1, hi=n-1, peak=0;
	while(lo<=hi)
	{
		ll mid = (lo+hi)/2;
		if(check2(mid))
		{
			peak = mid;
			lo = mid+1;
		}
		else{
			hi = mid-1;
		}
	}
	cout<<peak<<'\n';
	while(q--){
		ll k;
		cin>>k;
		vi ans;
		lo=0;hi = peak-1;
		while(lo<=hi){
			
			ll mid=(lo +hi)/2;
			
			if(arr[mid] == k){
				
				ans.pb(mid+1);
				break;
			}
			else if(arr[mid]>k){
				
				hi = mid-1;
			}
			else {
				
                lo = mid+1;
            }
		}
	
		lo = peak;
		hi = n-1;
		while(lo<=hi){
			ll mid = (lo + hi)/2;
			if(arr[mid] == k){
				ans.pb(mid+1);
				break;
			}
			else if(arr[mid]>k){
				lo = mid+1;
			}
			else {
                hi = mid-1;
            }
		}

		for(auto e: ans){
			cout<<e<<' ';
		}
		cout<<'\n';
	}
}

bool check(ll x){
	ll cnt=0,i;
	for(i=0;i<x;i++){
		if(arr[i] == 0) cnt++;
	}
	if(cnt<=k) return true;
	for(i=x;i<n;i++){
		if(arr[i-x] == 0)
			cnt--;
		if(arr[i] == 0)
			cnt++;
		if(cnt<=k) return true;
	}
	return false;
}
 
void solve3(){
	cin>>n>>k;
	arr.resize(n);
	rep(i,0,n) cin>>arr[i];

	ll lo = k;
	ll hi = n;
	ll ans = lo;
	while(lo<=hi){
		ll mid = (lo+hi)/2;
		if(check(mid)){
			ans = mid;
			lo = mid+1;
		}
		else
			hi = mid-1;
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
    solve3();
    
    
    
}