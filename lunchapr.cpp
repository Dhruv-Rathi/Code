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

// Driver function to sort the vector elements
// by second element of pairs
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

void solve()
{
	ll n, ans = 0, cnt = 0, cnt1 = 0; cin>>n;
	ll a[n];
	f(i,0,n) cin>>a[i];
	f(i,0,n) {
		if(a[i] == 1){
			ans+=(n-1);
			ans-=cnt1;
			cnt1++;
		}
		if(a[i] == 2){
			cnt++;
		}
	}
	if(cnt) {
		ans+=(cnt-1)*cnt/2;
	}

	cout<<ans<<'\n';	
}

void solve2(){
	ll n,m,l; cin>>n>>m>>l;
	ll x = l+n-1;
	for(ll i = n;i>0;i--){
		ll y = m/x;
		
		m = m - y*x;
		if(m == 0)
		    break; 
		if(y == 0){
		    i-=x-m-1;
		    x = m;
		    continue;
		}
		x--;
	}
	cout<<m<<'\n';
}

void solve3(){
	ll x,c; cin>>x>>c;
	if(c == 1) cout<<1, return;

}
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    test(t)
    solve();
    
    
    
}