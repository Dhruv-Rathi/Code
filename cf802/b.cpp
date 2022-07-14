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
	string s; cin>>s;
	ll ans = 0;
	if(s[0]!='9'){
		string s1="";
		f(i,0,n){
			s1+=to_string('9'-s[i]);
		}
		cout<<s1<<'\n';
	}else{
		string s1 = "";
		
		bool f = 0;
		frev(i,n-1,0){
			if((s[i] == '1' || s[i] == '0') && f == 0){
				s1+=to_string('1'-s[i]);
				// f = 1;
			}else if(f == 0){
				string z ="";z+= s[i];
				s1+=to_string(11-stoi(z));
				f = 1;
			}else{
				if(s[i] == '0'){
					s1+='0';
					f = 0;
				}else{
					string z ="";z+= s[i];
					s1+=to_string(10-stoi(z));
				}
			}
		}
		reverse(all(s1));
		cout<<s1<<'\n';
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