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
#define int long long int 
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}
// ll n,K;
// ll arr[200200];
// bool check(int mid)
// {
//     int count = 0;
//     int sum = 0;
//     for (int i = 0; i < n; i++) {
 
//         if (arr[i] > mid)
//             return false;

//         sum += arr[i];
 
//         if (sum > mid) {
//             count++;
//             sum = arr[i];
//         }
//     }
//     count++;
 
//     if (count <= K)
//         return true;
//     return false;
// }
 
// void solve()
// {
// 	cin>>n>>K;
// 	rep(i,0,n) cin>>arr[i];
//     int* max = max_element(arr, arr + n);
//     int lo = *max; 
//     int hi = 0;
 
//     for (int i = 0; i < n; i++) {
//         hi += arr[i]; 
//     }
 
//     int answer = 0;
//     while (lo <= hi) {
//         int mid = (lo + hi) / 2;
 
//         if (check(mid)) {
//             answer = mid;
//             hi = mid - 1;
//         }
//         else {
//             lo = mid + 1;
//         }
//     }
 
//     cout<<answer;
// }

ll power(ll a, ll b){
	ll p=1;
	while(b>0){
		if(b&1) p = (p%mod * a%mod)%mod;
		a = (a%mod * a%mod)%mod;
		b/=2;

	}
	return p;
}
inline ll inv(ll a){
	a = a%mod;
	if(a<0) a+=mod;
	ll b = mod, u = 0, v = 1;
	while(a){
		ll t = b/a;
		b-=t*a; swap(a,b);
		u-=t*v; swap(u,v);

	}
	assert(b==1);
	if(u<0) u+=mod;
	return u;
}
inline ll mul(ll a, ll b){
	return (a%mod * b%mod)%mod;
}
void solve2(){
	ll a,b,c,d,e,f,g,h;
	cin>>a>>b>>c>>d>>e>>f>>g>>h;
	ll ans = 0;
	ans = power(a,b);
	ans = (ans-c)%mod;
	ans = (ans - mul(d, inv(e)))%mod;
	ans = (ans+power(power(f,g), h))%mod;
	cout<<(ans+mod)%mod<<'\n';
}

void solve3(){
	ll a,b,n;
	cin>>a>>b>>n;
	ll ans = 0;
	ans = power(a,n)%mod;
	ll p = 0;
	p = mul(b, mul((ans-1), inv(a-1)));
	ans = (ans+p%mod)%mod;
	cout<<(ans+mod)%mod<<'\n';
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