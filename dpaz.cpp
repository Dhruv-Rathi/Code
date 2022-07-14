#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
int n,m;
int a[220][220];
int dp[220][220];
int dp2[220][220];
int area = 0;

int rec(int i, int j){
	if(i<0 || j<0){
		return 0;
	}
	if(dp[i][j]!=-1) return dp[i][j];

	int width = 0;
	if(a[i][j] == 1){
		width = (j==0)?1:rec(i,j-1)+1;
	}else{
		width = 0;
	}
	return dp[i][j] = width;
}


int rec2(int i, int j){
	if(i<0 || j<0){
		return 0;
	}
	if(dp2[i][j]!=-1) return dp2[i][j];
	
	int ans = 0;
    if(a[i][j]){
        int w = rec(i,j);
        for(int k=i;k>=0;k--){
            w = min(w,rec(k,j));
            ans = max(ans, w*(i-k+1));
        }
    }
	
	return dp2[i][j] = ans;
}

void solve(){
	area = 0;
	// memset(dp,-1,sizeof(dp));
	// memset(dp2,-1,sizeof(dp2));
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
            dp[i][j] = -1;
            dp2[i][j] = -1;
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			area = max(area, rec2(i,j));
		}
	}
	cout<<area<<'\n';

}

signed main(){
	fast
	 #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	int t; cin>>t; while(t--)
		solve();

	return 0;
}