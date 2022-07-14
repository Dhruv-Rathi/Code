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



bool comp(const pair<int,int> &a,const pair<int,int> &b){return (((a.F)*(a.F)+(a.S)*(a.S)) < ((b.S)*(b.S)+(b.F)*(b.F)));}

ll power(ll a, ll b, ll N){ ll p = 1;
    while (b > 0){
        if (b & 1) p = ((p % N) * (a % N)) % N;
        a = ((a % N) * (a % N)) % N; b /= 2;
    } return p;
}

const int N = 500010;

int fact[N];

void pre(){
	fact[0] = 1;
	for(int i=1;i<N;i++){
	fact[i] = 1LL*fact[i-1]*i%mod;
	}
}

int ncr(int n, int r){
	if(n<r) return 0;
	int ans = fact[n];
	ans = 1LL*ans*power(fact[n-r],mod-2,mod)%mod;
	ans = 1LL*ans*power(fact[r],mod-2,mod)%mod;
	ans = (ans+mod)%mod;
	return ans;
}

void solve(){
	ll n,s; cin>>n>>s;
	ll a[n]; map<ll,ll> m;

	f(i,0,n){
		cin>>a[i];
		m[a[i]]++;
	}

	f(i,0,n){
		if((m[s-a[i]]>0 && a[i]!=(s-a[i]))|| (m[s-a[i]]>1))
		{
			cout<<"Y\n"; return;
		}
	}
	cout<<"N\n";

}

ll distance(ll x,ll y){
	return (x*x + y*y);
}

void solve2(){
	ll n,k; cin>>n>>k;
	priority_queue<pair<ll, pair<ll,ll>>> pq;
	f(i,0,n){
		ll x,y;
		cin>>x>>y;
		ll d = distance(x,y);
		if(pq.size()<k){
			pq.push({d,{x,y}});
		}
		else {
			pair<ll,pair<ll,ll>> top = pq.top();
			pair<ll,pair<ll,ll>> cur = {d,{x,y}};
			if(top>cur){
				pq.pop();
				pq.push(cur);
			}
		}
	}

	vpll ans;
	while(pq.size()){
		pair<ll,pll> top = pq.top();
		ans.pb(top.S);
		pq.pop();
	}
	reverse(all(ans));
	for(auto v: ans){
		cout<<v.F<<' '<<v.S<<'\n';
	}
}


string s,res;
vector<string> ans;
string key[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void rec(int i){
	if(i==s.length()){
		ans.pb(res); return;
	}

	for(auto v: key[s[i]-'0']){
		res.push_back(v);
		rec(i+1);
		res.pop_back();
	}
}

void solve3(){
	cin>>s;
	rec(0);
	for(auto v: ans){
		cout<<v<<'\n';
	}
}


void solve4(){
	string s1,s2;
	cin>>s1>>s2;
	
	string ans = "";
	char prev = '0';
	if(s1.length()>s2.length()){
		string temp = s1;
		s1 = s2;
		s2 = temp;
	}

	// cout<<<<'\n';
	// f(i,0,){
	// 	cout<<"HHHHHHH"<<'\n';
	// }

	reverse(all(s1));
	int x = s2.length()-s1.length();
	f(i,0,x){
		s1 += '0';
	}

	reverse(all(s2));


	for(int i=0;i<s1.length();i++){
		if(s1[i] == '0' && s2[i] == '0'){
			ans+=prev;
			prev = '0';
		}else if(s1[i]=='0' && s2[i]=='1'){
			if(prev == '0'){
				ans+='1';
			}else{
				ans+='0';
			}
		}else if(s1[i] == '1' && s2[i] == '0'){
			if(prev == '0'){
				ans+='1';
			}else{
				ans+='0';
			}
		}else{
			if(prev == '0'){
				ans+='0';
				prev = '1';
			}else{
				ans+='1';
			}
		}
	}
	if(prev == '1') ans+='1';

	reverse(all(ans));
	cout<<ans<<'\n';
}

void solve5(){
	int n; cin>>n;
	vii a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ma=0, cnt=0;

	for(int i=0;i<n;i++){
		ma = max(ma,a[i]);
		if(ma == (i+1)) cnt++;
	}
	cout<<cnt<<'\n';
}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    test(t)
    solve5();
    
    
    
}