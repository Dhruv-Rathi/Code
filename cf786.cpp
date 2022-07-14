#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define vi vector<ll>
#define vvi vector<vi>
#define f(x,a,b) for(int x=a;x<b;x++)
#define pb push_back
#define eb emplace_back //faster than push_back
#define mod1 1000000007
#define mod2 998244353
#define ss second
#define ff first
#define all(a) a.begin(), a.end()
#define vecpii vector<pair<int,int>>
#define test(t) int tc; cin>>tc; while(tc--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}

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
	int x,y; cin>>x>>y;
	if(y%x){
		cout<<0<<' '<<0<<'\n';
		return;
	}
	cout<<1<<' '<<(y/x)<<'\n';
}
 
void solve2(){
	string s; cin>>s;
	int ans = 0;
	ans+=1+(s[0]-'a')*25;
	if(s[1]<s[0]){
		ans+=(s[1]-'a');
	}else{
		ans+=s[1]-'a'-1;
	}

	cout<<ans<<'\n';
}

void solve3(){
	string s,t; cin>>s; cin>>t;
	bool f = 0;
	f(i,0,t.length()){
		if(t[i] == 'a') {
			f=1; break;
		}
	}
	if(t == "a"){
		cout<<1<<'\n'; return;
	}

	if(t.length()>1 && f){
		cout<<-1<<'\n'; return;
	}

	ll ans = (ll)pow(2,s.length());
	cout<<ans<<'\n';

}

void solve4(){
	ll n; cin>>n;
	vi a(n), b(n);
	f(i,0,n) {
		cin>>a[i];
		b[i] = a[i];
	}
	sort(all(b));


	if(n%2){
		if(b[0]!=a[0]){
			cout<<"NO\n"; return;
		}
		f(i,1,n-1){
			if((a[i]==b[i]&&a[i+1]==b[i+1])||(a[i+1]==b[i]&&a[i]==b[i+1])){
				i++;continue;
			}else{
				cout<<"NO\n"; return;
			}
			i++;
		}
	}
	else{
		f(i,0,n-1){
			if((a[i]==b[i]&&a[i+1]==b[i+1])||(a[i+1]==b[i]&&a[i]==b[i+1])){
				i++;
				continue;
			}else{
				cout<<i<<"NO\n"; return;
			}
			i++;
		}
	}

	cout<<"YES\n";
}

bool check(ll x, ll n, ll a[]){
	for(ll i=1;i<n;i++){
		if((a[i]+a[i-1])<=3*x && 2*x>=max(a[i],a[i-1])) return true;
	}
	for(ll i=0;i+2<n;i++){
		ll mi = min(a[i],a[i+2]), ma = max(a[i],a[i+2]);
		if(x>=(mi+(ma-mi+1)/2)) return true;
	}
	return false;
}

void solve5(){
	ll n; cin>>n;
	ll a[n], b[n];
	f(i,0,n) {
		cin>>a[i];
		b[i] = a[i];
	}
	sort(b,b+n);
	ll ans = 0;
	ll lo = 0, hi = (b[0]+1)/2 + (b[1]+1)/2;
	while(lo<=hi){
		ll mid = (lo+hi)/2;
		if(check(mid,n,a)){
			ans = mid;
			hi = mid-1;
		}else{
			lo = mid+1;
		}
	}

	if(lo>hi && ans==0){
		ans = hi;
	}

	cout<<ans<<'\n';
}


void solve6(){
	ll n; cin>>n;
	vi a(n), b(n);
	f(i,0,n){
		cin>>a[i];
		b[i] = a[i];
	}
	ll ans1=0, ans2=0, ans3=0;
	sort(all(b));
	ans1+=b[0]/2 + b[1]/2 + b[0]%2 + b[1]%2;

	f(i,0,n-1){
		ll x = min(a[i],a[i+1]);
		ll y = (a[i]+a[i+1]) - x;
		
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