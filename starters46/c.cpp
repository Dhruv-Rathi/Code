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

bool check(char c){
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
	return false;
}

void solve(){
	ll n; cin>>n;
	string s; cin>>s;
	string ans = "";

	vector<ll> pos;
	for(ll i=0;i<n;i++){
		if(check(s[i])){
			pos.PB(i);
		}
	}
	if(pos.size() == 0){
		cout<<s<<'\n'; return;
	}

	// cout<<pos<<'\n';
	ll x = (pos.size()%2);
	reverse(all(pos));

	for(ll i = 0; i<(pos.size()-1); i+=2){

		for(ll j= (pos[i]-1);j>=pos[i+1];j--){
			ans+=s[j];
		}
	}

	if(pos.size()%2 == 1){
		for(ll i = (pos[pos.size()-1]-1); i>=0; i--){
			ans+=s[i];
		}
	}else{
		for(ll i=0;i<pos[pos.size()-1];i++){
			ans+=s[i];
		}
	}

	reverse(all(pos));

	for(ll i=(1-x); i<(pos.size()-1) ;i+=2){
		for(ll j = pos[i]; j<pos[i+1]; j++){
			ans+=s[j];
		}
	}
	for(ll i = pos[pos.size()-1];i<n;i++){
		ans+=s[i];
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