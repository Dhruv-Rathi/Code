#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll mod = 1e9+7;


int m, d;
string a, b;

ll dp[2010][2][2][2010];

ll rec(int level, int tlo, int thi, int sum){
    if(level == a.length()){
        if(sum == 0){
            return 1;
        }
        return 0;
    }
    ll &ans = dp[level][tlo][thi][sum];
    if(ans!=-1) return ans;

    int lo = 0, hi = 9;
    if(tlo == 1){
        lo = a[level]-'0';
    }
    if(thi == 1){
        hi = b[level]-'0';
    }
    ans = 0;

    for(int i=lo;i<=hi;i++){
        int ntlo=0, nthi=0;
        if(tlo == 1 && i == lo){
            ntlo = 1;
        }
        if(thi == 1 && i == hi){
            nthi = 1;
        }
        if(level%2 && i == d){
            ans += rec(level+1, ntlo, nthi, (sum*10+i)%m);
        }else if(level%2 == 0 && i!=d){
            ans += rec(level+1, ntlo, nthi, (sum*10+i)%m);
        }
        ans %= mod;
    }
    return ans;
}

void solve(){
    cin>>m>>d;
    cin>>a>>b;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,1,1,0)%mod<<'\n';
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