#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define vi vector<ll>
#define vvi vector<vi>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define ss second
#define ff first
#define all(arr) arr.begin(), arr.end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test(t) ll t;cin>>t;while(t--)
 
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}

void solve()
{
	ll x,y;
	cin>>x>>y;
	if(y<=x)
	{
		cout<<(x-y)<<'\n';return;
	}
	ll z = y-x;
	if(z%2)
	{
		cout<<(z/2 +2)<<'\n';
	}
	else
		cout<<(z/2)<<'\n';
}

ll lcm(ll x, ll y)
{
	return ((x*y)/__gcd(x,y));
}

void solve2()
{
	ll x,k;
	cin>>x>>k;
	ll m1,m2;
	m1 = 2*x;
	m2 = lcm(x*k,x*k-1);
	

	cout<<m1<<' '<<m2<<'\n';
}
 
void solve3()
{
	ll n,k;
	cin>>n>>k;
	ll ans = (n-k)*2 + ((k-1)/2)*2;
	cout<<ans<<'\n';


}

vi a;

void solve4(){
	ll n; cin>>n;
	a.resize(n);
	rep(i,0,n) cin>>a[i];
	sort(a.begin(), a.end());
	if(n == 2){
		cout<<0<<'\n';
		return;
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
    solve4();
    
    
    
}