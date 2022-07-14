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
#define S second
#define F first
#define all(a) a.begin(), a.end()
#define vecpii vector<pair<int,int>>
#define test(t) int tc; cin>>tc; while(tc--)
using ii = pair<int,int> ;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}


int n;
int arr[2020];
ii merge(ii cur, ii val){
	if(val.F>cur.F){
		return val;
	}else if(val.F == cur.F){
		cur.S += val.S;
		return cur;
	}else {
		return cur;
	}
}


// int dp[2020][2020];
ii dp[2022];

ii rec(int i){
	if(dp[i]!=make_pair(-1,-1)) return dp[i];
	ii ans = {1,1};
	for(int j=0;j<i;j++){
		if(arr[j]<arr[i]){
			ans = merge(ans,{dp[j].F+1, dp[j].S});
		}
	}
	return dp[i] = ans;
}

// O(n^2) solution
void solve2(){
	cin>>n;
	ii ans = {-1,0};

	for(int i=0;i<n;i++){
		cin>>arr[i];
		dp[i] = {-1,-1};
	}

	// Iterative code.
	// for(int i=0;i<n;i++){
	// 	dp[i] = {1,1};
	// 	for(int j=0;j<i;j++){
	// 		if(arr[j]<arr[i]){
	// 			dp[i] = merge(dp[i],{dp[j].F+1, dp[j].S});
	// 		}
	// 	}
	// 	ans = merge(ans, dp[i]);
	// }

	for(int i=0;i<n;i++){
		ans = merge(ans, rec(i));
	}

	cout<<ans.F<<' '<<ans.S<<'\n';
}
/*
void solve(){
	int n; cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int longest = 0;
	for(int sz=1;sz<=n;sz++){
		for(int i=0;i<n;i++){
			if(sz==1){
				dp[i][sz] = 1;
			}else{
				dp[i][sz] = 0;
				for(int j=0;j<i;j++){
					if(arr[j]<arr[i]){
						dp[i][sz] += dp[j][sz-1];
					}
				}
				if(dp[i][sz]){
					longest = max(longest,sz);
				}
			}
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		ans+=dp[i][longest];
	}
	cout<<ans<<'\n';
}
 */
signed main()
{
    fast
    
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

 
    // test(t)
    solve2();
    
    
    
}