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

int ans[(1<<16)+1];

void solve()
{
	int n; cin>>n;
	f(i,0,n){
		int x; cin>>x;
		cout<<ans[x]<<' ';
	}
}
 
signed main()
{
    fast

    ans[32768] = 0;
    for(int i=32767;i>=0;i--){
    	int cnt = 0;
    	int x = i;
    	while(x%32768) x = (2*x)%32768,cnt++;
    	ans[i] = cnt;
    	ans[i] = min(ans[i], 1+ans[i+1]);
    }

 
    // test(t)
    solve();
    
    
    
}