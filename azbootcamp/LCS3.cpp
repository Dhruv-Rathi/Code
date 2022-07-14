#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


// string s1, s2;
// ll n,m;
// ll dp[1001][1001];

// ll rec(ll i, ll j){
    
//     if(i>=n || j>=m) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];

//     ll ans = 0;
//     if(s1[i] == s2[j]){
//         ans = 1+rec(i+1,j+1);
//     }else{
//         ans = max({ans, rec(i,j+1),rec(i+1,j)});
//     }
//     return dp[i][j] = ans;
// }
// void solve(){
//     memset(dp,-1,sizeof(dp));
//     cin>>s1>>s2;
//     n = s1.length(); m = s2.length();
//     ll ans = 0;
//     for(ll i=0;i<n;i++){
//         for(ll j=0;j<m;j++){
//             ans = max(ans, rec(i,j));
//         }
//     }
//     cout<<ans<<'\n';
// }
 

// string s1,s2,s3;
// int a,b,c;
// int dp[101][101][101];

// int rec(int i, int j, int k){
// 	if(i>=a || j>=b || k>=c){
// 		return 0;
// 	}
// 	if(dp[i][j][k] != -1) return dp[i][j][k];
// 	int ans = 0;
// 	if(s1[i] == s2[j] && s1[i] == s3[k]){
// 		ans = 1+rec(i+1,j+1,k+1);
// 	}
// 	else{
// 		ans = max({rec(i,j+1,k+1), rec(i,j,k+1), rec(i,j+1,k), rec(i+1,j,k),
// 			rec(i+1,j+1,k), rec(i+1,j,k+1)});
// 	}
// 	return dp[i][j][k] = ans;
// }

// void solve(){
// 	memset(dp,-1,sizeof(dp));

// 	cin>>s1>>s2>>s3;
// 	a = s1.length(), b = s2.length(), c = s3.length();
// 	cout<<rec(0,0,0)<<'\n';
// }

string s;
int n;
int dp[1001][1001];

int rec(int i, int j){
	if(i == -1) return n-j;
	if(j == n) return i+1;
	if(dp[i][j]!=-1) return dp[i][j];
	int ans = 1e9;
	if(s[i] == s[j])ans = min(ans, rec(i-1,j+1));
	else{
		ans = min({ans, 1+rec(i-1,j), 1+rec(i,j+1)});
	}
	return dp[i][j] = ans;
}

void solve(){
	
	cin>>s;
	n = s.length();
	memset(dp,-1,sizeof(dp));
	int ans = 1e9;
	for(int i=0;i<n;i++){
		ans = min({ans, rec(i-1,i+1),rec(i-1,i), rec(i,i+1)});
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
 
    ll tc = 1;
    cin>>tc;
    for(int i=1;i<=tc;i++){
    //	cout<<"Case #"<<i<<": ";
    	solve();
    }
    
}