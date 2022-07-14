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
	string s1; cin>>s1;
	string s2; cin>>s2;
	int i=0,k=1;
	while(i<s1.length()){
		if(s2 == s1.substr(i,4)){
			cout<<k<<'\n'; return;
		}
		k++;i+=4;
	}

}

void solve2(){
	int n;
	 cin>>n;
	vpll a(n);
	vll b(n); ll ans = 0;
	ll s1=0, s2=0;
	f(i,0,n) {
		cin>>a[i].F;
		s1+=a[i].F;
	}
	f(i,0,n) {
		cin>>a[i].S;
		s2+=a[i].S;
	}
	ans+=s2*n-s1;
	f(i,0,n){
		b[i] = (a[i].F - a[i].S);
	}

	sort(all(b));

	f(i,0,n){
		ans+=b[i]*(i+1);
	}

	cout<<ans<<'\n';


}

void solve3(){
	vector<string> s(n+1);
	int n,k; cin>>k>>n;
	f(i,0,n+1){
		if(i==0){
			s[i] = '0';
		}else if(i==1 || i==2){
			s[i] = (char)('0'+k);
		}else{
			s[i] = s[i-1]+s[i-2]+s[i-3];
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

 
    test(t)
    solve2();
    
    
    
}