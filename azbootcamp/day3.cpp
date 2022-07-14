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

void solve(){
	ll n; cin>>n;
	ll ans = 0, i=1;
	while(1){
		ll val = n- i*(i-1)/2;
		if(val<0) break;
		if(val%i == 0) ans++;
		i++;
	}
	cout<<ans<<'\n';
}

void solve2(){
	string s; cin>>s;
	int n = s.length();
	int b[n]={0};
	int ans = 0;
	for(int i=0;i<26;i++){
		char a = (char)(i+'a');
		int tot = 0;
		for(int j=0;j<n;j++){
			if(s[j] == (a)){
				b[j] = 1;
				tot++;
			}else{
				b[j] = 0;
			}
		}
		int cur = 0;
		if(tot == n){
			ans = tot; break;
		}
		for(int j=0;j<n;j++){
			if(b[j] == 0){
				int k = j-1;
				int x = 0, y = 0;
				while(k>=0 && b[k] == 1){
					k--; x++;
				}
				k = j+1;
				while(k<n && b[k] == 1){
					k++; y++;
				}
				if(x+y<tot){
					cur = max(cur,x+y+1);
				}else{
					cur = max(cur,x+y);
				}
			}
		}

		ans = max(ans, cur);
	}

	cout<<ans<<'\n';
}

const int N = 1000000009;

bool check(ll x){

}

void solve3(){
	ll n,m,k; cin>>n>>m>>k;
	ll lo = m;
	ll hi = 1e18;
	ll ans = lo;
	while(lo<=hi){
		ll mid = (lo+hi)/2;
		if(check(mid)){
			ans = mid;
			hi = mid-1;
		}else{
			lo = mid+1;
		}
	}

	cout<<(ans%N);
}

void solve4(){
	ll n,m,k; cin>>n>>m>>k;
	ll x = (m+1)/(k-1);

	if(m+(x-1)<=n){
		cout<<m<<'\n';
	}
	
}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    // test(t)
    solve3();


    
}