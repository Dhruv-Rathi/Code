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
	ll n; cin>>n;
	map<ll,ll> mp;
	vll a(n);
	ll npos = 0, nneg = 0, nze = 0;;
	f(i,0,n){
		cin>>a[i];
		if(a[i]>0) npos++;
		else if(a[i]<0) nneg++;
		else nze++;
		mp[a[i]]++;
	}
	sort(all(a));
	if(npos>=3 || nneg>=3){
		no; return;
	}
	if(nze>0 && (npos == 2 || nneg == 2)){
		no; return;
	}
	if(npos == 1 && nneg == 1 && nze > 0){
		if(a[n-1]+a[0] == 0) yes;
		else no;
		return;
	}

	if(nze >= (n-1)){
		yes; return;
	}

	

	f(i,0,n){
		f(j,i+1,n){
			f(k,j+1,n){
				if(mp[a[i]+a[j]+a[k]] == 0){
					no; return;
				}
			}
		}
	}

	yes;

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