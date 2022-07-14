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
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define int long long 

template <class T> ostream &operator<<(ostream &os, const vector<T> a){ for (auto ele : a) os << ele << " "; return os;} 
template <class T> istream &operator>>(istream &is, vector<T> &a){ for (auto &ele : a) is >> ele; return is; }

void solve(){
	int n, m; 
	cin>>n>>m;
	vii a(m);
	vii cnt(n,0);
	cin>>a;
	sort(all(a));
	int ans = 0;
	// cout<<a<<'\n';

	f(i,0,m){
		cnt[a[i]-1]++;
	}
	// cout<<cnt<<'\n';
	sort(cnt.rbegin(), cnt.rend());
	int lo = 0, hi = cnt[0]; ans = hi;

	while(lo<=hi){
		int mid = (lo+hi)/2;
		bool f = 0;
		int prev = 0;
		for(int i=0;i<n;i++){
			if(cnt[i]+2*prev <= mid){
				prev = 0;
				continue;
			}
			else{
				if(cnt[i]>mid){
					prev+=(cnt[i]-mid);
				}else{
					prev -= (mid-cnt[i])/2;
				}
			}
		}

		if(prev == 0){
			ans = mid;
			hi = mid-1;
		}else{
			lo = mid+1;
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
 
    ll tc = 1;
    cin>>tc;
    for(int i=1;i<=tc;i++){
    //	cout<<"Case #"<<i<<": ";
    	solve();
    }
    
}