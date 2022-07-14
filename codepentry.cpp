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


void solve(){
	string s; cin>>s;
	int a[26] = {0};
	f(i,0,s.length()){
		a[s[i]-'a']++;
	}
	f(i,0,26){
		if(a[i] == 0){
			cout<<(char)('a'+i)<<'\n'; return;
		}
	}
	cout<<-1<<'\n';
}

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);   
}

void solve2(){
	ll n; cin>>n;
	ll x; cin>>x;
	ll g = x;
	for(ll i=1;i<n;i++){
		ll x; cin>>x;
		g = gcd(g,x);
	}
	// cout<<g<<'\n';
	if(g == 1){
		cout<<-1<<'\n'; return;
	}
	if(g%2 == 0){
		cout<<2<<' ';
		while(g%2 == 0){
			g/=2;
		}
	}
	for(ll i=3;i*i<=g;i+=2){
		if(g%i == 0){
			cout<<i<<' ';
			while(g%i==0){
				g/=i;
			}
		}
	}

	if(g>2){
		cout<<g<<' ';
	}
	cout<<'\n';
}

void solve3(){
	int n,m; cin>>n>>m;
	char arr[n][m+2];
	f(i,0,n){
		f(j,0,m+2){
			cin>>arr[n-i-1][j];
		}
	}


	int dp[n][2];
	f(i,0,n){
		dp[i][0] = dp[i][1] = 0;
	}
	int j = 0;
	f(i,1,m+1){
		if(arr[0][i] == '1')
			j = i;
	}
	if(n == 1){
		cout<<j<<'\n'; return;
	}
	dp[0][0] = 2*j;
	dp[0][1] = m+1;
	// cout<<dp[0][0]<<' '<<dp[0][1]<<'\n';
	f(i,1,n-1){
		bool f = 1;
		if(dp[i-1][0]+1<(dp[i-1][1]+m+2)){
			dp[i][0] = dp[i-1][0]+1;
		}else{
			dp[i][0] = dp[i-1][1]+m+2;
			f = 0;
		}
		if(f){
			j = 0;
			for(int k=1;k<=m;k++){
				if(arr[i][k] == '1'){
					j=k;
				}
			}

			dp[i][0] += 2*j ;
		}

		f = 1;
		if(dp[i-1][1]+1<(dp[i-1][0]+m+2)){
			dp[i][1] = dp[i-1][1]+1;
		}else{
			dp[i][1] = dp[i-1][0]+m+2;
			f = 0;
		}
		if(f){
			j=m+1; 
			for(int k=m;k>=1;k--){
				
				if(arr[i][k] == '1'){
					j = k;
				}
			}
			
			dp[i][1] += 2*(m+1-j);
		}
		cout<<dp[i][0]<<' '<<dp[i][1]<<'\n';
	}
	dp[n-1][0] = 1+dp[n-2][0];
	dp[n-1][1] = 1+dp[n-2][1];
	j=0;
	// cout<<dp[n-1][0]<<' '<<dp[n-1][1]<<' ';
	f(i,1,m+1){
		if(arr[n-1][i] == '1'){
			j = i;
		}
	}
	dp[n-1][0] += j;
	j = m+1;
	for(int i=m;i>=1;i--){
		if(arr[n-1][i] == '1'){
			j=i;
		}
	}
	
	dp[n-1][1]+=(m+1-j);
	
	// cout<<dp[n-1][0]<<' '<<dp[n-1][1]<<' ';
	cout<<min(dp[n-1][0], dp[n-1][1])<<'\n';
}

void solve31(){
	int n,m; cin>>n>>m;
	char arr[n][m+2];
	f(i,0,n){
		f(j,0,m+2){
			cin>>arr[i][j];
		}
	}


	int dp[n][2];
	
	memset(dp, 0, sizeof(dp));

	int mi = -1, ma = -1;
	f(i,1,m+1){
		if(arr[0][i]=='1'){
			if(mi == -1){
				mi = i;
			}
			ma = i;
		}
	}
	if(ma!=-1){
		dp[0][0] = ma;
	}
	if(mi!=-1){
		dp[0][1] = (m-mi+1);
	}

	for(int i=1;i<n;i++){
		mi = -1, ma = -1;
		for(int j=1;j<=m;j++){
			if(arr[i][j]=='1'){
				if(mi == -1){
					mi = j;
				}
				ma = j;
			}
		}
		if(dp[i-1][0] == 0){
			dp[i][0] = ma;
		}else if(ma!=-1){
			dp[i][0] = 1+min(2*ma+dp[i-1][0],m+1+dp[i-1][1]);
		}else{
			dp[i][0] = 1+min(dp[i-1][0],m+1+dp[i-1][1]);
		}
		if(dp[i-1][1] == 0){
			dp[i][1] = m-mi+1;
		}else if(mi!=-1){
			dp[i][1] = 1+min(2*(m-mi+1)+dp[i-1][1], m+1+dp[i-1][0]);
		}else{
			dp[i][1] = 1+min(dp[i-1][1], m+1+dp[i-1][0]);
		}
	}
	cout<<dp[n-1][0]<<'\n';
}


signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    test(t)
    solve31();
    
    
    
}