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

ll n;

ll p[100100];
ll t[400400];
vpll h;

void build(ll id, ll l, ll r){
	if(l == r){
		t[id] = 1;
		return;
	}
	ll mid = (l+r)/2;
	build(2*id,l,mid);
	build(2*id+1,mid+1,r);
	t[id] = (t[2*id] + t[2*id+1]);
}

void update(ll id, ll l, ll r, ll pos, ll val){
	if(pos<l || pos>r) return;
	if(l == r){
		t[id] = val; return;
	}
	ll mid = (l+r)/2;
	update(2*id,l,mid,pos,val);
	update(2*id+1,mid+1,r,pos,val);
	t[id] = (t[2*id] + t[2*id+1]);
}

ll query(ll id, ll l, ll r, ll x){
	if(l == r){
		return l;
	}
	ll mid = (l+r)/2;
	if(t[2*id]>=x) return query(2*id,l,mid,x);
	return query(2*id+1,mid+1,r,x-t[2*id]);
}


void solve(){
	cin>>n;
	vll arr(n);

	f(i,0,n){
		ll x; cin>>x;
		h.pb(mp(x,i));
	}
	
	f(i,0,n){
		cin>>p[i];
	}

	sort(all(h));
	
	build(1,0,n-1);

	f(i,0,n){
		ll x = h[i].F, y = h[i].S;

		ll pos = query(1,0,n-1,p[y]+1);
		cout<<pos<<' ';
		arr[pos] = y;
		update(1,0,n-1,pos,0);
	}
	cout<<'\n';
	f(i,0,n){
		cout<<(arr[i]+1)<<' ';
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