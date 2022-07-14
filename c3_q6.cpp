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
	ll n,k; cin>>n>>k;
	string s,c;
	cin>>s; cin>>c;
	ll ans = 0, cnt=0;
	ll j = 0;
	for(ll i=0;i<n;i++){
		if(c[s[i]-'a'] == '0') cnt++;
		if(cnt>k){
			ans = max(ans, i-j+1);
			while(c[s[j]-'a']!='0' && j<n){
				j++;
			}
			if(j == n) break;
			
		}
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
    solve();
    
    
    
}