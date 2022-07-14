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


vector<long long> prime_factorisation(long long n)
{
    //spf is smallest prime factor
    map<long long, long long> spf;
    vector<long long> ans(0);
    for(long long i = 2; i <= n; i++) spf[i] = i;

    for (long long i = 2; i <= n; i++)
        if (spf[i] == i)
            for (long long j = i * i; j <= n; j += i)
                if (spf[j] == j)
                    spf[j] = i;

    while (n != 1)
    {
        ans.push_back(spf[n]);
        n /= spf[n];
    }
    return ans;
}

void solve(){
	ll n; cin>>n;
	if(n == 2){
		cout<<1<<'\n'; return;
	}
	ll ans = 2;

	vll factor = prime_factorisation(n);
	set<ll> st;
	for(auto v: factor){
		st.insert(v);
	}
	cout<<st.size()<<'\n';
	cout<<factor<<'\n';

}

void solve2(){
	ll n; cin>>n;
	ll ans = 0;
	for(int i=1;i<=sqrt(n);i++){
		if(n%i == 0){
			if(n - i == i) ans++;
			else ans+=2 ;
			if(n/i == i) continue;
			if(n - (n/i)  == n/i) ans++;
			else ans+=2;
			// cout<<i<<' '<<(n - i)<<'\n';
			// cout<<(n/i)<<' '<<(n-n/i)<<'\n';
		}
	}
	cout<<(ans-2)<<'\n';
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
    	solve2();
    }
    
}