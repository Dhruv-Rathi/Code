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
#define test(t) ll t;cin>>t;while(t--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}


void solve()
{
	int n, k;
    cin>>n>>k;
    string s;
    cin>>s;

	string pre[3];
	for(int i=0;i<n;i++){
		if(i%3 == 0) pre[0]+='R';
		else if (i%3 == 1) pre[0]+='G';
		else pre[0]+='B';
	}
	for(int i=0;i<n;i++){
		if(i%3 == 0) pre[1]+='G';
		else if (i%3 == 1) pre[1]+='B';
		else pre[1]+='R';
	}
	for(int i=0;i<n;i++){
		if(i%3 == 0) pre[2]+='B';
		else if (i%3 == 1) pre[2]+='R';
		else pre[2]+='G';
	}
	int ans = 1e18;
    for(int i=0; i<3; i++){
        int dp[n+1];
        for(int j=0; j<n; j++){
            if(pre[i][j]!=s[j]){
                dp[j] = 1;
            }
            else{
                dp[j] = 0;
            }
        }
        for(int j=1; j<n; j++){
            dp[j] += dp[j-1];
        }
        ans = min(ans, dp[k-1]);
        for(int j=k; j<n; j++){
            ans = min(ans, dp[j] - dp[j-k]);
        }
    }

    cout<<ans<<endl;
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