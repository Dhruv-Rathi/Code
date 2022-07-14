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
#define f(x,a,b) for(ll x=a;x<b;x++)
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

int n,D,arr[100100];
map<int,int> compVal;

int t[400400];

#define mid ((l+r)>>1)
void update(int id, int l, int r, int pos, int val){
	if(pos<l || pos>r) return;
	if(l == r){
		t[id] = max(t[id],val);
		return;
	}
	update(id<<1,l,mid,pos,val);
	update(id<<1|1,mid+1,r,pos,val);
	t[id] = max(t[id<<1], t[id<<1|1]);
}

int  query(int id, int l, int r, int lq, int rq){
	if(lq>r || l>rq) return 0;
	if(lq<=l && rq>=r){
		return t[id];
	}
	return max(query(id<<1,l,mid,lq,rq),query(id<<1|1,mid+1,r,lq,rq));
}
#undef mid

void solve(){
	cin>>n;
	f(i,0,n){
		cin>>arr[i];
		compVal[arr[i]];
	}
	cin>>D;
	int cnt = 0;
	for(auto &v: compVal){
		v.S = cnt++;
	}
	int ans = 0;
	int dp[n];
	f(i,0,n){
		int lo = arr[i]-D;
		int hi = arr[i]+D;
		auto it = compVal.upper_bound(hi);
		it--;
		hi = it->S;

		it = compVal.lower_bound(lo);
		lo = it->S;

		dp[i] = query(1,0,cnt-1,lo,hi)+1;
		ans = max(ans, dp[i]);
		update(1,0,cnt-1,compVal[arr[i]],dp[i]);
	}
	cout<<ans<<'\n';

}
 
signed main()
{
    fast
    
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

 
    // test(t)
    solve();
    
    
    
}