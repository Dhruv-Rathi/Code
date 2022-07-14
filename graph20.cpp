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
typedef vector<vector<pii>> vvpll;
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

vii g[(1<<20)];
bool ban[(1<<20)];

int getVal(string s){
	int Val = 0;
	for(int i=0;i<20;i++){
		if(s[i] == '1'){
			Val|=(1<<i);
		}
	}
}

void add_edge(int a, int b){
	if(!ban[a]&&!ban[b]){
		g[a].pb(b);
		g[b].pb(a);
	}
}

void solve(){
	string s; cin>>s;
	int stVal = getVal(s);
	
	string en;
	cin>>en;
	int enVal = getVal(en);
	int k; cin>>k;
	for(int i=0;i<k;i++){
		string temp; cin>>temp;
		ban[getVal(temp)] = 1;
	}
	for(int i=0;i<(1<<20);i++){
		for(int j=0;j<20;j++){
			add_edge(i,i^(1<<j));
		}
	}
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