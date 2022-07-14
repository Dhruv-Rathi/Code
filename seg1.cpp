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

int n;
int arr[100100];

struct node{
	int mini;
	int cnt;
	node(int m = 1e9,int c = 0){
		mini = m;
		cnt = c;
	}
};

node merge(node a, node b){
	if(a.mini == b.mini){
		return node(a.mini, a.cnt+b.cnt);
	}else if(a.mini<b.mini) return a;
	else return b;
}


node t[400400];

void build(int id, int l, int r){
	if(l == r){
		t[id] = node(arr[l],1);
		return;
	}
	int mid = (l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	t[id] = merge(t[id*2],t[id*2+1]);
}

void update(int id, int l, int r, int pos, int val){
	if(pos<l || pos>r) return;
	if(l == r){
		t[id] = node(val,1);
		arr[l] = val;
		return;
	}
	int mid = (l+r)/2;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
	t[id] = merge(t[id*2],t[id*2+1]);
}

node query(int id, int l, int r, int lq, int rq){
	if(l>rq || r<lq){
		return 0;
	}
	if(lq<=l && r<=rq){
		return t[id];
	}
	int mid = (l+r)/2;
	return merge(query(id*2,l,mid,lq,rq), query(id*2+1,mid+1,r,lq,rq));
}

void solve(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	build(1,0,n-1);
	int q; cin>>q;
	while(q--){
		int ch; cin>>ch;
		if(ch == 1){
			int x,v; cin>>x>>v;
			update(1,0,n-1,x,v);
		}else{
			int l,r; cin>>l>>r;
			node x = query(1,0,n-1,l,r);
			cout<<x.mini<<' '<<x.cnt<<'\n';
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

 
    test(t)
    solve();
    
    
    
}