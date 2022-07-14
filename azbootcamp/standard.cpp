
// // void solve(){
// // 	int n; cin>>n;
// // 	vpll a(n);
// // 	FOR(i,0,n){
// // 		ll x; cin>>x;
// // 		a[i].F = x;
// // 		a[i].S = i;
// // 	}
// // 	sort(all(a));
// // 	reverse(all(a));
// // 	ll sum = 0; map<ll,ll> m;
// // 	FOR(i,0,n){
// // 		if(m[a[i].S-1] || m[a[i].S+1]){
// // 			continue;
// // 		}else{
// // 			// cout<<a[i].S<<' ';
// // 			sum+=a[i].F;
// // 			m[a[i].S]++;
// // 		}
// // 	}
// // 	cout<<sum<<'\n';
// // }

// // int n;
// // ll a[100100];
// // ll dp[100100];
// // ll rec(ll level){
// // 	if(level >= n) return 0;
// // 	if(dp[level]!=-1) return dp[level];
// // 	ll ans = 0;
// // 	ans = max(a[level]+rec(level+2), rec(level+1));
// // 	return dp[level] = ans;
// // }


// // void solve2(){
// // 	cin>>n;
// // 	FOR(i,0,n){
// // 		cin>>a[i];
// // 		dp[i] = -1;
// // 	}
// // 	cout<<rec(0)<<'\n';
// // }


// void solve(){
// 	int n; cin>>n;
// 	vector<pair<pll,ll>> b;
// 	FOR(i,0,n){
// 		ll h,w,l; cin>>h>>w>>l;
// 		b.PB({{h,w},l});
// 		b.PB({{w,h},l});
// 		b.PB({{l,w},h});
// 		b.PB({{w,l},h});
// 		b.PB({{h,l},w});
// 		b.PB({{l,h},w});
// 	}
// 	sort(all(b));
// 	reverse(all(b));
// 	vll dp(6*n);
// 	ll ans = 0;
// 	FOR(i,0,6*n){
// 		dp[i] = b[i].S;
// 		FOR(j,0,i){
// 			if(b[j].F.S>b[i].F.S && b[j].F.F>b[i].F.F){
// 				dp[i] = max(dp[i], dp[j]+b[i].S);
// 			}
// 		}
// 		ans = max(ans, dp[i]);
// 	}
// 	cout<<ans<<'\n';
// }
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
#define frev(x,a,b) for(int x=a;x>=b;x--)
#define PB push_back
#define MP make_pair
#define S second
#define F first
#define all(a) (a).begin(), (a).end()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define yesorno(x) cout<<((x)?"YES":"NO")<<"\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <class T> ostream &operator<<(ostream &os, const vector<T> a){ for (auto ele : a) os << ele << " "; return os;} 
template <class T> istream &operator>>(istream &is, vector<T> &a){ for (auto &ele : a) is >> ele; return is; }

void solve(){
	string s; cin>>s;
	bool ok = 0;
	int n = s.length();
	int a[26]={0};
	f(i,0,n){
		a[s[i]-'a']++;
	}
	int cnt = 0;
	f(i,0,26){
		if(a[i]%2) cnt++;
	}

	if(n%2 && cnt>1){
		cout<<-1<<'\n'; return;
	}
	if(n%2 == 0 && cnt){
		cout<<-1<<'\n'; return;
	}

	int l = 0, r = n-1, ans = 0;
	while(l<r){
		int i=l, j=r;
		while(s[i]!=s[j]) j--;
		if(i == j){
			swap(s[i], s[i+1]); ans++;
			continue;
		}
		while(j<r) {
			swap(s[j], s[j+1]); j++; ans++;
		}
		l++; r--;
	}
	cout<<ans<<'\n';

}
 
signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    ll tc = 1;
    cin>>tc;
    for(int i=1;i<=tc;i++){
    //	cout<<"Case #"<<i<<": ";
    	solve();
    }
    
}