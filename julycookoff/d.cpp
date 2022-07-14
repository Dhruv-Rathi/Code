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
#define int long long


ll gcd(ll a, ll b){
	return (b==0)?a:(gcd(b, a%b));
}

ll lcm(ll a, ll b){
	return (a*b)/gcd(a,b) ;
}


ll power(ll a, ll b, ll N){ ll p = 1;
    while (b > 0){
        if (b & 1) p = ((p % N) * (a % N)) % N;
        a = ((a % N) * (a % N)) % N; b /= 2;
    } return p;
}


const int N = 1e6;
int sp[N];

void fastFact(){
	for(int i=2;i<=N;i++) sp[i] = i;

	// O(Nlog(logN))

	for(int i=2;i<=N;i++){
		if(sp[i] == i){ // That means it is a prime
			for(int j=2*i;j<=N;j+=i){
				if(sp[j] == j){
					sp[j] = i;
				}
			}
		}
	}
}

vector<int> primeFact(int x){
	vector<int> ans;
	while(x>1){
		ans.push_back(sp[x]);
		x/=sp[x];
	}
	return ans;
}
 

void solve(){
	ll n; cin>>n;
	vll a(n);
	cin>>a;
	sort(all(a));
	// cout<<a<<'\n';
	vector<ll> mp(100010,0);

	ll cnt = 1, ans = 0;
	f(i,1,n){
		if(a[i] == a[i-1]) cnt++;
		else{
			ll x = a[i-1];
			vector<ll> pf = primeFact(x);
// 			cout<<pf<<'\n';
			for(auto z: pf){
				mp[z]+=cnt;
			}
			// if(cnt>=2){
			// 	ans += power(2, cnt, mod);
			// 	ans -= (cnt+1)%mod;
			// 	ans = (ans+mod)%mod;
				
			// }
			cnt=1;
		}
	}
	ll x = a[n-1];
	vector<int> pf = primeFact(x);
	for(auto z: pf){
		mp[z]+=cnt;
	}
	// if(cnt>=2){
	// 	ans += power(2, cnt, mod);
	// 	ans -= (cnt+1)%mod;
	// 	ans = (ans+mod)%mod;
	// }

	for(auto z: mp){
		if(z>=2){
			ans+=power(2, z,mod);
			ans -= (z+1)%mod;
			ans = (ans+mod)%mod;
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
 
   fastFact();
 
    ll tc = 1;
    cin>>tc;
    for(int i=1;i<=tc;i++){
    //	cout<<"Case #"<<i<<": ";
    	solve();
    }
    
}