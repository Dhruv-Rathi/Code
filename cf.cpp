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

void solve()
{
	int n; cin>>n;
	if(n==1){
		cout<<"1\n";return;
	}
	// ll a[n];
	// SieveOfEratosthenes(n);
	for(int i=1;i<=n;i++){
		cout<<(i+1)<<' ';
	}
	cout<<'\n';

}

void solve2(){
	ll n, a, b; cin>>n>>a>>b;
	vii arr;
	int l = 1, r = n;

	if(abs(a-b)>1 || (a+b)>(n-2)) {
		cout<<-1<<'\n';
		return;
	}

	if(a==b){
		int h = 0, v = 0;
		arr.pb(l);
		l++;
		while(h<a){
			arr.pb(r);
			r--;
			arr.pb(l);
			l++;
			h++;
		}

		f(i,l,r+1){
			arr.pb(i);
		}
	}
	else if(a>b){
		int h = 0;
		arr.pb(l);
		l++;
		while(h<a-1){
			arr.pb(r); r--;
			arr.pb(l); l++;
			h++;
		}
		for(int i=r; i>=l;i--){
			arr.pb(i);
		}
	}
		else{
			arr.pb(r);
			r--;
			int v = 0;
			while(v<b-1){
				arr.pb(l); l++;
				arr.pb(r); r--;
				v++;
			}
			f(i,l,r+1){
				arr.pb(i);
			}
		}
		cout<<arr<<'\n';
	
}
void solve3(){
	ll n; cin>>n;
	ll a[n], b[n];
	f(i,0,n) cin>>a[i];
	f(i,0,n) cin>>b[i];

	ll pos1=0, pos2=0;
	f(i,1,n){
		if(a[i]>a[pos1])
		{
			pos1 = i;
		}
		if(b[i]>b[pos2]){
			pos2 = i;
		}
	}
	// cout<<pos1<<' '<<pos2<<'\n';
	string ans="";
	f(i,0,n){
		ll f = 1;
		if(i!=pos1 || i!= pos2){
			if(b[i]<b[pos1] && a[i]<a[pos2])
				f = 0;
		}
		if(f) ans= ans + '1';
		else ans= ans + '0';
	}
	vector<int> first ;
	f(i,0,n){
		if(ans[i] == '0'){
			first.pb(i);
		}
	}
	f(i,first[0],n){
		if(ans[i]=='0'){
			f(j,0,n){
				if(i!=j && ans[j]=='1'){
					if(a[i]>a[j] || b[i]>b[j]) {
						ans[i] = '1';
						// i=first;
					}
				}
			}
		}
	}
	
	cout<<ans<<'\n';
} 

void solve31(){
	ll n; cin>>n;
	// ll a[n], b[n];
	vector<pair<ll, ll>> a(n), b(n);
	f(i,0,n) {
		cin>>a[i].F;
		a[i].S = i;

	}
	f(i,0,n) {
		cin>>b[i].F;
		b[i].S = i;
	}
	if(n==1){
		cout<<"1\n";return;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vector<ll> pa(n), pb(n);
	f(i,0,n){
		pa[a[i].S] = i;
		pb[b[i].S] = i;
	} 
	vector<ll> pmxa(n), pmxb(n), smxb(n);
	pmxa[0] = pa[b[0].S];
	pmxb[0] = pb[a[0].S];
	smxb[n-1] = pb[a[n-1].S];
	// for(ll i)

}

void solve4(){
	ll n,x; cin>>n>>x;
	vll a(n);
	f(i,0,n){
		cin>>a[i];
	}
	ll ans = 1e18;
	ll cur = 0;
	f(i,0,n-1){
		cur+=abs(a[i]-a[i+1]);
	}

	f(i,0,2){
		ll mn = abs(a[0]-1);
		ans = min(ans, cur+abs(a[0]-x)+(x-1));
		f(i,0,n-1){
			ans = min(ans, cur+mn-abs(a[i]-a[i+1])+abs(a[i]-x)+abs(a[i+1]-x));
			ans = min(ans, cur-abs(a[i]-a[i+1])+abs(a[i]-x)+abs(a[i+1]-1)+(x-1));
			mn = min(mn, 0LL-abs(a[i]-a[i+1])+abs(a[i]-1)+abs(a[i+1]-1));
		}
		ans = min(ans, cur+mn+abs(a.back()-x));
		reverse(all(a));
	}
	cout<<ans<<'\n';
}

void solve4cool(){
	ll n,x; cin>>n>>x;
	vll a(n);
	ll ma = 0, mi = 1e18;
	f(i,0,n){
		cin>>a[i];
		ma = max(ma, a[i]);
		mi = min(mi, a[i]);
	}

	ll ans = 0;
	f(i,0,n-1){
		ans+=abs(a[i]-a[i+1]);
	}

	if(x>ma){
		ans+=min((x-ma)*2,min(x-a[n-1],x-a[0]));
	}
	ans+=min((mi-1)*2,min(a[n-1]-1,a[0]-1));

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
    solve4cool();
    
    
    
}