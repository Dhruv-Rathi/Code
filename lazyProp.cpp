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
	int sum, maxr, lazy;
	node(){
		sum = 0;
		maxr = 0;
		lazy = 0;
	}
};

node merge(node a, node b){
	node temp;
	temp.sum = a.sum+b.sum;
	temp.maxr = max(a.maxr,b.maxr);
	return temp;
}

#define MAXN 100100
node t[4*MAXN];

void push(int id, int l, int r){
	if(t[id].lazy){
		t[id].sum = t[id].lazy*(r-l+1);
		t[id].maxr = t[id].lazy;
		if(l!=r){
			t[id<<1].lazy = t[id].lazy;
			t[id<<1|1].lazy = t[id].lazy;
		}
		t[id].lazy = 0;
	}
}

void update(int id, int l, int r, int lq, int rq, int v){
	push(id,l,r);
	if(lq>r || l>rq) return;
	if(lq<=l && rq>=r){
		t[id].lazy = v;
		push(id,l,r);
		return;
	}
	int mid = (l+r)>>1;
	update(id<<1,l,mid,lq,rq,v);
	update(id<<1|1,mid+1,r,lq,rq,v);
	t[id] = merge(t[id<<1],t[id<<1|1]);
}	

node query(int id,int l, int r,int lq, int rq){
	push(id,l,r);
	if(lq>r || l>rq) return node();
	if(lq<=l && rq>=r){
		return t[id];
	}
	int mid = (l+r)>>1;
	return merge(query(id<<1,l,mid,lq,rq),query(id<<1|1,mid+1,r,lq,rq));
}

// Every number given in the input is positive.
void solve(){
	update(1,0,9,0,5,3);
	update(1,0,9,6,9,4);
	node x = query(1,0,9,3,6);
	cout<<x.maxr<<' '<<x.sum<<'\n';
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