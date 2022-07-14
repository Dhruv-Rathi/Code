#include<bits/stdc++.h>
using namespace std;

#define mod 998244353

typedef long long ll;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	ll hh, mm;
	cin>>hh>>mm;
	ll ans = hh*60 - mm*11;

	ans = abs(ans);
	if(ans>=360) ans = 720-ans;

	cout<<ans<<'\n';
}

const int N = 10010;

int dp[101][N];

void solve2(){
    int n;
	cin>>n;
    int a[n], b[n];
	memset(dp,0,sizeof(dp));

	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int i=min(a[0],b[0]);i<=max(a[0],b[0]);i++){
		dp[0][i] = 1;
	}
	for(int i=1;i<N;i++){
		dp[0][i] = (dp[0][i]+dp[0][i-1])%mod;
        dp[0][i] = (dp[0][i]+mod)%mod;
        
	}
	for(int i=1;i<n;i++){
		for(int j = min(a[i],b[i]);j<=max(a[i],b[i]); j++){
			dp[i][j] = dp[i-1][j-1];
		}
		for(int j=1;j<N;j++){
			dp[i][j] = (dp[i][j]+dp[i][j-1])%mod;
            dp[i][j] = (dp[i][j]+mod)%mod;
		}
	}
	int ans = dp[n-1][N-1];
    ans = (ans+mod)%mod;
	cout<<ans<<'\n';
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
    	solve2();
    }
    
}