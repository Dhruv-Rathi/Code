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
#define frev(x,a,b) for(int x=a;x>=b;x--)
#define PB push_back
#define MP make_pair
#define S second
#define F first
#define all(a) (a).begin(), (a).end()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define yesorno(x) cout<<((x)?"YES":"NO")<<"\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <class T> ostream &operator<<(ostream &os, const vector<T> a){ for (auto ele : a) os << ele << " "; return os;} 
template <class T> istream &operator>>(istream &is, vector<T> &a){ for (auto &ele : a) is >> ele; return is; }

// int n,m;

// int happy[55][15];

// ll memo[51][(1<<10)];

// ll dp(int i, int mask){
// 	if(i == m) return 0;
// 	if(memo[i][mask]!=-1) return memo[i][mask];
// 	ll ans = dp(i+1,mask);
// 	for(int j=0;j<n;j++){
// 		if(((1<<j)&mask) == 0) 
// 		ans = max(ans, dp(i+1, mask|(1<<j))+happy[i][j]);
// 	}
// 	return memo[i][mask] = ans;
// }

// void solve(){
// 	memset(memo,-1,sizeof(memo));

// 	cin>>n>>m;
// 	f(i,0,m){
// 		f(j,0,n){
// 			cin>>happy[i][j];
// 		}
// 	}
// 	cout<<dp(0,0)<<'\n';
// }


// ll n,m;
// vector<vector<ll>> g;
// ll init;
// ll dp[21][(1LL<<20)];

// ll rec(ll i, ll mask){
//     if(dp[i][mask]!=-1) return dp[i][mask];
//     ll ans = 0;
//     for(auto v: g[i]){
//         if(__builtin_popcountll(mask)>2 && v == init){
//             ans++;
//         }else if(v>init && !(mask&(1LL<<v))){
//             ans+=rec(v, (mask|(1LL<<v)));
//         }
//     }
//     return dp[i][mask] = ans;
// }

// void solve(){
//     cin>>n>>m;
//     g.resize(n+1);
//     for(ll i=0;i<m;i++){
//         ll a,b; cin>>a>>b;
//         a--; b--;
//         g[a].push_back(b);
//         g[b].push_back(a);
//     }
//     memset(dp,-1,sizeof(dp));
//     ll ans = 0;
//     for(ll i=0;i<n;i++){
//         init = i;
//         ans+=rec(i,(1LL<<i));
//     }
//     ans = ans/2;
//     cout<<ans<<'\n';
// }

// int n;
// int dist[20][20];
// ll dp[15][(1LL<<15)];

// ll rec(int i, int mask){
//     if(mask == ((1LL<<n)-1)){
//         if(i == 0) return 0;
//         return 1e18;
//     }
//     if(dp[i][mask]!=-1) return dp[i][mask];
//     ll ans = 1e18;
//     for(int j=0;j<n;j++){
//         if((mask&(1LL<<j)) == 0){
//             ans = min(ans, rec(j,(mask|(1LL<<j)))+dist[i][j]);
//         }
//     }
//     return dp[i][mask] = ans;
// }

// void solve(){
//     memset(dp,-1,sizeof(dp));
//     cin>>n;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++) cin>>dist[i][j];
//     }
//     cout<<rec(0,0)<<'\n';
// }


// int N;
// int A[20];
// ll dp[10][1<<20];// -> dp[1<<20] TC = O(N^2 * 2^2N)
// ll bestPairing(int board, int mask){
//     if(board == N) return 0;
//     if(dp[board][mask]!=-1) return dp[board][mask];
//     ll ans = -1e18;
//     for(int i=0;i<2*N;i++){
//         for(int j=i+1;j<2*N;j++){
//             if(((mask)&(1LL<<i | 1LL<<j))==0){
//                 ans = max(ans, bestPairing(board+1,mask|(1<<i)|(1<<j))+(board+1)*abs(A[i]-A[j])*(__gcd(A[i], A[j])));
//             }
//         }
//     }
//     return dp[board][mask] = ans;
// }
// void solve(){
// 	cin>>N;
// 	for(int i=0;i<2*N;i++) cin>>A[i];
// 	memset(dp,-1,sizeof(dp));
// 	cout<<bestPairing(0,0)<<'\n';
// }

// int n;
// int isEdge[16][16];
// ll dp[1<<15];

// int rec(int l, int mask){
// 	if(l == n) return 0;
// 	if(dp[mask]!=-1) return dp[mask];
// 	ll ans = 2e18;
// 	for(int i=0;i<n;i++){
// 		if((mask&(1<<i))==0){
// 			ll temp = 0;
// 			for(int j=0;j<n;j++){
// 				if((mask&(1<<j))){
// 					temp+=isEdge[i][j];
// 				}
// 			}
// 			ans = min(ans, rec(l+1,mask|(1<<i))+temp);
// 		}
// 	}
// 	return dp[mask] = ans;
// }

// void solve(){
// 	memset(dp,-1,sizeof(dp));
// 	cin>>n;
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<n;j++) cin>>isEdge[i][j];
// 	}
// 	cout<<rec(0,0)<<'\n';
// }

// int n;
// int a[16][16];
// ll hap[(1LL<<16)];

// void pre(){
// 	hap[0] = 0;
// 	for(int mask = 1;mask<(1LL<<n);mask++){
// 		int temp = -1;
// 		for(int i=0;i<n;i++){
// 			if(mask&(1LL<<i)){temp = i; break;}
// 		}
// 		hap[mask] = 0;
// 		for(int i=0;i<n;i++){
// 			if(mask&(1LL<<i)){ hap[mask]+=a[i][temp];}
// 		}
// 		hap[mask] += hap[mask^(1<<temp)];
// 	}
// }

// ll dp[(1LL<<17)];
// bool done[(1LL<<17)];

// ll rec(ll mask){
// 	if(mask == 0) return 0;
// 	if(done[mask]) return dp[mask];
	
// 	ll ans = 0;
// 	for(int submask = mask; submask; submask = (submask-1)&mask){
// 		ll temp = hap[submask];
// 		ans = max(ans, temp+rec(mask^submask));
// 	}
// 	done[mask] = 1;
// 	return dp[mask] = ans;
// }

// void solve_U(){
// 	memset(done,0,sizeof(done));
// 	cin>>n;
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<n;j++) cin>>a[i][j];
// 	}
// 	pre();
// 	cout<<rec((1<<n)-1)<<'\n';
// }

// int n,m;

// void generate_next_masks(int curr_mask, int i, int next_mask, vector<int> &next_masks){
// 	if(i == n+1){
// 		next_masks.PB(next_mask);
// 		return ;
// 	}
// 	if((curr_mask&(1<<i))!=0){
// 		generate_next_masks(curr_mask, i+1,next_mask, next_masks);
// 	}
// 	if(i!=n){
// 		if((curr_mask&(1<<i)) == 0 && (curr_mask&(1<<(i+1))) == 0)
// 			generate_next_masks(curr_mask,i+2,next_mask,next_masks);
// 	}
// 	if((curr_mask&(1<<i)) == 0)
// 		generate_next_masks(curr_mask, i+1, next_mask+(1<<i),next_masks);

// }

// ll dp[1001][(1<<12)];

// ll rec(int col, int mask){
// 	if(col == m+1){
// 		if(mask == 0) return 1;
// 		return 0;
// 	}
// 	if(dp[col][mask]!=-1) return dp[col][mask];
// 	ll ans = 0;
// 	vector<int> next_masks;
// 	generate_next_masks(mask, 1,0,next_masks);
// 	for(auto next_mask: next_masks){
// 		ans = (ans+rec(col+1,next_mask))%mod;
// 	}
// 	return dp[col][mask] = ans;
// }

// void solve(){
// 	cin>>n>>m;
// 	if(n%2 && m%2){
// 		cout<<"0\n"; return;
// 	}

// 	memset(dp,-1,sizeof(dp));
	
// 	cout<<rec(1,0)<<'\n';
// }

int n;
int a[22][22];
ll full_mask = 1;

vector<vector<int>> dp(22, vector<int>((1LL<<22),-1));

ll rec(int level, ll mask){
	if(n+1-level!=n-__builtin_popcount(mask)) return 0;
	if(level == n+1 && mask!=full_mask) return 0;
	if(level == n+1 && mask == full_mask) return 1;

	if(dp[level][mask]!=-1) return dp[level][mask];
	ll ans = 0;
	for(int i=1;i<(n+1);i++){
		if(a[level][i]!=0){
			ll p = 1LL<<(i-1);
			ll nmask = (mask|p);
			if(!(mask&p)){
				ans=(ans+rec(level+1,nmask))%mod;
			}
		}
	}
	return dp[level][mask] = ans;
}

void solve_O(){
	cin>>n;

	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		full_mask = (full_mask|(1LL<<i));
	}
	cout<<rec(1,0)<<'\n';
}

void add_self(int &a, int b){
	a+=b;
	if(a>=mod) a-=mod;
}

void solve_O_DP_Atcoder(){
	int n; cin>>n;
	vector<vector<int>> can(n, vector<int>(n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) cin>>can[i][j];

	vector<int> dp(1 << n);
	dp[0] = 1;

	for(int mask=0; mask < (1 << n)-1; mask++){
		int a = __builtin_popcount(mask);
		for(int b = 0; b < n; b++){
			if(can[a][b] && !(mask & (1 << b))){
				int m2 = mask ^ (1 << b);
				add_self(dp[m2], dp[mask]);
			}
		}
	}

	cout<<dp[(1<<n)-1]<<'\n';
}


signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    ll tc = 1;
    // cin>>tc;
    for(int i=1;i<=tc;i++){
    //	cout<<"Case #"<<i<<": ";
    	solve_O_DP_Atcoder();
    }
    
}