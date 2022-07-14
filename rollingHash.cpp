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
// #define mod 1000000007
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

ll quickHash(string s, ll p, ll mod){
	ll ans = (s[0]-'a'+1);
	for(int i=1;i<s.length();i++){
		ans = (ans*p+(s[i]-'a'+1))%mod;
	}return ans;
}

struct hasher{
	int sz; ll mod,p;
	vll fHash;
	vll pk;
	void init(string s, ll _p, ll _mod){
		mod = _mod; p = _p;
		sz = s.length();
		fHash.resize(sz);
		pk.resize(sz); // stores p to the power k.

		fHash[0] = (s[0]-'a'+1);
		pk[0] = 1;
		for(int i=1;i<s.length();i++){
			fHash[i] = (fHash[i-1]*p+(s[i]-'a'+1))%mod;
			pk[i] = (pk[i-1]*p)%mod;
		}
	}

	ll getfHash(int l, int r){
		if(l==0) return fHash[r];
		else return ((fHash[r]-fHash[l-1]*pk[r-l+1])%mod + mod)%mod;
	}
};

void solve(){
	string s; cin>>s;
	int n = s.length();

	hasher shash;
	shash.init(s,31,1e9+7);
	f(i,0,n){
		f(j,i,n){
			cout<<shash.getfHash(i,j)<<'\n';
		}
	}
}

void solve2(){
	string text, pattern;
	cin>>text>>pattern;
	int p = pattern.length();
	int h = quickHash(pattern, 31, 999999929);
	hasher texth; texth.init(text, 31, 999999929);
	for(int i=0;i+p-1<text.length();i++){
		if(h == texth.getfHash(i, i+p-1)){
			cout<<"Match at :"<<i<<'\n';
		}
	}
}

int n;
hasher shash;
string s;

bool comp(int i, int j){
	int lo = 1;
	int hi = n;
	int ans = -1;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(shash.getfHash(i,i+mid-1) == shash.getfHash(j,j+mid-1)){
			ans = mid;
			lo = mid+1;
		}else{
			hi = mid-1;
		}
	}
	if(ans == n){
		return 0;
	}else{
		return s[i+ans]<s[j+ans];
	}
}

void solve3(){
	cin>>s;
	n = s.length();
	s = s+s;
	
	shash.init(s, 37, 999999937);
	vector<int> final;
	for(int i=0;i<n;i++) final.push_back(i);
	sort(final.begin(), final.end(), comp);
	for(auto v: final){
		cout<<v<<' ';
	}cout<<'\n';
}
 
signed main()
{
    fast
    
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

 
    // test(t)
    solve3();
    
    
    
}