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

ll a[200100];
ll t[800400];

void build(ll id, ll l, ll r){
	if(l == r){
		t[id] = a[l]; return;
	}
	ll mid = (l+r)/2;
	build(2*id, l, mid);
	build(2*id+1, mid+1, r);
	// t[id] = t[2*id]+t[2*id+1];
}

void update(ll id, ll l, ll r, ll lq, ll rq, ll val){
	if(l>rq || r<lq) return ;
	if(lq<=l && rq>=r){
		t[id]+=val;
		return;
	}
	ll mid = (l+r)/2;
	update(2*id, l, mid, lq, rq, val);
	update(2*id+1, mid+1, r, lq, rq, val);
	// t[id] = t[2*id]+t[2*id+1];
}

ll query(ll id, ll l, ll r, ll x){
	if(x<l || x>r) return 0;
	if(l == r){
		return t[id];
	}
	ll mid = (l+r)/2;
	return (t[id]+query(2*id,l,mid,x)+query(2*id+1,mid+1,r,x));
} 

void solve(){
	int n,q; 
	cin>>n>>q;
	f(i,0,n){
		cin>>a[i];
	}
	build(1,0,n-1);
	while(q--){
		int ch; cin>>ch;
		if(ch == 1){
			ll i,j,x; cin>>i>>j>>x;
			i--; j--;
			update(1,0,n-1,i,j,x);
		}else{
			ll i; cin>>i;
			i--; 
			cout<<query(1,0,n-1,i)<<'\n';
		}
	}
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