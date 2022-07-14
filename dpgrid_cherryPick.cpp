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

int n,m;
int arr[50][50];
// int dp[50][50][50][50];

bool check(int x, int y){
	if(x>=n || y>=m) return 0;
	return 1;
}

int rec(int r1, int c1, int r2, int c2){  // r1+c1 == r2+c2
	// int c2 = (r1+c1)-(r2);  This is state space reduction. we can use dp[r1][c1][r2] here
	if(!check(r1,c1) || !check(r2,c2)){
		return -1e9;
	}
	if(r1==n-1 && c1==n-1 && r2==n-1 && c2==n-1){
		return arr[r1][c1];
	}
	if(dp[r1][c1][r2][c2]!=-1) return dp[r1][c1][r2][c2];
	int ans = ((r1==r2 && c1==c2) ? arr[r1][c1]: arr[r1][c1]+arr[r2][c2]);
	ans = ans + max({rec(r1+1,c1,r2+1,c2), rec(r1,c1+1,r2+1,c2), rec(r1+1,c1,r2,c2+1), rec(r1,c1+1,r2,c2+1)});
	return dp[r1][c1][r2][c2] = ans;
}

// For k persons.
int k;
map<pair<int,int>, int> mp;
int rec(vector<int> rowVal, int c0){
	int totRow = 0, totCol = 0;
	vector<int> colVal;
	for(int i=0;i<k;i++){
		colVal.pb(rowVal[0]+c0-rowVal[i]);
		if(!check(rowVal[i], colVal[i]))
			return -1e9;
		totRow+=rowVal[i]; totCol+=colVal[i];
	}

	if(totRow==k*(n-1) && totCol==k*(m-1)) return arr[n-1][m-1];

	if(mp.find(make_pair(rowVal, c0)) != mp.end()){
		return mp[make_pair(rowVal, c0)];
	}

	int ans = -1e9;
	int temp=0;
	set<pair<int, int>> st;
	for(int i=0;i<k;i++){
		st.insert({rowVal[i], colVal[i]});
	}
	for(auto v: st){
		temp+=arr[v.first][v.second];
	}
	for(int mask=0; mask<(1<<k); mask++){
		vector<int> rNew = rowVal;
		int c0new = c0;
		for(int i=0;i<k;i++){
			if(mask&(1<<i)){
				rNew[i]++;
			}else{
				if(i==0) c0new++;
			}
		}
		ans = max(ans, temp+rec(rNew, c=New));
	}

	return mp[make_pair(rowVal, c0)] = ans;

}

void solve()
{
	
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