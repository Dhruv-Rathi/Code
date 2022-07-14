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
	if((s[0]-'0')+s[1]-'0'+s[2]-'0' == (s[5]-'0'+s[4]-'0'+s[3]-'0')){
		cout<<"YES\n";
	}else{
		cout<<"NO\n";
	}
}

void solve2(){
	ll n; cin>>n;
	ll a[n]; f(i,0,n) cin>>a[i];

	sort(a,a+n);ll ans = 0;
	f(i,1,n){
		ans+=(a[i]-a[0]);
	}
	cout<<ans<<'\n';
}

void solve3(){
	ll n,m;
	 cin>>n>>m;
	 string s[n];
	 f(i,0,n){
	 	cin>>s[i];

	 }
	 ll mi = 1e18;
	 f(i,0,n){
	 	
	 	f(j,i+1,n){
	 		ll cur = 0;
	 		f(k,0,m)
	 			cur+=abs(s[i][k]-s[j][k]);
	 		mi = min(mi, cur);
	 	}
	 	
	 }

	 cout<<mi<<'\n';

}

void solve4(){
	ll n,m; cin>>n>>m;
	ll a[n][m];
	f(i,0,n){
		f(j,0,m){
			cin>>a[i][j];
		}
	}
	ll sum = 0, cur;
	f(i,0,n){
		f(j,0,m){
				// cout<<i<<' '<<j<<'\n';
				ll x = i, y = j;
				cur = a[i][j];
				while(x+1<n && y+1<m){
					x++; y++;
					cur+=a[x][y];
				}
				x = i, y = j;
				while(x-1>=0 && y-1>=0){
					x--; y--;
					cur+=a[x][y];
				}
				x = i, y = j;
				while(x+1<n && y-1>=0){
					x++; y--;
					cur+=a[x][y];
				}
				x = i, y = j;
				while(x-1>=0 && y+1<m){
					x--; y++;
					cur+=a[x][y];
				}	
				sum = max(sum, cur);
			
			
		}
	}

	cout<<sum<<'\n';

}

void solve5(){
	ll n,q; cin>>n>>q;
	vll a(n);
	f(i,0,n){
		cin>>a[i];

	}
	sort(all(a));
	reverse(all(a));
	f(i,1,n){
		a[i] += a[i-1];
	}
	while(q--){
		ll x; cin>>x;
		if(lower_bound(all(a), x) == a.end()){
			cout<<-1<<'\n'; 
		}else{
			cout<<(lower_bound(all(a), x) - a.begin()+1)<<'\n';
		}
	}
}

void solve6(){
	ll n,k; cin>>n>>k;
	vll a(n);
	map<ll,ll> m;
	f(i,0,n){
		cin>>a[i];
		m[a[i]]++;
	}
	vll b;ll cnt=  0;map<ll,ll> m2;
	f(i,0,n){
		if(m[a[i]]>=k && m2[a[i]]==0){
			m2[a[i]]++;
			b.pb(a[i]);
			cnt++;
		}
	}
	if(cnt==0){
		cout<<-1<<'\n'; return;
	}
	sort(all(b));

	n = cnt;
	// cout<<b<<'\n';
	cnt = 1;ll l=b[0],r=b[0],ans=1, prev=0,i=1;

	for(i=1;i<n;i++){
		if(b[i] == 1+b[i-1]){
			cnt++;
		}else{
			if(cnt>ans){
				ans = cnt;
				r=b[i-1];
				l = b[prev];
			}
			cnt=1; prev = i;
		}
	}
	if(cnt>ans){
		ans = cnt;
		r=b[i-1];
		l = b[prev];
	}

	cout<<l<<' '<<r<<'\n';
}

int bal[4010];

void dfs(vll a[], int x, int par, string &s){
	bal[x] = (s[x] == 'B')?1:(-1);
	for(auto v: a[x]){
		if(v!=par){
			dfs(a,v,x,s);
			bal[x]+=bal[v];
		}
	}
}

void solve7(){
	ll n; cin>>n;
	vll a[n+1];
	f(i,2,n+1){
		ll x; cin>>x;
		a[i].pb(x);
		a[x].pb(i);
	}
	string s; cin>>s;
	
	s = "A"+s;
	dfs(a,1,0,s); ll ans = 0;
	for(int i=1;i<=n;i++){
		if(bal[i] == 0) ans++;
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
    solve7();
    
    
    
}