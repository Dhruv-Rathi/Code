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
	int l1,r1,l2,r2;
	cin>>l1>>r1>>l2>>r2;
	int ans;
	if(max(l1,l2)<=r1 && max(l1,l2)<=r2){
		ans = max(l1,l2);
	}else{
		ans = (l1+l2);
	}
	cout<<ans<<'\n';
}

void solve2(){
	int n,m; cin>>n>>m;
	char a[n][m];
	// map<int,int> m;
	int cnt = 0,x=0,y=0,d = 1e9;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			if(a[i][j] == 'R'){
				cnt++;
				if(d>(i+j)){
					d = i+j;
					x=i; y=j;
				}
			}
		}
	}

	if(cnt == 1){
		yes; return;
	}
	if(cnt == 0){
		no; return;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j] == 'R'){
				if(i<x || j<y){
					no; return;
				}
			}
		}
	}
	yes; 


}

signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    test(t)
    solve3();
    
    
    
}