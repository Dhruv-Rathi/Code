#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define F first
#define S second

const ll mod = 1e9+7;

const int N = 1e5+10;
const int K = 4;

void solve1(){
    vector<pair<int,int>> a;
    int n;
    cin>>n;
    a.assign(n,{0,0});
    for(int i=0;i<n;i++){
        cin>>a[i].S;
    }
    for(int i=0;i<n;i++){
        cin>>a[i].F;
    }
    sort(a.begin(), a.end());
    vector<int> ht;
    for(auto itr: a){
        int cur = itr.S;
        auto it = lower_bound(ht.begin(), ht.end(), cur);
        if(it == ht.end()){
            ht.push_back(cur);
        }
        else{
            *it = cur;
        }
    }
    cout<<ht.size()<<'\n';
}


ll power(ll a, ll b){
    ll p = 1;
    while(b>0){
        if(b&1) p = ((p%mod)*(a%mod))%mod;
        a = ((a%mod)*(a%mod))%mod;
        b/=2;
    }
    return p;
}

ll add(ll x, ll y){
    x+=y;
    while(x>=mod) x-=mod;
    while(x<0) x+=mod;
    return x;
}

ll mul(ll x, ll y){
    return (x*y)%mod;
}

ll n; 
string s; 
ll dp[N][K][K];
ll po3[N];

void solve(){
	cin>>n;
    cin>>s;
    ll cntQ = 0;
    for(auto c: s){
        if(c == '?')
            cntQ++;
    }
    dp[0][0][0] = 1;
    for(ll i=0;i<n;i++){
        for(ll j=0; j<=3;j++){
            for(ll k=0;k<=3;k++){
                if(!dp[i][j][k]) continue;
                dp[i+1][j][k] = add(dp[i+1][j][k], dp[i][j][k]);
                if(j<3 && (s[i] == '?' || s[i]-'a' == j)){
                    ll nk = (s[i] == '?'? k+1: k);
                    dp[i+1][j+1][nk] = add(dp[i+1][j+1][nk], dp[i][j][k]);
                }
            }
        }
    }

    ll ans = 0;
    for(int i=0;i<=3;i++){
        if(cntQ>=i){
            ans = add(ans, mul(dp[n][3][i], po3[cntQ-i]));
        }
    }
    cout<<ans<<'\n';
}

signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    po3[0] = 1;
    for(ll i=1;i<N;i++){
        po3[i] = mul(po3[i-1], 3);
    }
 
    ll tc = 1;
    cin>>tc;
    for(int i=1;i<=tc;i++){
    //	cout<<"Case #"<<i<<": ";
    	solve1();
    }
    
}
