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


bool cmp(pair<ll,ll> &a, pair<ll,ll> &b){
	return a.S < b.S;
}

void solve(){
	string s; ll p;
	cin>>s;
	cin>>p;
	ll n = s.length();
	ll price = 0;
	vector<pair<ll,ll>> v(n);
	f(i,0,n){
		v[i].F = (s[i]-'a'+1);
		v[i].S = i;
		price+=v[i].F;
	}
	if(price<=p){
		cout<<s<<'\n'; return;
	}
	sort(all(v));
	frev(i,n-1,0){
		price-=v[i].F;
		v[i].F = 0;
		if(price<=p) break;
	}
	sort(all(v), cmp);

	string s1 = "";
	f(i,0,n){
		if(v[i].F == 0) continue;
		s1+=s[i];
	}

	cout<<s1<<'\n';
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