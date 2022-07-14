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

template <class T> ostream &operator<<(ostream &os, const vector<T> a){ for (auto ele : a) os << ele << " "; return os;} 
template <class T> istream &operator>>(istream &is, vector<T> &a){ for (auto &ele : a) is >> ele; return is; }

void solve(){
	ll n,m; cin>>n>>m;
	ll s1 = 0, s2 = 0;
	vll a(n); 
	f(i,0,n){
		cin>>a[i];
		s1+=a[i];
	}
	ll k; cin>>k;
	vll b(k); 
	f(i,0,k){
		cin>>b[i];
		s2+=b[i];
	}
	if(s1!=s2){
		no; return;
	}

	vpll v1, v2;
	f(i,0,n){
		if(a[i]%m == 0){
			ll x = a[i];
			while(x%m == 0){
				x/=m;
			}
			if(!v1.empty() && v1.back().F == x){
				v1.back().S+=a[i]/x;
			}else{
				v1.PB({x, a[i]/x});
			}
		}else{
			if(!v1.empty() && v1.back().F == a[i]){
				v1.back().S++;
			}else{
				v1.PB({a[i], 1});
			}
		}
	}

	f(i,0,k){
		if(b[i]%m == 0){
			ll x = b[i];
			while(x%m == 0){
				x/=m;
			}
			if(!v2.empty() && v2.back().F == x){
				v2.back().S+=b[i]/x;
			}else{
				v2.PB({x,b[i]/x});
			}
		}else{
			if(!v2.empty() && v2.back().F == b[i]){
				v2.back().S++;
			}else{
				v2.PB({b[i],1});
			}
		}
	}

	if(v1 == v2){
		yes;
	}else{
		no;
	}

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