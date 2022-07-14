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
#define test(t) int tc; cin>>tc; while(tc--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <class T> ostream &operator<<(ostream &os, const vector<T> a){ for (auto ele : a) os << ele << " "; return os;} 
template <class T> istream &operator>>(istream &is, vector<T> &a){ for (auto &ele : a) is >> ele; return is; }

struct monoDeque{
	deque<int> dq;
	void insert(int x){
		while(!dq.empty() && dq.back()<x){
			dq.pop_back();
		}
		dq.push_back(x);
	}
	void remove(int y){
		if(dq.front() == y) dq.pop_front();
	}
	int getMax(){
		return dq.front();
	}
};

void solve(){
	monoDeque D;
	int n; cin>>n;
	int arr[n];
	int dp[n];
	f(i,0,n){
		cin>>arr[i];
        dp[i] = arr[i];
	}
	int k; cin>>k;
	f(i,1,n){
		D.insert(dp[i-1]);
		if(i-k-1>=0) D.remove(dp[i-k-1]);

		dp[i] += D.getMax();
		// dp[i] = max(dp[i], dp[i-1]+arr[i-1]); 
	}
	cout<<dp[n-1]<<'\n';
}

void solve2(){
	int n,k; cin>>n; int a[n]; f(i,0,n)cin>>a[i];
    cin>>k;
    multiset<int> st;
    int dp[n];
    dp[0]=a[0];
    f(i,1,n)
    {  
       st.insert(dp[i-1]);
       if(i-k-1>=0) st.erase(st.find(dp[i-k-1]));
       dp[i]=(*st.rbegin())+a[i];
    }
    cout<<dp[n-1]<<'\n';
}

int dungeon[1010][1010];
int n,m;

void witcher(){
	cin>>n>>m;
	f(i,0,n) f(j,0,m) cin>>dungeon[i][j];
	int dp[n][m];
	if(dungeon[n-1][m-1]>=0){
		dp[n-1][m-1] = 1;
	}else{
		dp[n-1][m-1] = 1-dungeon[n-1][m-1];
	}
	frev(i,n-2,0){
		dp[i][m-1] = max(dp[i+1][m-1] - dungeon[i][m-1], 1);
	}
	frev(j,m-2,0){
		dp[n-1][j] = max(dp[n-1][j+1] - dungeon[n-1][j], 1);
	}
	frev(i,n-2,0){
		frev(j,m-2,0){
			dp[i][j] = max(min(dp[i+1][j], dp[i][j+1])-dungeon[i][j],1);
		}
	}
	cout<<dp[0][0]<<'\n';
}


bool check(ll x){
    ll dp[n][m];
    dp[0][0] = x+dungeon[0][0];
    if(dp[0][0]<=0) return false;
    f(i,1,n){
        dp[i][0] = dungeon[i][0]+dp[i-1][0];
        if(dp[i][0]<=0){
            dp[i][0] = -1e18;
        }
    }
    f(j,1,m){
    	dp[0][j] = dungeon[0][j]+dp[0][j-1];
    }
    f(i,1,n){
    	f(j,1,m){
    		dp[i][j] = max(dp[i-1][j], dp[i][j-1])+dungeon[i][j];
    		if(dp[i][j]<=0) dp[i][j] = -1e18;
    	}
    }
    if(dp[n-1][m-1]<=0) return false;
    return true;
}

void sol2(){
    cin>>n>>m;
	f(i,0,n) f(j,0,m) cin>>dungeon[i][j];
    ll lo = 1, hi = (m+n)*1000+1;
    ll ans = hi;
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        if(check(mid)){
        	// cout<<mid<<' ';
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    cout<<ans<<'\n';
}

 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    test(t)
    sol2();
    
}