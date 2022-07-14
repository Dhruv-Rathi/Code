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
int n,k;
int dp[301][301][301];
int rec(int i, int j, int m){
	if(j>k) return 0;
	if(i == n){
		if(j == k) return 1;
		else return 0;
	}
	ll ans
}
void solve()
{
	cin>>n>>k;
	vecpii v(n);
	f(i,0,n){
		cin>>v[i].ff;
	}
	f(i,0,n) cin>>v[i].ss;
	sort(all(v));
	f(i,0,n){
		cout<<v[i].ff<<' '<<v[i].ss<<'\n';
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
    solve();
    
    
    
}