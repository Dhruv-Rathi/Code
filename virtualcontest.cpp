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
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test(t) int t; cin>>t; while(t--)
 
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}


ll power(ll a, ll b){ ll p = 1;ll N = 1000000007;
    while (b > 0){
        if (b & 1) p = ((p % N) * (a % N)) % N;
        a = ((a % N) * (a % N)) % N; b /= 2;
    } return p;
}

const int N = 500010;


int fact[N];
int invfact[N];
void pre(){
	fact[0] = 1;
	for(int i=1;i<N;i++){
	fact[i] = 1LL*fact[i-1]*i%mod;
	}
    invfact[0] = 1;
    for(int i=1;i<N;i++){
        invfact[i] = power(fact[i],mod-2)%mod;
    }
}

int ncr(int n, int r){
	if(n<r) return 0;
	int ans = fact[n];
	ans = 1LL*ans*invfact[n-r]%mod;
	ans = 1LL*ans*invfact[r]%mod;
	ans = (ans+mod)%mod;
	return ans;
}



void solve()
{
	int n,l; cin>>n>>l;
	ll x[n];
	f(i,0,n){
		cin>>x[i];
	}
	ll y[l]={0};

	f(i,0,n){
		f(j,0,l){
			y[j] = y[j]+(x[i]%2);
			x[i]/=2;
		}
	}
	ll ans = 0;
	ll k = 1;
	f(i,0,l){
		if(y[i]>=(n-y[i])){
			ans += k;
		}
		k = k*2;
	}

	cout<<ans<<'\n';
}

void solve2() {
	int n; cin>>n;
        int ans = 2;
        int a[n];
        for(int i=0;i<n;i++){cin>>a[i];}
        int d = a[1] - a[0];
        int x = 2;
        for(int i=2;i<n;i++){
            if(a[i]-a[i-1] == d){
                x++;
            }else{
                
                x = 2;
                d = a[i]-a[i-1];
            }
            ans = max(ans,x);
		}
        cout<<ans<<'\n';
	
}
void solve3(){
	int a[6];
	f(i,0,6) cin>>a[i];
	string s; cin>>s;
	int t;
	f(i,0,s.length()){
		switch(s[i]){
			case 'N':
			t = a[0];
			a[0] = a[1];
			a[1] = a[5];
			a[5] = a[4];
			a[4] = t;
			break;
			case 'S':
			t = a[0];
			a[0] = a[4];
			a[4] = a[5];
			a[5] = a[1];
			a[1] = t;
			break;
			case 'E':
			t = a[0];
			a[0] = a[3];
			a[3] = a[5];
			a[5] = a[2];
			a[2] = t;
			break;
			case 'W':
			t  = a[0];
			a[2] = a[5];
			a[5] = a[3];
			a[3] = t;
			break;
		}
	}
	cout<<a[0]<<'\n';
}

void solve4(){
	int n,k; cin>>n>>k;
	ll a[n], b[31] = {0};
	f(i,0,n) {
		cin>>a[i];
		ll x = a[i];
		ll q = 0;
		while(x){
			b[q]+=x%2;
			x/=2;
			q++;
		}
	}
	f(i,0,31) cout<<b[i]<<' ';

	cout<<'\n';

}

void solve5(){
	ll n; cin>>n;
	ll a[n];
	f(i,0,n) {
		cin>>a[i];
	}

	ll s1=0,s2=0,s3=0,s4=0;

	for(ll i=0;i<31;i++){
		ll cnt = 0;
		for(ll j=0;j<n;j++){
			if(a[j]&(1LL<<i)){
				cnt++;
			}
		}
		s1 = ((s1%mod)+((1LL<<i)*((cnt%mod)*((n-cnt)%mod))%mod)%mod)%mod;
		if(cnt){
			s2 = ((s2%mod)+((1LL<<i)*power(2,n-1))%mod)%mod;
		}
		s3 = ((s3%mod)+((1LL<<i)*ncr(cnt,2)%mod)%mod)%mod;

		s4 = ((s4%mod)+((1LL<<i)*(power(2,cnt) - 1)%mod)%mod)%mod;
	}

	cout<<s1<<' '<<s2<<' '<<s3<<' '<<s4<<'\n';
}

void solve6(int tc){
	cout<<"Case #"<<tc<<": ";
	ll n,m; cin>>n>>m;
	vi a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

}

void solve7(){
	ll n,l,r; cin>>n>>l>>r;
	vi a(n);
	f(i,0,n){
		cin>>a[i];
	}
	sort(all(a));
	ll ans = 0;
	f(i,0,n){
		ans+= upper_bound(all(a),r-a[i])-a.begin();
		ans-= lower_bound(all(a),l-a[i])-a.begin();
		if(l<=2*a[i] && 2*a[i]<=r)
			ans--;
	}
	cout<<ans/2<<'\n';
}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    // pre();
 
    test(t)
    solve7();
    
    // cout<<((1<<3)-1)<<'\n';
    
}