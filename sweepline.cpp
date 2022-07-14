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
	ll n, L; cin>>n>>L;
	vpll v;
	f(i,0,n){
		ll l,r; cin>>l>>r;
		v.pb({l,r});
	}
	sort(all(v));
	map<ll,ll> mp;

	f(i,0,n){
		mp[v[i].F] = max(mp[v[i].F], v[i].S);
	}
	ll ans = 0, prev = 0, ma = 0;
	for(auto it: mp){
		if(it.F == prev){
			ma = max(ma, it.S);
			prev = ma;
			ans++;
		}
		else if(it.F>prev){
			ans++;
			prev = ma;
		}
		ma = max(ma, it.S);
	}
	if(prev<L) ans++;
	cout<<ans<<'\n';
}

void solve2(){
	ll n, L; cin>>n>>L;
	vpll v;
	f(i,0,n){
		ll l,r; cin>>l>>r;
		v.pb({l,+1});
		v.pb({r,-1});
	}
	sort(all(v));
	
	ll cnt = 0, ans = n+1;

	f(i,0,(ll)(v.size()-1)){
		cnt+=v[i].S;
		if(v[i].F!=v[i+1].F){
			ans = min(ans, cnt);
		}
		cout<<cnt<<' '<<ans<<'\n';
	}
	cout<<(n+1-ans)<<'\n';
	
}

void solve3(){
	int n; cin>>n;
	vector<pair<ll,pll>> events;
	for(int i=0;i<n;i++){
		ll l,r,x; cin>>l>>r>>x;
		events.pb({l,{0,x}});
		events.pb({r,{2,x}});
	}
	int q; cin>>q;
	pll quer[q];
	for(int i=0;i<q;i++){
		ll y,z; cin>>y>>z;
		quer[i].F = y; quer[i].S = z;
		events.pb({y,{1,i}});
	}
	int ans[q];
	sort(all(events));
	multiset<ll> mt;
	for(int i=0;i<events.size();i++){
		if(events[i].S.F == 0){
			mt.insert(events[i].S.S);
		}else if(events[i].S.F == 2){
			mt.erase(mt.find(events[i].S.S));	
		}else{
			ll z = quer[events[i].S.S].S;
			auto it = mt.upper_bound(z);
			if(it!=mt.begin()){
				it--;
				ans[events[i].S.S] = *it;
			}else{
				ans[events[i].S.S] = -1;
			}
		}
	}
	for(auto a: ans){
		cout<<a<<'\n';
	}
}

void sweepLine_hard(){
	int n; cin>>n;
	vector<pii> events;
	
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