#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define vi vector<ll>
#define vvi vector<vi>
#define f(x,a,b) for(int x=a;x<b;x++)
#define pb push_back
#define eb emplace_back //faster than push_back
#define mod1 1000000007
#define mod2 998244353
#define ss second
#define ff first
#define all(a) a.begin(), a.end()
#define vecpii vector<pair<int,int>>
#define test(t) int tc; cin>>tc; while(tc--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}

void solve(){
	string s; cin>>s;
	ll n = s.length(), a = 0, b = 0;
	bool f = 1;
	f(i,0,n){
		if(s[i]=='B'){
			b++;
		}else a++;
		if(b>a) f=0;
	}
	if(s[n-1]!='B') f=0;
	if(f) cout<<"YES\n"; else cout<<"NO\n";

}

void solve2(){
	ll n; cin>>n;
    ll ans = 2;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0) {
        	ans++;
        	if(i*i!=n) ans++;
        }
    }
    cout<<ans<<'\n';
}

void solve3(){
	ll n; cin>>n;
	ll a[n];
	f(i,0,n) cin>>a[i];
	ll cnt = 0;
	f(i,0,n-1){
		if(a[i]>a[i+1]){
			swap(a[i],a[i+1]);cnt++;
			if(i!=0){
				i-=2;
			}
		}
		if(cnt>1){
			cout<<"NO\n"; return;
		}
	}
	cout<<"YES\n";
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