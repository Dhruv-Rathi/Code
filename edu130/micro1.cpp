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

void solve(){
	ll n,a,b;
	cin>>n>>a>>b;
	if(a == b) {cout<<0<<'\n'; return;}
	ll ans = 0;
	while(a!=b){
		if(a>b){
			a/=2; ans++;
		}else{
			b/=2; ans++;
		}
	}
	cout<<(2*ans-1)<<'\n';
}
void solve2(){
	int dx[] = {1,0,-1,0};
	int dy[] = {0,-1,0,1};

	ll n,l; cin>>n>>l;
	vpll tur;
	for(ll i=0;i<l;i++){
		ll tim, turn; cin>>tim>>turn;
		tur.PB({tim,turn});
	}
	sort(all(tur));

	ll x=0, y=0,k=0, prev = 0;
	for(ll i=0;i<l;i++){
		if(tur[i].S == 0){
			x+=dx[k]*(tur[i].F-prev); y+=dy[k]*(tur[i].F-prev);
			prev = tur[i].F;
			k = (k+3)%4;
		}else{
			x+=dx[k]*(tur[i].F-prev); y+=dy[k]*(tur[i].F-prev);
			prev = tur[i].F;
			k = (k+1)%4;
		}
	}
	x+=dx[k]*(n-prev); y+=dy[k]*(n-prev);
	// cout<<x<<' '<<y<<'\n';
	cout<<(x+y)<<'\n';
}

void solve3(){
	ll n,p,ff,u,d; cin>>n>>p>>ff>>u>>d;
	ll dis[n+1];
	f(i,1,n+1) dis[i] = 1e18;

	queue<ll> q;
	q.push(p);
	dis[p] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(x+u<=n && dis[x+u]>(dis[x]+1)){
			dis[x+u] = dis[x]+1;
			q.push(x+u);
		}
		if(x-d>=1 && dis[x-d]>(dis[x]+1)){
			dis[x-d] = (dis[x]+1);
			q.push(x-d);
		}
	}
	if(dis[ff]==1e18){
		cout<<-1<<'\n';
	}else{
		cout<<dis[ff]<<'\n';
	}
}
signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    // test(t)
    solve3();
    
}