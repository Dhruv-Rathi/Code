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

ll dist[404][404];

void solve(){
	ll n,m,q; cin>>n>>m>>q;

	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			if(i!=j) dist[i][j] = 1e18;
		}
	}

	for(ll i=0;i<m;i++){
		ll a,b,c;
		cin>>a>>b>>c; a--; b--;
		dist[a][b] = min(dist[a][b], c);
		dist[b][a] = dist[a][b];
	}


	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}

	while(q--){
		ll a,b; cin>>a>>b;
		a--;b--;
		if(dist[a][b]==1e18 || dist[b][a]==1e18){
			cout<<-1<<'\n';
		}else{
			cout<<dist[a][b]<<'\n';
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