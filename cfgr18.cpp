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
	ll a[n], s = 0;
	rep(i,0,n) {
		cin>>a[i];
		s+=a[i];
	}
	if(s%n == 0) cout<<0;
	else cout<<1;
	cout<<'\n';

}

void solve2(){
	ll l,r; cin>>l>>r;
	vi arr;
	rep(i,l,r+1){
		arr.pb(i);
	}
	ll z =  r, k=0;
	while(z>0){
		k++;
		z/=2;
	}
	// cout<<arr<<'\n';
	ll cnt[k] = {0};
	rep(i,l,r+1){
		ll x = i, k = 0;
		while(x>0){
			cnt[k] += (x%2);
			x/=2;
			k++;
		}
	}
	sort(cnt, cnt+k);
	cout<<(r-l+1-cnt[k-1])<<'\n';
}

void solveB(){
	ll l,r; cin>>l>>r;
	vi arr;
	rep(i,l,r+1){
		arr.pb(i);
	}
	ll cnt[30]={0};
	for(int i=29;i>=0;i--){
		for(auto v:arr){
			if(!(v&(1LL<<i)))
				cnt[i]++ ;
		}
	}
	sort(cnt, cnt+30);
	// rep(i,0,30) cout<<cnt[i]<<' ';
	cout<<(cnt[0])<<'\n';
}


signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    test(t)
    solveB();
    
    
    
}