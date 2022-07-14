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
#define FOR(x,a,b) for(int x=a;x<b;x++)
#define FORr(x,a,b) for(int x=a;x>=b;x--)
#define PB push_back
#define MP make_pair
#define S second
#define F first
#define all(a) (a).begin(), (a).end()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define yesorno(x) cout<<((x)?"YES":"NO")<<"\n"
#define test(t) int tc; cin>>tc; while(tc--)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <class T> ostream &operator<<(ostream &os, const vector<T> a){ for (auto ele : a) os << ele << " "; return os;} 
template <class T> istream &operator>>(istream &is, vector<T> &a){ for (auto &ele : a) is >> ele; return is; }

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}

void solve(){
	int n; cin>>n;
	vpll s(n);
	FOR(i,0,n){
		cin>>s[i].F>>s[i].S;
	}
	sort(all(s), sortbysec);
	int ans = 1;
	ll prev = s[0].S;
	FOR(i,1,n){
		if(s[i].F>prev){
			ans++;
			prev = s[i].S;
		}
	}
	cout<<ans<<'\n';
}

string s; int n;

int dp[1010][1010];

int isPal(int i, int j){
	if(i>j) return 1;
	if(dp[i][j]!=-1) return dp[i][j];
	
	if(s[i] == s[j]) return dp[i][j] = isPal(i+1,j-1);
	return dp[i][j] = 0;
}

void solve2(){
	memset(dp,-1,sizeof(dp));
	cin>>s;
	n = s.length();
	int ma = 0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(isPal(i,j)){
				ma = max(ma, j-i+1);
			}
		}
	}
	// cout<<ma<<'\n';
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(isPal(i,j) && ma == (j-i+1)){
				cout<<s.substr(i,j-i+1)<<'\n'; return;
			}
		}
	}
}
 
signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    test(t)
    solve2();
    
}