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
#define FOR(x,a,b) for(int x=a;x<b;x++)
#define FORr(x,a,b) for(int x=a;x>=b;x--)
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
	int n; cin>>n;
	vii p(n); cin>>p;
	if(n==1){ cout<<-1<<'\n'; return; }
	bool f = 0;
	map<int , int > m;
	vii ans(n);
	if(p[n-1] == n){
		ans[n-2] = n; m[n]++;
		f = 1;
	}
	int i=1;
	
	FOR(i,0,n){
		if(f && i == n-2) continue;
		FOR(j,1,n+1){
			if(m[j] == 0 && p[i]!=j){
				ans[i] = j; m[j]++; break;
			}
		}
	}
	cout<<ans<<'\n';
}
 
signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    test(t)
    solve();
    
}