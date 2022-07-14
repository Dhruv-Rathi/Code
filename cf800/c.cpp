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
	ll n; cin>>n;
	ll sum = 0;
	ll cnt = 0 ;
	vll a(n); cin>>a;
	// cout<<a<<'\n';
	bool f = 0;
	f(i,0,n){
		sum+=a[i];
		if(a[i]!=0 && f == 1){
			no; return;
		}
		if(sum<=0) {f = 1;}
		
	}
	if(sum!=0){
		no; return;
	}
	if(n == 1){
		if(a[0] == 0) yes;
		else no;
		return;
	}
	yes;

}



bool check(ll num){
	string s = to_string(num);

	int n = s.length();
	for(int i=0;i<n/2; i++){
		if(s[i]!=s[n-i-1]) return 0;
	}
	return 1;
}
ll dp[40001];

void solve2(){
	ll n; cin>>n;
	cout<<dp[n]%mod<<'\n';
}
 
signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    vll pal;

    f(i,1,40001){
    	if(check(i))
    		pal.PB(i);
    }
    
    f(i,0,40001) dp[i] = 0;
    dp[0] = 1;
    f(i,0,pal.size()){
    	f(j,0,40001){
    		if(j - pal[i]>=0){
    			dp[j] += dp[j-pal[i]]%mod;
    		}
    	}
    }
 
    ll tc = 1;
    cin>>tc;
    for(int i=1;i<=tc;i++){
    //	cout<<"Case #"<<i<<": ";
    	solve2();
    }
    
}