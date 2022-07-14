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

ll dp[2001][2001];
vector<ll> d[2001];
ll prefix[2001][2001];

ll rec(ll k, ll n){
   if(k==1) return 1;
   if(dp[k][n] != -1)
       return dp[k][n];
   ll ans=0;
   for(ll i:d[n]){
       ans = (ans + rec(k-1, i))%mod;
   }
   return dp[k][n]=ans;
}

signed main() {
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
   #endif
	
   for(ll i=1; i<=2000; ++i){
       for(ll j=i; j<=2000; j+=i){
           d[j].push_back(i);
       }
   }
   memset(dp,-1,sizeof(dp));
   for(int i=1;i<=2000;i++){
       for(int j=1;j<=2000;j++){
           dp[i][j] = rec(i,j);
           prefix[i][j] = prefix[i][j-1]+dp[i][j];
           prefix[i][j]%=mod;
       }
   }
   ll t;
   cin>>t;
   while(t--){
       ll n,k;
       cin>>n>>k;
       cout<<prefix[k][n]<<"\n";
   }
   return 0;
}