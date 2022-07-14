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


int memo[51][1<<15];
// TC = O(N*M*2^N)
// call -> dp(0,0);
int dp(int i, int mask){
	if(i == M) return 0;
    if(memo[i][mask]!=-1) return memo[i][mask];
	int ans = dp(i+1,mask);
	for(int j=0;j<N;j++){
		if(((1<<j)&mask)==0){
            ans = max(ans, dp(i+1,mask|(1<<j))+happy[i][j]);
        }
	}
    return memo[i][mask] = ans;
}

int ways(int node, int mask){
    if(mask == ((1<<N)-1)){
        if(node == N) return 1;
        return 0;
    }
    // memo
    int ans = 0;
    for(auto v: neigh[node]){
        if(mask&(1<<(v-1))) continue;
        ans+=ways(v, mask|(1<<(v-1)));
    }
    return ans;
}

// bestPairing(1,0) gives ans
ll dp[10][1<<20];// -> dp[1<<20] TC = O(N^2 * 2^2N)
ll bestPairing(int board, int mask){
    if(board == N+1) return 0;
    if(dp[board][mask]!=-1) return dp[board][mask];

    ll ans = 0;
    for(int i=0;i<2*N;i++){
        for(int j=0;j<2*N;j++){
            if(mask&((1<<i)|(1<<j)) == 0) {
                ans = max(ans, bestPairing(board+1,mask|(1<<i)|(1<<j))+board*abs(A[i]-A[j])*__gcd(A[i], A[j]));
            }
        }
    }
    return dp[board][mask] = ans;
}

int bestChoice(int pos, int mask){
    if(pos == N+1) return 0;
    // Add memo

    int ans = 1e9;
    for(int i=0;i<N;i++){
        if(mask&(1<<i)) continue;
        int temp = 0;
        for(int j = 0;j<N;j++){
            if(mask&(1<<j)) temp+=NumEdge[i][j];
        }
        ans = min(ans, bestChoice(pos+1, mask|(1<<i))+temp);
    }
    return ans;
}

// PreProcessing Group Happiness;
// O(2^N *N)
void pre(){
    G_hap[0] = 0;
    for(int mask=1;mask<(1<<N); mask++){
        int temp = -1;
        for(int i=0;i<N;i++){
            if(mask&(1<<i)){temp = i; break; }
        }
        G_hap[mask] = 0;
        for(int i=0;i<N:i++){
            if(mask&(1<<i)){ G_hap[mask]+=Hap[i][temp];}
        }
        G_hap[mask]+=G_hap[mask^(1<<temp)];
    }
}
// O(3^N)
ll maxHappiness(int mask){
    if(mask == 0) return 0;

    // Add memo

    ll ans = 0;
    for(int submask=mask; submask; submask = (submask-1)&mask){
        ll temp = HAPPINESS_GRP(submask);
        ans = max(ans, temp+maxHappiness(mask^submask));
    }
    return ans;
}

void solve(){
	// kadane practice
    int max_so_far = -1e9, max_ending_here = 0;
    for(int i=0;i<n;i++){
        max_ending_here+=a[i];
        if(max_ending_here>max_so_far){
            max_so_far = max_ending_here;
        }
        if(max_ending_here<0){
            max_ending_here = 0;
        }
    }
    cout<<ma<<'\n';
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