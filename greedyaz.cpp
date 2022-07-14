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
	ll n; cin>>n;
	vll a(n); 
	f(i,0,n) cin>>a[i];
	vll b(n,0);
	ll i=0,pre = 0;
	while(i<n)
	{
		while(a[i+1]<a[i] && (i+1)<n){
			i++;
		}
		ll k = 1;
		for(ll j = i;j>pre;j--){
			b[j] = k++;
		}
		if(pre == 0){
			b[pre] = k;
		}
		else
			b[pre] = max(k,1+b[pre-1]);
		pre = i+1;
		i++;
	}
	
	// cout<<b<<'\n';
	ll ans = 0;
	f(j,0,n){
		ans+=b[j];
	}
	cout<<ans<<'\n';
}

void solve2(){
	ll k; cin>>k;

	vll fib;
	fib.pb(0);
	fib.pb(1);
	ll x, i = 2;
	while(1){
		x = fib[i-1]+fib[i-2];
		if(x>k) break;
		fib.pb(x);
		i++;
	}
	ll ans = 0, j = fib.size()-1;
	while(k){
		ans+=(k/fib[j]);
		k%=(fib[j]);
		j--;
	}

	cout<<ans<<'\n';
}

void solve3(){
	int n; cin>>n;
	ll d[n], l[n];
	f(i,0,n){
		cin>>d[i];
	}
	f(i,0,n){
		cin>>l[i];
	}
	vpll job(n+1);
	f(i,0,n){
		job[i].F = d[i];
		job[i].S = l[i];
	}
	job.pb({0,0});
	sort(all(job));
	reverse(all(job));
	ll ans = 0;
	priority_queue<ll> pq;
	pq.push(-job[0].S);

	f(i,1,n+1){
		ll interval = job[i-1].F-job[i].F;
		while(interval>0 && !pq.empty()){
			ll duration = -pq.top();
			pq.pop();
			ll time = min(interval, duration);
			interval-=time;
			duration-=time;
			if(duration>0) pq.push(-duration);
			else ans++;
		}
		pq.push(-job[i].S);
	}
	cout<<ans<<'\n';
}	

void solve4(){
	ll n; cin>>n;

	vpll v(n);
	f(i,0,n){
		cin>>v[i].F>>v[i].S;
	}

	sort(all(v), sortbysec);
	ll ans = 0, last_point = -1e18;
	for(auto x: v){
		ll left = x.F;
		ll right = x.S;
		if(left>last_point){
			last_point = right;
			ans++;
		}
	}

	cout<<ans<<'\n';
}

signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    test(t)
    solve3();
}