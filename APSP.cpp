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



void solve(){
	ll n; cin>>n;
	ll dist[510][510];

	f(i,0,n){
		f(j,0,n){
			cin>>dist[i][j];
		}
	}

	ll x[510];
	vll ans;
	f(i,0,n){ cin>>x[i]; x[i]--;}

	for(int i=n-1;i>=0;i--){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				dist[j][k] = min(dist[j][k],dist[j][x[i]]+dist[x[i]][k]);
			}
		}
		ll temp = 0;
		for(int j=i;j<n;j++){
			for(int k=i;k<n;k++){
				temp+=dist[x[j]][x[k]];
			}
		}
		ans.pb(temp);
	}
	reverse(all(ans));
	cout<<ans<<'\n';

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