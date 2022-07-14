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
#define int long long
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
	int n; cin>>n;
	int a[n], e=0, o=0;
	f(i,0,n){
		cin>>a[i];
		o+=a[i]%2;
		e+=1-a[i]%2;
	}
	sort(a,a+n);
	ll ans = 0;
	if(e%2){
		cout<<"errorgorn\n";
	}else{
		cout<<"maomao90\n";
	}
}

void solve2(){
	string s; cin>>s;
	int a = 0, b = 0;
	int i = 0;
	int n = s.length();
	while(s[i] == 'A' && i<n){
		i++;
		a++;
	}
	if(i == n){
		cout<<"NO\n"; return;
	}
	else if(a==0){
		cout<<"NO\n"; return;
	}
	b=1; i++;a=0;
	for(;i<s.length();i++){
		if(s[i] == 'A'){
			a++;
			b = 0;
		}
		else if(s[i] == 'B'){
			if(a == 0){
				cout<<"NO\n"; return;
			}
			a=0;b++;
		}
		if(b>1){
			cout<<"NO\n";
		}
	}

	cout<<"YES\n";
}

void solve3(){
	string s; cin>>s;
	int i=0, n = s.length(), a=0, b=0;
	while(i<n){
		while(s[i] == 'A' && i<n){
			i++;
			a++;
			b=0;
		}

		if(a==0){
			cout<<"NO\n"; return;
		}
		if(s[i]!='B' || i==n){
			cout<<"NO\n"; return;
		}
		if(s[i] == 'B'){
			b++;
		}
		i++;
		while(s[i] == 'B' && i<n){
			b++;
			i++;
		}
		if(b>1 && i!=n){
			cout<<"NO\n";
			return;
		}
		if(i == n && b>1){
			if(a<=1){
				cout<<"NO\n";
				return;
			}
		}
		
	}
	cout<<"YES\n";
}

void solve4(){
	ll n; cin>>n;
	ll a[n];
	f(i,0,n){
		cin>>a[i];
	}
	ll cnt = 0;
	
	// cout<<cnt<<' ';
	
	ll f1=-1, f2 = -1;;
	f(i,0,n){
		if(a[i] == a[i+1]){
			f1 = i; break;
		}
	}
	for(ll i=n-1;i>0;i--){
		if(a[i] == a[i-1]){
			f2 = i; break;
		}
	}

	cout<<(f2-f1+1)<<' ';
	cnt = f2-f1+1;
	ll ans = 0;
	if(cnt<=2){
		cout<<0<<'\n';
		return;
	}
	if(cnt==3 || cnt == 4){
		cout<<1<<'\n';
		return;
	}
	cnt-=2;
	while(cnt){
		ans+=cnt/2;
		int x = cnt%2;
		if(x && cnt>1) ans++;
		cnt/=2;
	}
	cout<<ans<<'\n';
}

void solve5(){
	ll n; cin>>n;
	ll a[n];
	f(i,0,n) cin>>a[i];
	ll f1=1e9, f2 = 0;
	f(i,0,n-1){
		if(a[i] == a[i+1]){
			f1 = min(f1, i);
			f2 = max(f2,i);
		}
	}
	if(f1 == f2 || f1 == 1e9){
		cout<<0<<'\n';return;
	}
	if(f2-f1<3){
		cout<<1<<'\n';
	}
	else{
		cout<<(f2-f1-1)<<'\n';
	}
}

int cnt[200005];

void solveD(){
	int n; cin>>n;
	int a[n], b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	f(i,1,n+1) cnt[i] = 0;
	int i=0, j=0; bool pos = 1;
	while(j<n){
		if(a[i] == b[j] && i<n && j<n){
			i++; j++;
			continue;
		}
		if(cnt[b[j]]>0 && b[j] == b[j-1]){
			cnt[b[j++]]--;
		}
		else if(i<n){
			cnt[a[i++]]++;
		}else{
			pos = 0; break;
		}
	}
	if(pos){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
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
    solveD();
    
    
    
}