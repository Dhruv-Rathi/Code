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
	ll n; cin>>n;
	ll a[n];
	f(i,0,n){
		cin>>a[i];
	}
	stack<ll> st;
	st.push(a[0]);
	ll k = 1;
	while(!st.empty() && k<n){
		ll x = st.top();
		if(x == a[k]){
			st.pop();
		}
		st.push(a[k++]);
	}

	cout<<(st.size())<<'\n';
}

void solve2(){
	ll n; cin>>n;
	string s; cin>>s;
	char arr[] = {'a','e','i','o','u'};
	ll ans = 1;
	f(i,0,n){
		int mi = 1e9;
		for(int j=0;j<5;j++){
			mi = min(mi, abs(s[i]-arr[j]));
		}
		ll cnt = 0;
		for(int j=0;j<5;j++){
			if(abs(s[i]-arr[j]) == mi){
				cnt++;
			}
		}
		ans = ((ans%mod)*(cnt%mod))%mod;
	}

	cout<<(ans+mod)%mod<<'\n';
}

ll n,k;
vector<vector<pll>> g;

int dep[100100];
int par[100100];
int subtreeSz[100100];


void solve3(){
	cin>>n>>k;
	g.resize(n+1);
	vector<pair<pair<ll,ll>,ll>> edges;
	f(i,0,n-1){
		ll a,b,c;
		cin>>a>>b>>c;
		g[a].pb({b,c});
		g[b].pb({a,c});
		edges.pb(mp(mp(a,b),c));
	}

	int ans = 0, cnt = 0, cnt2;

	// dfs(1,0,0);

	for(auto v: g[1]){
		if(v.S == 0){
			cnt++;
		}
	}

	if(cnt>k){
		cout<<-1<<'\n'; return;
	}
}


vii b[26];
int ans[26][200200];

void solve4(){
	int n; cin>>n;

	f(i,0,26){
		b[i].clear();
	}
	f(i,0,26){
		f(j,0,n+1) ans[i][j] = 0;
	}

	string s; 
	cin>>s;

	int cnt = 1;
	
	char ch ;

	f(j,0,26){
		cnt = 0;
		ch = 'a'+j;
		f(i,0,n){
			if(s[i] == ch){
				cnt++;
			}else if(cnt>0){
				b[j].pb(cnt);
				cnt = 0;
			}
		}
		if(cnt>0){
			b[j].pb(cnt);
		}
	}
	
	f(j,0,26){
		sort(all(b[j]));
		reverse(all(b[j]));
		// cout<<b[j]<<'\n';
	}
	
	f(j,0,26){
		int i=0;
		if(b[j].size())
			ans[j][i] = b[j][0];
		else {ans[j][i] = 0;}
		while(i<(n+1)){
			i++;
			if(i<b[j].size()){
				ans[j][i]= ans[j][i-1]+b[j][i];
			}else{
				ans[j][i] = ans[j][i-1];
			}
		}
	}

	// f(i,0,26){
	// 	f(j,0,n+1) cout<<ans[i][j]<<' ';
	// 	cout<<'\n';
	// }


	f(i,0,n+1){
		int ma = -1e9;
		f(j,0,26){
			ma = max(ma,ans[j][i]);
		}
		cout<<ma<<' ';
	}
	cout<<'\n';
}



 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    test(t)
    solve4();
    
    
}