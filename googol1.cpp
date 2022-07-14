#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef vector<int> vii;
typedef vector<vector<int>> vvii;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<pll>> vvpll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
#define mod 1000000007
#define mod2 998244353
#define f(x,a,b) for(int x=a;x<b;x++)
#define pb push_back
#define mp make_pair
#define S second
#define F first
#define all(a) a.begin(), a.end()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define yesorno(x) cout<<((x)?"YES":"NO")<<"\n"
#define test(t) int tc; cin>>tc; while(tc--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}

ll n,s,m;
ll a[100100];

// code for GGOGOL2 is commented.
// bool check(ll x){
// 	ll arr[n]={0};
// 	ll sum = 0;
// 	f(i,0,n){
// 		if(a[i]<x)
// 			arr[i] = x-a[i];
// 		sum+=arr[i];

// 		if(arr[i]>m) return false;
// 	}
// 	if(sum>s*m) return false;

// 	return true;
// }

// void solve(){
// 	cin>>n>>s>>m;
// 	ll lo = 1e9;
// 	f(i,0,n){
// 		cin>>a[i];
// 		lo = min(lo,a[i]);
// 	}

// 	ll hi = 2*1e9;
// 	ll ans = lo;
// 	while(lo<=hi){
// 		ll mid = (lo+hi)/2;
// 		if(check(mid)){
// 			lo = mid+1;
// 			ans = mid;
// 		}else{
// 			hi = mid-1;
// 		}
// 	}

// 	cout<<ans<<'\n';

// }

bool check(ll x){
	vll pre(n,0);
	ll b[n];
	f(i,0,n) b[i] = a[i];
	ll cnt = 0;
	f(i,0,n){
		if(i){
			pre[i]+=pre[i-1];
			b[i]+=pre[i];
			if(b[i]<x){
				pre[i]+=(x-b[i]);
				cnt+=(x-b[i]);
				if(i+s<n){
					pre[i+s]-=(x-b[i]);
				}
				b[i] = x;
			}
		}else{
			if(b[i]<x){
				pre[i]+=(x-b[i]);
				cnt+=(x-b[i]);
				if(i+s<n){
					pre[i+s]-=(x-b[i]);
				}
				b[i] = x;
			}
		}
	}

	if(cnt>m) return false;
	return true;
}

void googol(){
	cin>>n>>s>>m;
	ll lo = 1e9;

	ll hi = 0;
	f(i,0,n){
		cin>>a[i];
		lo = min(lo,a[i]);
		hi = max(hi,a[i]);
	}
	hi+=m;
	ll ans = lo;
	while(lo<=hi){
		ll mid = (lo+hi)/2;
		if(check(mid)){
			lo = mid+1;
			ans = mid;
		}else{
			hi = mid-1;
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

 
    test(t)
    googol();
    
    
    
}