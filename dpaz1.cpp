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

#define int long long

// int n,m,k;
// int arr[110];
// int p[110][110];
// int dp[110][110][110];

// int rec(int x, int y, int z){
// 	if(y<0){
// 		return 1e18;
// 	}
// 	if(x == n){
// 		if(y == 0)
// 			return 0;
// 		return 1e18;
// 	}
// 	if(dp[x][y][z]!=-1) return dp[x][y][z];
// 	int ans = 1e18;
// 	if(arr[x] == 0){
// 		f(j,0,m){
// 			if(z!=j+1){
// 				ans = min(ans, rec(x+1,y-1,j+1)+p[x][j]);
// 			}else{
// 				ans = min(ans, rec(x+1,y,j+1)+p[x][j]);
// 			}
// 		}
// 	}else{
// 		if(arr[x]!=z){
// 			ans = rec(x+1,y-1,arr[x]);
// 		}else{
// 			ans = rec(x+1,y,arr[x]);
// 		}
// 	}

// 	return dp[x][y][z] = ans;
// }


// void solve(){
// 	cin>>n>>m>>k;
// 	f(i,0,n){
// 		cin>>arr[i];
// 	}
// 	f(i,0,n){
// 		f(j,0,m){
// 			cin>>p[i][j];
// 		}
// 	}
// 	memset(dp,-1,sizeof(dp));
	
// 	int ans = rec(0,k,0);
// 	if(ans >= 1e18){
// 		cout<<-1<<'\n';
// 	}else{
// 		cout<<ans<<'\n';
// 	}

// }




// void solve2(){
// 	int q,n,c;
// 	cin>>n>>q>>c;
// 	vector<pair<pii,int>> star;
// 	f(i,0,n){
// 		int x,y,s;
// 		cin>>x>>y>>s;
// 		star.pb({{x,y},s});
// 	}	
// 	ll dp[101][101][11], bright[101][101][11];
// 	memset(dp,0,sizeof(dp)); memset(bright,0,sizeof(bright));
// 	for(int m=0;m<=c;m++){
// 		for(int k=0;k<n;k++){
// 			bright[star[k].F.F][star[k].F.S][m] += (star[k].S+m)%(c+1);
// 		}
// 	}

// 	f(i,1,101){
// 		f(j,1,101){
// 			f(m,0,c+1){
// 				dp[i][j][m] = bright[i][j][m]+dp[i-1][j][m]+dp[i][j-1][m]-dp[i-1][j-1][m];
// 			}
// 		}
// 	}


// 	for(int i=0;i<q;i++){
// 		ll m,x1,y1,x2,y2;
// 		cin>>m>>x1>>y1>>x2>>y2;
// 		m%=(c+1);
// 		ll ans = dp[x2][y2][m]-dp[x2][y1-1][m]-dp[x1-1][y2][m]+dp[x1-1][y1-1][m];
// 		cout<<ans<<'\n';
// 	}	

// }

// string s;
// int n,k;

// int dp[110][110][26];
// int done[110][110][26];
// int costs[26][26];

// int rec(int l, int kl, int prev){
// 	if(kl<0) return -1e9;
// 	if(l == n){
// 		return 0;
// 	}
// 	if(done[l][kl][prev]) return dp[l][kl][prev];
// 	int ans = -1e9;
// 	f(i,0,26){
// 		if(l == 0){
// 			if(i == s[0]-'a'){
// 				ans = max(ans,rec(l+1,kl,i));
// 			}else{
// 				ans = max(ans, rec(l+1,kl-1,i));
// 			}
// 		}else if(i == (int)(s[l]-'a')){
// 			ans = max(ans, costs[prev][i]+rec(l+1,kl,i));
// 		}else{
// 			ans = max(ans, costs[prev][i]+rec(l+1,kl-1,i));
// 		}
// 	}
// 	done[l][kl][prev] = 1;
// 	return dp[l][kl][prev] = ans;
// }

// string s; 
// ll n;
// ll costs[26][26];
// ll dp[101][101][27];
// bool done[101][101][27];
// ll rec(ll level,ll left,ll prev)
// {
//     if(left<0) return -1e9;
//     if(level==n) return 0;
//     ll ans=-1e9;
//     if(done[level][left][prev]) return dp[level][left][prev];
//     for(int i=0;i<26;i++)
//     {   
//         if(i==(int)(s[level]-'a')) ans=max(ans,rec(level+1,left,i)+((level>0)?costs[prev][i]:0LL));
//         else 
//         {
//             ans=max(ans,rec(level+1,left-1,i)+((level>0)?costs[prev][i]:0LL));
//         }

//     }
//     done[level][left][prev]=1;
//     return dp[level][left][prev]=ans;
// }

// void solve31(){
// 	memset(costs,0,sizeof(costs));
// 	ll i,j,k,m; cin>>s; n=s.length(); cin>>k;
//     cin>>m;
//     f(i,0,m)
//     { char x,y; ll c; cin>>x>>y>>c;
//       costs[x-'a'][y-'a'] = c;
//     }
//     f(i,0,n)
//     {
//         f(j,0,k+1)
//         {
//             for(int l=0;l<26;l++)done[i][j][l]=0;
//         }
//     }
//     //for(auto &it:mp)cout<<it.F<<"->"<<it.S.F<<" "<<it.S.S<<'\n';
//     cout<<rec(0,k,s[0]-'a');
    
//     cout<<'\n'; 
// }

// void solve3(){

// 	memset(costs,0,sizeof(costs));

	
// 	cin>>s>>k;
// 	n = s.length();

// 	f(i,0,n+1){
// 		f(j,0,k+1){
// 			f(p,0,26){
// 				done[i][j][p] = 0;
// 			}
// 		}
// 	}

// 	int m;
// 	cin>>m;

// 	f(i,0,m){
// 		char x,y; int c;
// 		cin>>x>>y>>c;
// 		costs[x-'a'][y-'a'] = c;
// 	}
// 	cout<<rec(0,k,(int)(s[0]-'a'))<<'\n';
// }

// int n;
// int a[110];
// int dp[110][110][110];

// int rec(int l, int r, int x){
// 	if(l>r) return 0;

// 	if(dp[l][r][x]!=-1) return dp[l][r][x];

// 	int ans = 0;
// 	ans = max(ans, rec(l+1,r,0)+(x+1)*(x+1));
// 	for(int i=l+1;i<=r;i++){
// 		if(a[l] == a[i]){
// 			ans = max(ans, rec(l+1,i-1,0)+rec(i,r,x+1));
// 		}
// 	}
// 	// cout<<l<<' '<<r<<' '<<ans<<'\n';
// 	return dp[l][r][x] = ans;
// }

// void marbles(){
// 	cin>>n;
// 	f(i,0,n){
// 		cin>>a[i];
// 	}
// 	memset(dp,-1,sizeof(dp));
// 	cout<<rec(0,n-1,0)<<'\n';
// }	

// int n,m,k;
// int a[210][210];
// int dp[210][210][210];

// int rec(int i, int j, int kl){
// 	if(i>=n || j>=m || kl>k || a[i][j] == 1) return 0;
// 	if((i == n-1) && (j == m-1)){
// 		return 1;
// 	}
// 	if(dp[i][j][kl]!=-1) return dp[i][j][kl];
// 	int ans = 0;
// 	ans = ((rec(i+1,j,0)%mod)+(rec(i,j+1,kl+1)%mod))%mod;
// 	return dp[i][j][kl] = (ans+mod)%mod;
// }

// void solve(){

// 	cin>>n>>m>>k;
// 	f(i,0,n){
// 		f(j,0,m){
// 			cin>>a[i][j];
// 		}
// 	}
// 	// memset(dp,-1,sizeof(dp));
// 	f(i,0,n+1){
// 		f(j,0,m+1){
// 			f(l,0,k+1)
// 			dp[i][j][l] = -1;
// 		}
// 	}

// 	cout<<(rec(0,0,0)+mod)%mod<<'\n';

// }

// ll n,k;
// vll a;
// ll dp[1010][1010][2];


// ll rec(int l, int x, int flag){	
	
// 	if(l == n){
// 		return 1;
// 	}

// 	if(dp[l][x][flag]!=-1) return dp[l][x][flag];

// 	ll ans = 0;
// 	if(flag == 0){
// 		if(abs(a[l]-a[l-1])<=k){
// 			ans = (ans+rec(l+1,x,0))%mod;
// 		}
// 		if(abs(a[l]-a[x])<=k){
// 			ans = (ans+rec(l+1,l-1,1))%mod;
// 		}
// 	}else{
// 		if(abs(a[l]-a[l-1])<=k){
// 			ans = (ans+rec(l+1,x,1))%mod;
// 		}
// 		if(abs(a[l]-a[x])<=k){
// 			ans = (ans+rec(l+1,l-1,0))%mod;
// 		}
// 	}
	
// 	return dp[l][x][flag] = ans;
// }

// void solve(){
// 	cin>>n>>k;
// 	a.resize(n);
// 	f(i,0,n){
// 		cin>>a[i];
// 	}
	
// 	sort(all(a));
// 	reverse(all(a));
// 	f(i,1,n){
// 		if(a[i-1]-a[i]>k){
// 			cout<<0<<'\n'; return;
// 		}
// 	}

// 	memset(dp,-1,sizeof(dp));
// 	// cout<<a<<'\n';
// 	int ans = ((rec(1, 0, 0) > 0)?rec(1, 0, 0)-2:rec(1, 0, 0));
//     cout<<(ans+mod)%mod<<'\n';
// }

// int n,x,y,z;
// vii arr;
// int dp[51][51][51];
// bool done[51][51];

// int rec(int l, int r, int xx){
// 	if(l==r){
// 		if(arr[l] == xx) return 0;
// 		return 1e9;
// 	}
// 	if(done[l][r]) return dp[l][r][xx];
// 	f(i,0,50) dp[l][r][i] = 1e9;
	
// 	f(mid,l,r){
// 		f(fs,0,50){
// 			f(ls,0,50){
// 				dp[l][r][(fs*x+ls*y+z)%50] = min(dp[l][r][(fs*x+ls*y+z)%50], rec(l,mid,fs)+rec(mid+1,r,ls)+fs*ls);
// 			}
// 		}
// 	}
// 	done[l][r] = 1;
// 	return dp[l][r][xx];

// }


// void solve(){
// 	memset(done,0,sizeof(done));

// 	cin>>n>>x>>y>>z;
// 	arr.resize(n);
// 	f(i,0,n) cin>>arr[i];
// 	int ans = 1e9;
// 	f(i,0,50){
// 		ans = min(ans, rec(0,n-1,i));
// 	}
// 	cout<<ans<<'\n';

// }

// int n;
// int p[1010];
// int dp[1010];
// int arr[1010];

// int rec(int i){
// 	if(i == n+1){
// 		return 1;
// 	}
// 	if(dp[i]!=-1) return dp[i];
// 	arr[i]++;
// 	int ans = 0;
// 	if(arr[i]%2){
// 		ans = rec(p[i]-1)%mod;
// 	}else{
// 		ans = rec(i+1)%mod;
// 	}
// 	return dp[i] = ans;
// }

// void solve(){
// 	cin>>n;
// 	f(i,0,n){
// 		cin>>p[i];
// 	}
// 	memset(dp,-1,sizeof(dp));
// 	memset(arr,0,sizeof(arr));
// 	cout<<rec(0)<<'\n';
// 	
// }

// int k,n;
// vii arr;

// int dp[1250][1250];
// map<int, int> f;

// int rec(int level, int sz){
// 	if(sz>k) return 0;

// 	if(level<0) return 1;

// 	if(dp[level][sz]!=-1) return dp[level][sz];

// 	int ans = 0;
// 	ans+=rec(level-1,sz)%mod;
// 	ans = ans%mod;
// 	ans += rec(level-1,sz+1)*f[arr[level]]%mod;
// 	ans%=mod;
// 	return dp[level][sz] = ans;

// }

// void solve(){
// 	cin>>n>>k;
// 	f.clear();
// 	f(i,0,n){
// 		ll x;
// 		cin>>x;
// 		f[x]++;
// 	}
// 	int ans = 0;
// 	n = 0;
// 	memset(dp,-1,sizeof(dp));
// 	vii uni;
// 	for(auto e: f){
// 		n++;
// 		uni.pb(e.F);
// 	}
// 	arr = uni;
// 	cout<<rec(n-1,0)<<'\n';
// }

#define int long long

int n,m;
char s[510][510];
int dp[510][510][2];



int check(int x1, int y1, int x2, int y2){
	if(x1>x2 || y1>y2) return 0;
	if(s[x1][y1]!=s[x2][y2]) return 0;

	return dp[x1][x2][(x1+y1)%2];
}

int rec(int x1, int y1, int x2, int y2){
	if(x1>x2 || y1>y2) return 0;
	if(s[x1][y1]!=s[x2][y2]) return 0;
	int ans = 0;
	if(((x1 == x2)&&((y1==y2)||(y1 == y2-1)))||((x1 == x2-1)&&(y1==y2))){
		ans = 1;
	}else{
		ans = (ans+check(x1+1,y1,x2-1,y2))%mod;
		ans = (ans+check(x1,y1+1,x2-1,y2))%mod;
		ans = (ans+check(x1+1,y1,x2,y2-1))%mod;
		ans = (ans+check(x1,y1+1,x2,y2-1))%mod;
	}
	return dp[x1][x2][(x1+y1)%2] = ans;
}
void solve(){
	cin>>n>>m;
	f(i,0,n) f(j,0,m) cin>>s[i][j];
	if(s[0][0]!=s[n-1][m-1]){
		cout<<0<<'\n'; return;
	}
	int d = (n+m)/2;
	while(d--){
		for(int x1=0, y1=d;x1<n;x1++,y1--){
			if(y1>=0 && y1<m){
				for(int x2=n-1;x2>=0;x2--){
					int y2 = (n+m-2)-(x2+d);
					if(y2>=0 && y2<m){
						rec(x1,y1,x2,y2);
					}
				}
			}
		}
	}
	cout<<check(0,0,n-1,m-1)<<'\n';
}	
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    // test(t)
    solve();
    
    
    
}