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


string s;ll n, dp[100100];

ll rec(ll level){
    if(level <= 0){
        return 0;
    }
    if(dp[level] != -1) return dp[level];
    ll ans = 0;
    if(s[level] == ')'){
        if(level>0){
            if(s[level-1] == '('){
                ans = 2+rec(level-2);
            }

            else {
                ll x = rec(level-1);
                if(x>0 && level-x-1>=0 && (s[level-x-1]=='(')){
                    ans = ans+x+2+rec(level-x-2);
                    
                }
            }
        }
    }
    return dp[level] = ans;
}

void solve()
{
	cin>>s;
    n = s.length();
    for(ll i=0;i<n;i++) dp[i] = -1;
    ll ans = 0;
    for(ll i=0;i<n;i++){
        ans = max(ans, rec(i));
    }
    ll cnt=0;
    for(ll i=0;i<s.length();i++){
        if(rec(i) == ans) cnt++;
    }

    if(ans){
        cout<<ans<<' '<<cnt<<'\n';
    }
    else{
        cout<<0<<' '<<1<<'\n';
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