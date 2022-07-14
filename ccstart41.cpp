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
#define pb push_back
#define mp make_pair
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

void solve(){
	ll x,y; cin>>x>>y;
	ll ans = 0;
	if(x<y){
		ans+=(y-x);
	}else if(x>y){
		ll z = (x-y);
		ans+=z/2;
		if(z%2){
			ans+=2;
		}
	}
	cout<<ans<<'\n';
}

void solve2(){
	ll n,k; cin>>n>>k;
	if(n==1){
		if(k==0)
			no;
		else
			yes;
		return;
	}
	if(n%2 && k == 0){
		no; return;
	}
	yes;
}

void solve3(){

	ll n,k; cin>>n>>k;
	if(n%2 == 0){
		if(k%2){
			cout<<"Even";
		}else{
			if(k == 2){
				cout<<"Odd";
			}
			else
				cout<<"Even";
		}
	}else{
		if(k%2 == 0){
			if(k == 2)
				cout<<"Odd";
			else
				cout<<"Even";
		}else{
			if(k == 1)
				cout<<"Odd";
			else
				cout<<"Even";
		}
	}cout<<'\n';
}


void solve4(){
	ll n; cin>>n;
	vll a(n);
	cin>>a;
    map<ll,ll> m;
    ll j = 0, ans = 1e18;
    for(ll i=0;i<n;i++){
        m[a[i]]++;
        while(m[a[i]]>1){
            m[a[j]]--;
            j++;
        }
        ans = min(ans, 2*min(j,n-i-1)+max(j,n-i-1));
    }
	cout<<ans<<'\n';
}

const int N = 3e5+11;
int a[N], b[N];
ll black[N], white[N], none[N];
vii g[N];

void dfs(int node, int par){
	if(!b[node])
		white[node]++;
	else
		black[node]++;
	for(auto x: g[node]){
		if(x == par){
			continue;
		}
		dfs(x, node);
		none[node]+=min({none[x], 1+white[x], 1+black[x]});
		if(!b[node]){
			black[node]+=black[x];
			white[node]+=black[x];
		}
		if(b[node]){
			white[node]+=white[x];
			white[node]+=white[x];
		}
	}
	if(a[node]!=b[node]){
		none[node] = 1e9;
	}
	return;
}

void solve5(){
	int n;
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
		g[i].clear();	
		black[i] = white[i] = none[i] = 0;
	}
	f(i,1,n+1) cin>>b[i];

	f(i,1,n){
		int x,y; cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,-1);
	cout<<min({1+black[1], 1+white[1], none[1]})<<'\n';
}

 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    test(t)
    solve5();
    
    
    
}