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
#define frev(x,a,b) for(int x=a;x>=b;x--)
#define PB push_back
#define MP make_pair
#define S second
#define F first
#define all(a) (a).begin(), (a).end()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define yesorno(x) cout<<((x)?"YES":"NO")<<"\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <class T> ostream &operator<<(ostream &os, const vector<T> a){ for (auto ele : a) os << ele << " "; return os;} 
template <class T> istream &operator>>(istream &is, vector<T> &a){ for (auto &ele : a) is >> ele; return is; }

// ll rec(ll n, ll k){
// 	if(n == 1) return 1;
// 	return ((rec(n-1,k)+k-1)%n+1);
// }


// void solve(){
// 	ll n,k; cin>>n>>k;
// 	cout<<rec(n,k);
// }


// string s1, s2; 
// int dp[41][41][41];

// int rec(int l1, int l2, int kl){
//     if(kl == 1){
//         return (s1[l1] == s2[l2]);
//     }
//     if(dp[l1][l2][kl] != -1) return dp[l1][l2][kl];
//     int ans = 0;
//     for(int i=1;i<kl;i++){
//         ans|=(rec(l1,l2,i)&(rec(l1+i,l2+i,kl-i)));
//         if(ans) break;
//         ans|=(rec(l1,l2+kl-i,i)&rec(l1+i,l2,kl-i));
//         if(ans) break;
//     }
//     return dp[l1][l2][kl] = ans;
// }

// void solve(){
//     cin>>s1>>s2;
//     if(s1 == s2){
//         yes; return;
//     }
//     memset(dp,-1,sizeof(dp));
//     if(rec(0,0,s1.length())){
//         yes;
//     }else{
//         no;
//     }
// }

// void solve2(){
//     int n; cin>>n;
//     int a[n];
//     bool f = 0;
//     f(i,0,n){
//         cin>>a[i];
//         if(a[i] == 0) f = 1;
//     }
//     if(f){
//         cout<<-1<<'\n'; return;
//     }
//     ll cnt2 = 0, cnt5 = 0;
//     ll c = 0;
//     f(i,0,n){
//         int x = a[i]; 
//         while(x%2 == 0 && x>1) {x/=2; cnt2++; }
//         while(x%5 == 0 && x>1) {x/=5; cnt5++; }
//     }
//     if(cnt2>cnt5){
//         cnt2=cnt5; 
//     }else{
//         cnt5=cnt2; 
//     }
//     f(i,0,n){
//         while((a[i]%2 == 0) && cnt2>0) {a[i]/=2; cnt2--;}
//         while((a[i]%5 == 0) && cnt5>0) {a[i]/=5; cnt5--;}
//         a[i] %= 10;
//     }

//     int p=1;
//     f(i,0,n){
//         p = p*a[i];
//     }
//     cout<<p%10<<'\n';

// }

// void BLAWHI(){
//     ll n,m; cin>>n>>m;
//     ll tot = (n*m)%mod;
//     tot = (tot*(tot-1))%mod;
//     ll att = max(0LL, n-1)*max(0LL, m-2)*4 % mod;
//     (att += max(0LL, n-2)*max(0LL, m-1)*4 % mod)%=mod;
//     cout<<(tot-att+mod)%mod<<'\n';
// }

// void awesome(){
//     string s; cin>>s;
//     int n = s.length();
//     map<int, int> mp;
//     mp[0] = -1;
//     int ans = 0, mask = 0;
//     for(int i=0;i<n;i++){
//         mask^=(1<<(s[i]-'0'));
//         if(mp.find(mask)!=mp.end()) ans = max(ans, i-mp[mask]);
//         for(int j=0;j<=9;j++){
//             mask^=(1<<j);
//             if(mp.find(mask)!=mp.end()) ans = max(ans, i-mp[mask]);
//             mask^=(1<<j);
//         }
//         if(mp.find(mask)!=mp.end()){
//             mp[mask] = min(mp[mask],i);
//         }else{
//             mp[mask] = i;
//         }
//         cout<<i<<' '<<ans<<'\n';
//     }
//     cout<<ans<<'\n';
// }

// string s; int n;
// vector<ll> dp;

// ll rec(int i){
//     if(dp[i]!=-1) return dp[i];
//     if(i == n-1) {
//         if(s[i] == '0')
//             return dp[i] =  0;
//         else return dp[i] = 1;
//     }
//     if(s[i] == '0'){
//         return dp[i] = 0;
//     }
//     ll ans = 0;
//     ans = (ans+rec(i+1))%mod;

//     ll x = s[i]-'0';
//     x*=10;
//     x = x+(s[i+1]-'0');
//     if(x>=1 && x<=26) {
//         if(i == n-2)
//             ans = (ans+1)%mod;
//         else ans = (ans+rec(i+2))%mod;
//     }
    
//     return dp[i]=ans;
// }

// void Message_Decode(){
//     cin>>s;
//     // cout<<s<<'\n';
//     n = s.length();
//     dp.resize(n);
//     for(int i=0;i<n;i++) dp[i] = -1;
//     cout<<rec(0)<<'\n';
// }

// void KSUM(){
//     ll n,k; cin>>n>>k;
//     ll a[n];
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     ll pre[n]; pre[0] = a[0]%k;
//     pre[0] = (pre[0]+k)%k;
//     for(int i=1;i<n;i++){
//         pre[i] = (pre[i-1]+a[i])%k;
//         pre[i] = (pre[i]+k)%k;
//     }
//     ll arr[k][2];
//     for(int i=0;i<k;i++){
//         arr[i][0] = arr[i][1] = -1;
//     }
    
//     for(int i=0;i<n;i++) {
//         // cout<<pre[i]<<' ';
//         if(arr[pre[i]][0] == -1  && (pre[i])){
//             arr[pre[i]][0] = arr[pre[i]][1] = i;
//         }else{
//             arr[pre[i]][1] = i;
//         }
//     }
    
//     ll ans = 0;
//     for(int i=0;i<k;i++){
//         ans = max(ans, arr[i][1]-arr[i][0]);
//     }
//     cout<<ans<<'\n';
// }


// ll dp[5005][5005];

// ll rec(int n, int k){
//  if(n<k) return 0;
//  if(n == 0) return 1;
//  if(k == 1) return 1;
//  if(n<0 || k==0) return 0;
//  if(dp[n][k]!=-1) return dp[n][k];
//  ll ans = 0;
//  if(n && k) ans = rec(n-1, k-1)%mod;
//  ans = (ans+rec(n-k, k))%mod;

//  return dp[n][k] = ans;
// }


// void solve(){
//  memset(dp,-1,sizeof(dp));
//  int t; cin>>t; while(t--){
//      int n, k; cin>>n>>k;
//      if(k>n){
//          cout<<"0\n"; continue;
//      }
//      cout<<rec(n,k)<<'\n';
//  }

// }

// ll dp[202][202];
// int nums[210];

// ll rec(int i, int j){
//     if(i>j) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];

//     ll ans = 0;
//     for(int k = i+1;k<j;k++){
//         ans = max(ans, rec(i,k)+rec(k,j)+nums[k]*nums[i]*nums[j]);
//     }
//     return dp[i][j] = ans;
// }


// void Bubbles(){
//     memset(dp,-1,sizeof(dp));

//     int n; cin>>n;

//     nums[0] = nums[n+1] = 1;
//     for(int i=1;i<=n;i++) cin>>nums[i];
//     cout<<rec(0,n+1)<<'\n';
// }   

ll n,d;
vll h; 
map<ll,ll> co;

pll seg[400400];
#define mid (l+r)/2
pll combine(pll &l, pll &r){
    if(l.F>r.F) return l;
    return r;
}
void update(int id, int l, int r, int x, pll val){
    if(l == r) {
        if(val.F>seg[id].F) seg[id] = val;
        return;
    }
    if(x<=mid) update(2*id, l, mid, x, val);
    else update(2*id+1, mid+1, r, x, val);
    seg[id] = combine(seg[2*id], seg[2*id+1]);
}

pii query(int id, int l, int r, int lq, int rq){
    if(r<lq || l>rq) return {-1,-1};
    if(l>=lq && r<=rq){
        return seg[id];
    }
    pll x = query(2*id,l,mid,lq,rq);
    pll y = query(2*id+1,mid+1,r,lq,rq);
    return combine(x, y);
}
#undef mid
void coordinateCompression(){
    for(auto &x: h) co[x];
    int new_name = 0;
    for(auto &x: co) x.S = new_name++;
}

void solve(){
    
    cin>>n>>d;
    h.assign(n,0);

    f(i,0,n) cin>>h[i];
    coordinateCompression();
    vector<ll> dp(n,1), back(n,-1);

    f(i,0,n){
        ll left = h[i]-d, right = h[i]+d;
        {
            auto it = co.upper_bound(left);
            if(it!=co.begin()){
                it--;
                left = it->S;
                pll val = query(1,0,n-1,0,left);
                if(1+val.F > dp[i]){
                    dp[i] = 1+val.F;
                    back[i] = val.S;
                }
            }
        }
        {
            auto it = co.lower_bound(right);
            if(it!=co.end()){
                right = it->S;
                pll val = query(1,0,n-1,right,n-1);
                if(1+val.F > dp[i]){
                    dp[i] = 1+val.F;
                    back[i] = val.S;
                }
            }
        }
        update(1,0,n-1,co[h[i]],{dp[i],i});
    }
    int bestAns = 0;
    f(i,0,n){
        if(dp[i]>dp[bestAns]) bestAns = i;
    }

    vll ans;
    for(int i=bestAns; i!=-1; i = back[i]){
        ans.PB(i+1);
    }
    reverse(all(ans));
    cout<<dp[bestAns]<<'\n';
    for(auto &x: ans) cout<<x<<' ';

}
 
signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    ll tc = 1;
    // cin>>tc;
    for(int i=1;i<=tc;i++){
    //	cout<<"Case #"<<i<<": ";
    	solve();
    }
    
}