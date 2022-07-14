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
	int t; cin>>t; 
	for(int i=1;i<=(t); i++){
		string a; cin>>a;
		int a1[26]={0};
		for(int j=0;j<26;j++){
			a1[a[j]-'a'] = j;
		}
		string s; cin>>s;
		ll ans=0;
		for(int j=1;j<s.length();j++){
			ans+=abs(a1[s[j]-'a']-a1[s[j-1]-'a']);
		}
		cout<<ans<<'\n';

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