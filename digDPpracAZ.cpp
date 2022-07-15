#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll mod = 1e9+7;


// int m, d;
// string a, b;

// ll dp[2010][2][2][2010];

// ll rec(int level, int tlo, int thi, int sum){
//     if(level == a.length()){
//         if(sum == 0){
//             return 1;
//         }
//         return 0;
//     }
//     ll &ans = dp[level][tlo][thi][sum];
//     if(ans!=-1) return ans;

//     int lo = 0, hi = 9;
//     if(tlo == 1){
//         lo = a[level]-'0';
//     }
//     if(thi == 1){
//         hi = b[level]-'0';
//     }
//     ans = 0;

//     for(int i=lo;i<=hi;i++){
//         int ntlo=0, nthi=0;
//         if(tlo == 1 && i == lo){
//             ntlo = 1;
//         }
//         if(thi == 1 && i == hi){
//             nthi = 1;
//         }
//         if(level%2 && i == d){
//             ans += rec(level+1, ntlo, nthi, (sum*10+i)%m);
//         }else if(level%2 == 0 && i!=d){
//             ans += rec(level+1, ntlo, nthi, (sum*10+i)%m);
//         }
//         ans %= mod;
//     }
//     return ans;
// }

// void solve(){
//     cin>>m>>d;
//     cin>>a>>b;
//     memset(dp,-1,sizeof(dp));
//     cout<<rec(0,1,1,0)%mod<<'\n';
// }

string L, R;
int len;

ll dp[11][2][2][51][51];

bool check(int x){
    if(x<2) return 0;
    for(int i=2;i<=sqrt(x);i++){
        if(x%i == 0) return 0;
    }
    return 1;
}

ll rec(int l, int tlo, int thi, int sum1, int sum2){
    if(l == len){
        if(l%2){
            if(check(sum2-sum1))
                return 1;
        }
        else{
            if(check(sum1-sum2))
                return 1;
        }
        return 0;
    }
    ll &ans = dp[l][tlo][thi][sum1][sum2];
    if(ans!=-1) return ans;
    ans = 0; int lo = 0, hi = 9;
    if(tlo) lo = L[l]-'0';
    if(thi) hi = R[l]-'0';
    for(int i=lo;i<=hi;i++){
        int ntlo = tlo;
        if(i!=L[l]-'0') ntlo = 0;
        int nthi = thi;
        if(i!=R[l]-'0') nthi = 0;
        if(l%2){
            ans += rec(l+1, ntlo, nthi, sum1, sum2+i);
        }else{
            ans += rec(l+1, ntlo, nthi, sum1+i, sum2);
        }
    }
    return ans;

}

void solve(){
    cin>>L>>R;
    int cnt = R.length() - L.length();
    string t = "";
    while(cnt--) t+='0';
    L = t+L;
    len = R.length();
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,1,1,0,0)<<'\n';
}

signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    ll tc = 1;
    cin>>tc;
    for(int i=1;i<=tc;i++){
    //	cout<<"Case #"<<i<<": ";
    	solve();
    }
    
}