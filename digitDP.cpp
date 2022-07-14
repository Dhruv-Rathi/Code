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
#define test(t) int tc; cin>>tc; while(tc--)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <class T> ostream &operator<<(ostream &os, const vector<T> a){ for (auto ele : a) os << ele << " "; return os;} 
template <class T> istream &operator>>(istream &is, vector<T> &a){ for (auto &ele : a) is >> ele; return is; }

ll len, D;
string L, R;

ll dp[10010][2][2][100];

ll rec(ll l, ll tlo, ll thi, ll sumD){
	if(l == len){
		if(sumD == 0) return 1;
		return 0;
	}
	if(dp[l][tlo][thi][sumD]!=-1) return dp[l][tlo][thi][sumD];
	ll ans = 0, lo = 0, hi = 9;
	if(tlo == 1) lo = L[l]-'0';
	if(thi == 1) hi = R[l]-'0';
	for(int i=lo;i<=hi;i++){
		ll ntlo = tlo;
		if(i!=L[l]-'0') ntlo = 0;
		ll nthi = thi;
		if(i!=R[l]-'0') nthi = 0;
		ans+=rec(l+1, ntlo, nthi, (sumD+i)%D);
		ans%=mod;
	}
	return dp[l][tlo][thi][sumD] = ans;
}

void solve(){
	L = "1";
	cin>>R;
	cin>>D;
	int cnt = R.length() - L.length();
	string t = "";
	while(cnt--) t+='0';
	L = t+L;
	len = R.length();
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,1,1,0)<<'\n';
}
 
signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    // test(t)
    solve();
    
}