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
	string s,t; cin>>s>>t;
	map<char,ll> m;
	int l1=s.length(),l2=t.length();
	if(l1!=l2){
		cout<<"N\n"; return;
	}
	for(int i=0;i<l1;i++){
		m[s[i]]++;
	}
	for(int i=0;i<l1;i++){
		if(m[t[i]]){
			m[t[i]]--;
		}else{
			cout<<"N\n"; return;
		}
	}
	cout<<"Y\n"; 
}


ll power(ll a,ll b,ll m){
	ll p=1;
	while(b){
		if(b&1) p = ((p%m)*(a%m))%m;
		a = ((a%m)*(a%m))%m;
		b>>=1;
	} return p;
}

void solve2(){
	string s;
	cin>>s;
	int n = s.length();
	ll ans = 0;
	ll k = n-1;
	for(int i=0;i<n;i++){
		ans = ((ans%mod)+((s[i]-'A'+1)*power(26,k,mod))%mod)%mod;
		k--;
	}

	cout<<(ans+mod)%mod<<'\n';;
}

void solve3(){
	ll n; cin>>n;
	string ans="";
	while(n){
		ans+=(char)((n-1)%26+'A');
		n = (n-1)/26;
	}
	reverse(all(ans));
	cout<<ans<<'\n';
}

string s;
string res;
vector<string> ans;

void rec(int i){
	if(i == s.length()){
		ans.pb(res); 
		return;
	}

	int val = s[i]-'0';
	if(val>=1 && val<=9){
		res.push_back(char('A'+val-1));
		rec(i+1);
		res.pop_back();
	}
	if(i+1<s.length()){
		val*=10;
		val+=s[i+1]-'0';
		if(val>=10 && val<=26){
			res.push_back(char('A'+val-1));
			rec(i+2);
			res.pop_back();
		}
	}
}

void solve4(){

	ans.clear();

	cin>>s;

	rec(0);
	sort(all(ans));

	for(auto v: ans){
		cout<<v<<'\n';
	}

} 

void solve5(){
	ll n,m ; cin>>n>>m;
	vll a(n), pre(n+1,1),suf(n+1,1);
    f(i,0,n){
        cin>>a[i];
    }
    
    f(i,2,n+1){
        pre[i] = (pre[i-1]*a[i-2])%m;
    }
    for(int i=n-1;i>=1;i--){
        suf[i] = suf[i+1]*a[i]%m;
    }
    f(i,1,n+1){
        cout<<(pre[i]*suf[i])%m<<' ';
    }
}

signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    // test(t)
    solve5();
    
    
    
}