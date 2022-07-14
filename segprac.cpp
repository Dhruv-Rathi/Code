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

// struct node{
// 	int e,o;
// 	node(){
// 		e = 0; o = 0;
// 	}
// };

// node t[400400];

// int a[100100];

// node merge(node a, node b){
// 	node c;
// 	c.o = a.o+b.o;
// 	c.e = a.e+b.e;
// 	return c;
// }

// #define mid ((l+r)>>1)
// void build(int id, int l, int r){
// 	if(l == r){
// 		if(a[l]%2) t[id].o = 1;
// 		else t[id].e = 1;
// 		return;
// 	}
// 	build(id<<1,l,mid);
// 	build(id<<1|1,mid+1,r);
// 	t[id] = merge(t[id<<1],t[id<<1|1]);
// }

// void update(int id, int l, int r, int pos, int val){
// 	if(pos<l || pos>r) return;
// 	if(l == r){
// 		if(val%2) {t[id].o = 1;t[id].e = 0;}
// 		else {t[id].e = 1;t[id].o = 0;}
// 		return;
// 	}
// 	update(id<<1,l,mid,pos,val);
// 	update(id<<1|1,mid+1,r,pos,val);
// 	t[id] = merge(t[id<<1],t[id<<1|1]);
// }

// node query(int id, int l, int r, int lq, int rq){
// 	if(lq>r || rq<l) return node();
// 	if(lq<=l && rq>=r){
// 		return t[id];
// 	}
// 	return merge(query(id<<1,l,mid,lq,rq),query(id<<1|1,mid+1,r,lq,rq));
// }
// #undef mid


// void solve(){
// 	int n; cin>>n;
// 	f(i,0,n){
// 		cin>>a[i];
// 	}

// 	int q; cin>>q;
// 	build(1,0,n-1);
// 	while(q--){
// 		int ch,x,y; cin>>ch>>x>>y;
// 		if(ch == 0){
// 			x--;
// 			update(1,0,n-1,x,y);
// 		}else if(ch == 1){
// 			x--; y--;
// 			node p = query(1,0,n-1,x,y);
// 			cout<<p.e<<'\n';
// 		}else{
// 			x--; y--;
// 			node p = query(1,0,n-1,x,y);
// 			cout<<p.o<<'\n';
// 		}
// 	}
// }


// ll a[200200];
// ll t[800800];

// #define mid (l+r)/2
// void build(ll id, ll l, ll r){
// 	if(l == r){
// 		t[id] = a[l];
// 		return;
// 	}
// 	build(id<<1,l,mid);
// 	build(id<<1|1, mid+1,r);
// 	t[id] = max(t[id<<1], t[id<<1|1]);
// }
// void update(ll id, ll l, ll r, ll pos, ll val){
// 	if(pos<l || pos>r) return;
// 	if(l==r){
// 		a[l]-=val;
// 		t[id] = a[l];
// 		// cout<<id<<' '<<t[id]<<'\n';
// 		return;
// 	}
// 	update(id<<1,l,mid, pos, val);
// 	update(id<<1|1, mid+1,r, pos, val);
// 	t[id] = max(t[id<<1], t[id<<1|1]);
// }
// ll query(ll id, ll l, ll r, ll x){
// 	if(t[id]<x) return -1;
// 	// cout<<l<<' '<<r<<'\n';
// 	if(l == r){
// 		// cout<<l<<'\n';
// 		return l;
// 	}
// 	if(t[id<<1]>=x) return query(id<<1,l,mid,x);
// 	return query(id<<1|1,mid+1,r,x);
// }
// #undef mid

// void solve2(){
// 	int n,q; cin>>n>>q;
// 	f(i,0,n){
// 		cin>>a[i];
// 	}
// 	build(1,0,n-1);
// 	while(q--){
// 		ll x; cin>>x;
// 		// cout<<x<<'\n';
// 		ll ans = query(1,0,n-1,x);
// 		if(ans>=0) update(1,0,n-1,ans,x);
// 		cout<<ans+1<<' ';
// 	}
// }

struct node{
	int L, O, C;
	node (int l=0,int o=0, int c=0){
		L = l; O = o; C = c;
	}
};

const int N = 1000010;
int arr[N];
node t[4*N];
string s;

node merge(node a, node b){
	int t = min(a.O, b.C);
	node c;
	c.L = a.L + b.L + 2*t;
	c.O = a.O + b.O - t;
	c.C = a.C + b.C - t;
	return c;
}

#define mid (l+r)/2
void build(int id, int l, int r){
	if(l == r){
		if(s[l] == '(')
			t[id] = node(0,1,0);
		else
			t[id] = node(0,0,1);
		return;
	}
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	t[id] = merge(t[id<<1], t[id<<1|1]);
}

node query(int id, int l, int r, int lq, int rq){
	if(lq>r || rq<l) return node(0,0,0);
	if(lq<=l && rq>=r){
		return t[id];
	}
	return merge(query(id<<1,l,mid,lq,rq),query(id<<1|1,mid+1,r,lq,rq));
}


void solve(){
	cin>>s;
	int n = s.length();
	f(i,0,n){
		if(s[i] == '(') arr[i] = 1;
		else arr[i] = -1;
	}
	f(i,1,n){
		arr[i] += arr[i-1];
	}
	build(1,0,n-1);
	int q; cin>>q;
	while(q--){
		ll l,r; cin>>l>>r;
		l--; r--;
		cout<<query(1,0,n-1,l,r).L<<'\n';
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