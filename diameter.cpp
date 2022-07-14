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

vll g[200200];
ll dep[200200];
ll par[200200];

ll d, cnt;

void dfs(ll node, ll parent, ll depth){
	dep[node] = depth;
	par[node] = parent;

	if(depth == d/2) cnt++;

	for(auto v: g[node]){
		if(v!=parent){

			dfs(v,node,depth+1);

		}
	}
}

void solve(){
	ll n; cin>>n;
	f(i,0,n-1){
		ll a,b; cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}

	if(n == 1){
		cout<<1<<'\n'; return;
	}
	dfs(1,0,0);
	ll maxch=1;
	f(i,2,n+1){
		if(dep[i]>dep[maxch]){
			maxch = i;
		}
	}
	dfs(maxch,0,0);
	f(i,1,n+1){
		if(dep[i]>dep[maxch]){
			maxch = i;
		}
	}

	d = dep[maxch];
	ll ans = 0;
	if(dep[maxch]%2){
		
		ll c1=maxch,c2;
		ll x = d/2;
		while(x--){
			c1 = par[c1];
		}
		c2 = par[c1];
		
		cnt=0;
		dfs(c1,c2,0);
		ans = cnt;
		cnt=0;
		dfs(c2,c1,0);
		ans*=cnt;
	}else{
		ll c = maxch;
		ll x = d/2;
		while(x--){
			c=par[c];
		}
		d--;
		// cout<<maxch<<'\n';
		vll arr;
		for(auto v: g[c]){
			cnt = 0;
			dfs(v,c,0);
			
			arr.pb(cnt);
		}

		// cout<<arr;

		ll s1=0, s2=0;

		for(auto a: arr){
			s1+=a;
			s2+=a*a;
		}

		s1 = s1*s1;
		ans = (s1-s2)/2;
	}

	cout<<ans<<'\n';

}
 
signed main()
{
    fast

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    solve();
    
    
    
}