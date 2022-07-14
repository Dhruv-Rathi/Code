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
#define test(t) int tc; cin>>tc; while(tc--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}

int n;
int cost[100100];
int lo[100100];
int hi[100100];

// Segment tree
int t[400400];

void build(int id, int l, int r){
	
	t[id] = 0;
	if(l == r) {
		return;
	}
	int mid = (l+r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);

	// merge logic:
	// t[id] = min(t[id*2], t[id*2]+1);
}

void update(int id, int l, int r, int x, int y){
	if(l>r||x<l||x>r) return;
	if(l==r){
		t[id] = y;
		return;
	}
	update(id*2, l, mid,x,y);
	update(id*2+1, mid+1, r,x,y);
	t[id] = min(t[id*2], t[id*2]+1);
}

int query(int id, int l, int r, int lq, int rq){
	if(lq>r || l>rq) return 1e9;
	if(lq<=l && r<=rq) {
		return t[id];
	}
	return min(query(id*2, l, mid,lq,rq), query(id*2+1, mid+1, r,lq,rq));
}

int dp[100100];

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>lo[i]>>hi[i];
	}
	for(int i=1;i<=n;i++){
		cin>>cost[i];
	}
	build(1,1,n);
	for(int i=n;i>0;i--){
		if(i==n){
			dp[i] = cost[n];
		}else{
			int ql = i+lo[i];
			int qr = i+hi[i];
			dp[i] = cost[i] + query(1,1,n,ql,qr);
		}
		update(1,1,n,i,dp[i]);
	}
	cout<<dp[1]<<'\n';
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