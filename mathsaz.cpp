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
#define S second
#define F first
#define all(a) a.begin(), a.end()
#define vecpii vector<pair<int,int>>
#define test(t) int tc; cin>>tc; while(tc--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
 
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}

ll power(ll a, ll b, ll N){ ll p = 1;
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
        invfact[i] = power(fact[i],mod-2,mod)%mod;
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

void solve(){
	int n,m,k; cin>>n>>m>>k;
	int ans = 0;
	for(int i=0;i<=n;i++){
		int temp = ncr(n,i);
		if(n+k-i*m-1<n-1) break;
		temp = 1LL * temp * ncr(n+k-i*m-1,n-1)%mod;
		temp = (temp+mod)%mod;
		if(i%2) ans = (ans-temp+mod)%mod;
		else ans = (ans+temp)%mod;
	}

	cout<<ans<<'\n';
}

int en[12345];
int getans(int l, int r){
	int i;
	int ans=0;
	f(i,0,min(l,r-1)+1){
		ans+=ncr(l,i)*ncr(r,i+1);
		ans%=mod;
	}
	return ans;
}

void solve2(){
	int n; cin>>n;
	int a[n];
	f(i,0,n) cin>>a[i];
	ll ans = power(2,n-1,mod)%mod;
	ans = (ans+mod)%mod;
	sort(a,a+n);
	f(i,0,n) en[a[i]] = i;
	int l,r;
	f(i,0,n){
		l = i;
		r = n-i-1;
		ans+=getans(l,r);
		l=i;
		r=n-en[a[i]]-1;
		ans-=getans(l,r);
	}

	ans%=mod;
	ans = (ans+mod)%mod;
	cout<<ans<<'\n';

}

void solve3(){
	int n; cin>>n;
	string s; cin>>s;
	int s1=0, s2=0, c1=0, c2=0;
	f(i,0,n/2){
		if(s[i]!='?') s1+=s[i]-'0';
		else c1++;
	}
	f(i,n/2,n){
		if(s[i]!='?') s2+=s[i]-'0';
		else c2++;
	}

	if(c1+c2 == 0){
		if(s1==s2){
			cout<<"Bicarp";
		}else cout<<"Monocarp";
		return;
	}
	// if(c1)
	s1+=c1*9;
	int L = s1-s2;
	s1-=c1*9; s2+=c2*9;
	int R = s1-s2;
	if((L+R)/2 == 0){
		cout<<"Bicarp";
	}
	else{
		cout<<"Monocarp";
	}


}

void solve4(){  // getting wa for Tough Mex
	int n; cin>>n;
	int a[n]; 
	f(i,0,n) {
		cin>>a[i];
		if(a[i]>n) a[i] = n+1;
	}

	sort(a,a+n);
	int ans = 0, ways = 1, prev = 0, idx = 0;
	for(int mex=1;mex<=n;mex++){
		while(prev+1<mex){
			int cnt=0;
			while(idx<n && a[idx]==prev+1){
				idx++;
				cnt++;
			}
			ways = ((ways%mod2)*((power(2,cnt,mod2)%mod2 + (mod2-1))%mod2))%mod2;
			ways = (ways+mod2)%mod2;
			prev++;
		}
		int pos = idx;
		for(int p=idx;p<n && a[p] == mex;p++) pos++;
		ans = ((ans%mod2) + ((mex%mod2)*((ways%mod2)*(power(2,n-pos,mod2)%mod2))%mod2)%mod2);
		ans = (ans+mod2)%mod2;
	}
	cout<<ans<<'\n';

}

void solve5(){
	int n; cin>>n;
	int a[n];
	int freq[n+3]={0};
	int bpref[n+3]={0};
	int pw[n+3]={0};
	f(i,0,n){
		cin>>a[i];
		if(a[i]>n) a[i] = n+1;
		freq[a[i]]++;
	}
	sort(a,a+n);
	int p = 1;
	int ans = 0;
	for(int i=n+1;i>=0;i--){
		bpref[i] = (bpref[i+1]+freq[i])%mod2;
	}
	for(int i=0;i<=n+1;i++){
		pw[i] = power(2,i,mod2);
	}

	for(int i=1;i<=n+1;i++){
		ans = (ans+(i*((p*pw[bpref[i+1]])%mod2))%mod2)%mod2;
		p = (p*(power(2,freq[i],mod2)-1))%mod2;
	}

	cout<<(ans+mod2)%mod2<<'\n';

}

void solve6(){
	ll n; cin>>n;
	ll e = n+1;
	ll o = 0;
	while(n){
		o+=n%2;
		n/=2;
	}
	o = power(2,o,mod);
	e -= o;
	cout<<e<<' '<<o<<'\n';
}
void solve7(){
	ll n; cin>>n;
	ll a[n], b[n];
	vi norm(n), invnorm(n);
	ll ans = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}

	for(int i=0;i<n;i++){
		int x = a[i];
		ll z=1;ll w=1;
		for(int j=2;j*j<=(x);j++){
			ll y = 0;
			while(a[i]%j == 0){
				a[i]/=j;
				y++;
			}
			z*=power(j,y%3,mod);
            w*=power(j,(3 - y%3)%3,mod);
		}
		if(a[i]>1){
			z*=power(a[i],1,mod);
            w*=power(b[i],2,mod);
		}
		norm[i] = z;
        invnorm[i] = w;
	}

	
	map<ll,ll> freq;
	for(int i=0;i<n;i++){
		freq[invnorm[i]]++;
	}
    for(int i=0;i<n;i++){
        freq[invnorm[i]]--;
        ans+=freq[norm[i]];
    }
	cout<<ans<<'\n';
}

// ll power(ll a, ll b, ll N){ ll p = 1;
//     while (b > 0){
//         if (b & 1) p = ((p % N) * (a % N)) % N;
//         a = ((a % N) * (a % N)) % N; b /= 2;
//     } return p;
// }

int prime[10000001];
void seive(){
    for(int i=1;i<10000001;i++){
        prime[i] = i;
    }
    for(int i=2;i<10000001;i++){
        if(prime[i] == i){
            for(int j=i;j<10000001;j+=i){
                prime[j] = i;
            }
        }
    }
}

void solve8(){
	ll n; cin>>n;
	ll ans = 1;
	map<ll,ll> m1;
	ll m; cin>>m;
	f(i,0,m){
		ll x; cin>>x;
		while(x>1){
            m1[prime[x]]++;
            x/=prime[x];
        }
	}
	f(i,1,n){
		ll m; cin>>m;
		map<ll,ll> m2;
		f(j,0,m){
			ll x; cin>>x;
			while(x>1){
                m2[prime[x]]++;
                x/=prime[x];
            }
		}
		for(auto e: m1){
			m1[e.F] = min(m1[e.F],m2[e.F]);
		}
	}
	for(auto e:m1){
		
			ans = ((ans%mod)*(power(e.F,e.S,mod)%mod))%mod;
		
	}
	cout<<(ans+mod)%mod<<'\n';
}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGEx
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    // pre();
 	seive();
    // test(t)
    solve8();
    
    
    
}