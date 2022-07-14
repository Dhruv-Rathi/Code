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

struct node{
	ll msum,lsum,rsum,totsum;
	node(ll m=-1e18,ll l=-1e18,ll r=-1e18,ll t=-1e18){
		msum = m, lsum = l, rsum = r, totsum = t;
	}
};

node merge(node a, node b){
	node c;
	c.totsum = a.totsum+b.totsum;
	c.msum = max({a.msum,b.msum,a.rsum+b.lsum});
	if(c.msum<0) c.msum = 0;
	c.lsum = max(a.lsum,a.totsum+b.lsum);
	if(c.lsum<0) c.lsum = 0;
	c.rsum = max(b.rsum, a.rsum+b.totsum);
	if(c.rsum<0) c.rsum = 0;
	return c;
}

ll n;
ll arr[200100];

node t[800400];

void build(ll id, ll l, ll r){
	if(l == r){
		t[id] = node(arr[l],arr[l],arr[l],arr[l]);
		return;
	}
	ll mid = (l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	t[id] = merge(t[2*id], t[2*id+1]);
}

void update(ll id, ll l, ll r, ll pos, ll val){
	if(pos<l || pos>r) return;
	if(l == r){

		t[id] = node(val,val,val,val);
		arr[l] = val;
		return;
	}
	ll mid = (l+r)/2;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
	t[id] = merge(t[id*2],t[id*2+1]);
}

node query(ll id, ll l, ll r, ll lq, ll rq){
	if(l>rq || r<lq) {
		return node(-1e9,-1e9,-1e9,-1e9);
	}
	if(lq<=l && rq>=r){
		return t[id];
	}

	int mid = (l+r)/2;
	return merge(query(id*2,l,mid,lq,rq), query(id*2+1,mid+1,r,lq,rq));
}



void solve(){
	cin>>n;
	ll m; cin>>m;
	f(i,0,n){
		cin>>arr[i];
	}
	build(1,0,n-1);

	while(m--){
		ll k,x; cin>>k>>x;
		k--;
		update(1,0,n-1,k,x);
		node xf = query(1,0,n-1,0,n-1);
		ll ans = xf.msum<0?0:xf.msum;
		cout<<ans<<'\n';
	}
	
	// while(m--){
	// 	int ch; cin>>ch;
	// 	if(ch == 0){
	// 		ll x,y; cin>>x>>y;
	// 		x--;
	// 		update(1,0,n-1,x,y);
			
	// 	}else{
	// 		ll l,r; cin>>l>>r;
	// 		l--,r--;
	// 		node x = query(1,0,n-1,l,r);
	// 		cout<<x.msum<<'\n';
	// 	}
	// }
}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    // test(t)
    solve();
    
    
    
}