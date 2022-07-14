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


bool comp(pair<pair<ll,ll>,ll> &a, pair<pair<ll,ll>,ll> &b){
	return a.F.S< b.F.S;
}


void solve(){
	ll n; cin>>n;
	vll b(n+1);
	vll a(n+1, 0);
	set<ll> s;
	vector<pair<pair<ll,ll>, ll>> r;
	
	f(i,1,n+1){
		s.insert(i);
		cin>>b[i];
		if(b[i] == 0){
			r.PB({{i+1, n}, i});
		}
		else{
			r.PB({{(i/(b[i]+1))+1, i/b[i]}, i});
		}
	}

	sort(r.begin(), r.end(), comp);

	int prev = 0;

	for(ll i=0; i<(ll)r.size(); i++){
		ll x = *(s.lower_bound(r[i].F.F));
		s.erase(x);
		prev = x;
		a[r[i].S] = x;
	}
	f(i,1,n+1){
		cout<<a[i]<<' ';
	}cout<<'\n';


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