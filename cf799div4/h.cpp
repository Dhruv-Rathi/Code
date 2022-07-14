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

struct node{
	ll pre, suf, val, sum;
	node(){
		pre = suf = val = sum = -1e18;
	}
};

node merge(node a, node b){
	node c;
	c.pre = max(a.pre, a.sum+b.pre);
	c.suf = max(b.suf, b.sum+a.suf);
	c.val = max({a.val, b.val, a.suf+b.pre});
	return c;
}

ll x[200100];
ll b[200100];
node t[800400];

#define mid (l+r)/2

void update(ll id, ll l, ll r, ll pos, ll val){
	if(l>pos || r<pos) return;
	if(l == pos && r == pos){
		t[id].pre = val;
		t[id].suf = val;
		t[id].val = val;
		t[id].sum = val;
		return ;
	}
	update(id<<1, l, mid,pos,val);
	update(id<<1|1,mid+1,r,pos, val);
	t[id] = merge(t[id<<1], t[id<<1|1]);
}

node query(ll id, ll l, ll r, ll lq, ll rq){
	if(l>rq || r<lq) return node();
	if(l>=lq && r<=rq){
		return t[id];
	}
	return merge(t[id<<1], t[id<<1|1]);
}
#undef mid


void solve(){
	ll n; cin>>n;
	map<ll,ll> mp;
	for(ll i=0;i<n;i++){
		cin>>x[i];
		mp[x[i]]++;
	}
	for(ll i=0;i<n;i++){
		update(1,0,n-1,i,-1);
	}
	ll ma = 0, a = 0;
	ll fans = 0, fa = 0, fl = 0, fr = 0;
	for(auto v: mp){
		a = v.F;
		for(ll i=0;i<n;i++){
			if(x[i] == a) update(1,0,n-1,i,1);
			// else update(1,0,n-1,i,-1);
		}

		ll ans = query(1,0,n-1,0,n-1).val;
		for(ll i=0;i<n;i++){
			update(1,0,n-1,i,-1);
		}
		// cout<<a<<' '<<ans<<'\n';
		if(ans>fans){
			fa = a;
			fans = ans;
		}
	}
	ll l = -1, r  =-1;
	for(ll i=0;i<n;i++){
		if(x[i] == fa){
			x[i] = 1;
		}
		else
			x[i] = -1;
	}
	ll sum = 0, lastl = 0;
	ma = 0;
	// for(ll i=0;i<n;i++) cout<<x[i]<<' '; cout<<'\n';
	for(ll i=0;i<n;i++){
		sum+=x[i];
		if(sum>ma){
			ma = sum;
			r = i;
			l = lastl;
		}
		if(sum<0){
			sum = 0;
			lastl = i+1;
		}
	}
	// cout<<fans<<'\n';
	cout<<fa<<' '<<l+1<<' '<<r+1<<'\n';
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