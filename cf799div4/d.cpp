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

bool check(string s, int n){
	for(int i=0;i<n/2;i++){
		if(s[i]!=s[n-i-1]) return false;
	}return true;
}

string func(string &s, int x){
	string news = "";
	string hh = s.substr(0,2);
	string mm = s.substr(3,2);
	int h = stoi(hh); int m = stoi(mm);
	int x1 = x/60;
	int x2 = x%60;
	h+=x1; m+=x2;
	h+=m/60; m%=60;
	h%=24;
	// cout<<h<<' '<<m<<'\n';
	string h1 = to_string(h);
	string m1 = to_string(m);
	// cout<<h1<<' '<<m1<<'\n';
	// // cout<<h1.length()<<' '<<m1.length()<<'\n';
	if(h1.length() == 1){
		h1 = '0'+h1;
	}
	if(m1.length()==1){
		m1 = '0'+m1;
	}
	news = h1+':'+m1;
	return news;
}

void solve(){
	string s; cin>>s;
	int x; cin>>x;
	ll ans = 0;
	if(check(s, 5)) ans++;
	string news = "";
	string hh = s.substr(0,2);
	string mm = s.substr(3,2);
	int h = stoi(hh); int m = stoi(mm);
	int x1 = x/60;
	int x2 = x%60;
	h+=x1; m+=x2;
	h+=m/60; m%=60;
	h%=24;
	// cout<<h<<' '<<m<<'\n';
	string h1 = to_string(h);
	string m1 = to_string(m);
	// cout<<h1<<' '<<m1<<'\n';
	// // cout<<h1.length()<<' '<<m1.length()<<'\n';
	if(h1.length() == 1){
		h1 = '0'+h1;
	}
	if(m1.length()==1){
		m1 = '0'+m1;
	}
	news = h1+':'+m1;
	// cout<<news<<'\n';
	while(!(news == s)){
		if(check(news, 5)) ans++;
		news = func(news,x);
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
 
    test(t)
    solve();
    
}