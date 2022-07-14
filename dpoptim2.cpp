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
#define pb push_back
#define mp make_pair
#define S second
#define F first
#define all(a) a.begin(), a.end()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define yesorno(x) cout<<((x)?"YES":"NO")<<"\n"
#define test(t) int tc; cin>>tc; while(tc--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}

deque<int> dq;
void insert(int x){
	while(!dq.empty() && dq.back()>x){
		dq.pop_back();
	}
	dq.push_back(x);
}

void remove(int y){
	if(dq.front()==y) dq.pop();
}

int getMin(){
	return dq.front();
}

void clear(){
	while(!dq.empty()) dq.pop_back();
}

void solve(){
	int n,m,k; cin>>n>>m>>k;
	int arr[n-1], brr[n], dp[2][n];
	for(int i=0;i<n-1;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		cin>>brr[i];
	}
	for(int i=0;i<=m;i++){ // i means number of flights
		dp[i&1][0] = 0;
		clearVal();
		for(int j=1;j<n;j++){ // city number 
			if(i == 0){
				dp[i&1][j] = dp[i&1][j-1]+a[j-1];
			}else{
				dp[i&1][j] = dp[i%2][j-1]+a[j-1];
				insert(dp[(i-1)%2][j-1]+b[j-1]);
				if(j-k-1>=0) remove(dp[(i-1)%2][j-k-1]+b[j-k-1]);
				dp[i%2][j] = min(dp[i%2][j],getMin()+b[j]);
			}
		}
	}
	cout<<dp[m%2][n-1]<<'\n';
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