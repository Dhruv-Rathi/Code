#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define vi vector<ll>
#define vvi vector<vi>
#define f(x,a,b) for(int x=a;x<b;x++)
#define pb push_back
#define eb emplace_back //faster than push_back
#define mod1 1000000007
#define mod2 998244353
#define ss second
#define ff first
#define all(a) a.begin(), a.end()
#define vecpii vector<pair<int,int>>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test(t) int tc; cin>>tc; while(tc--)


template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}

void solve()
{
	ll n; cin>>n;
	multiset<ll> allnum;
	f(i,0,(1<<n)){
		ll x; cin>>x;
		allnum.insert(x);
	}
	vi orig;
	multiset<ll> generated;
	generated.insert(0);
	allnum.erase(allnum.find(0));
	while(!allnum.empty()){
		ll smallest = *allnum.begin();
		orig.pb(smallest);

		vi newgen;
		for(auto v: generated){
			newgen.pb(smallest+v);
		}
		for(auto v:newgen){
			generated.insert(v);
			allnum.erase(allnum.find(v));
		}

	}
	for(auto v: orig){
		cout<<v<<' ';
	}

	cout<<'\n';

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