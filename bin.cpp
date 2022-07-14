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
ll arr[100100];

// bool check(ll diff){
//     ll points = 0;
//     ll i = 1;
//     while(i<n){
//         points+=(arr[i]-arr[i-1]+diff-1)/diff - 1;
//         i++;
//     }
//     return points<=k;
// }

// void solve()
// {
// 	cin>>n>>k;
//     arr.resize(n);
//     rep(i,0,n) cin>>arr[i];
//     ll low = 1, high = 1e9;
//     ll ans = high;
//     while(low<=high){
//         ll mid = (low+high)/2;
//         if(check(mid)){
//             ans = mid;
//             high = mid-1;
//         }else{
//             low = mid+1;
//         }
//     }
//     cout<<ans<<'\n';
    
// }

// void solve2(){
// 	cin>>n>>s;
// 	ll lo = 1, hi = n;
// 	ll ans = 0;
// 	while(lo<=hi){
// 		ll mid = (lo+hi)/2;
// 		ll temp = mid;
// 		ll sum = 0;
// 		while(temp>0){
// 			sum+=temp%10;
// 			temp/=10;
// 		}
// 		if(mid-sum>=s)
// 			hi = mid-1;
// 		else{
// 			ans = mid;
// 			lo = mid+1;
// 		}
		
// 	}
// 	cout<<(n-ans)<<'\n';
// } 

map<ll,ll> freq;

bool check2(ll m){
	ll tot = 0;
	for(auto e: freq){
		tot+=min(e.ss, m);
	}
	return tot>=(k*m);
}
void solve3(){
	cin>>n>>k;
	rep(i,0,n) {
		cin>>arr[i];
		freq[arr[i]]++;
	}
	ll sum = 0;
	ll lo = 0, hi = n, ans=lo;
	while(lo<=hi){
		ll mid = (lo+hi)/2;
		if(check2(mid)){
			ans = mid;
			lo = mid+1;
		}
		else{
			hi = mid-1;
		}
	}

	cout<<ans<<'\n';
	freq.clear();
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