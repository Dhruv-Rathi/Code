// Coordinate compression

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

struct Coordinate_Compress{

	map<ll,ll> compVal;
	vll rev;
	int cnt;

	void add(ll x){
		compVal[x];
	}
	void build(){
		cnt = 0;
		for(auto &v: compVal){
			rev.emplace_back(v.F);
			v.S = cnt++;
		}
	}

	inline ll getComp(ll x){
		return compVal[x];
	}
	inline ll getorig(ll x){
		return rev[x];
	}
	ll getPrev(ll x){
		auto it = compVal.upper_bound(x);
		it--;
		return it->S; // logic dependent
	}
	ll getNext(ll x){
		auto it = compVal.lower_bound(x);
		return it->S;
	}
	void deb(){

	}
}CMP;

void solve(){
	vll arr = {1,3,5,4,5,2,3,1,1000000};
	for(auto v:arr){
		CMP.add(v);
	}


	CMP.deb();
	CMP.build();

}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    test(t)
    solve();
    
    
    
}