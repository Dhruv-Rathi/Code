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
	string s = to_string(n);
	ll mi = 10;
	if(s.length() == 2){
		cout<<s[1]<<'\n'; return;
	}
	f(i,0,s.length()){
		mi = min(mi, (ll)(s[i]-'0'));
	}
	cout<<mi<<'\n';
}

void solve2(){
	ll a,b,c; cin>>a>>b>>c;
	ll x,y,z;
	z = c;
	y = (z+b);
	x = (y+a);
	cout<<x<<' '<<y<<' '<<z<<'\n';
}

void solve3(){
	int n,m; cin>>n>>m;
	vll g[n];
	f(i,0,n){
		f(j,0,m){
			ll x; cin>>x;
			g[i].pb(x);
		}
	}
	if(m == 1){
		cout<<1<<' '<<1<<'\n'; return;
	}
	bool f = 0;
	vll b;vll ans, final;
	ll cnt = 0;
	f(i,0,n){
		b = g[i];
		sort(all(b));
		if(b == g[i]){
			cnt++;
			if(i && cnt!=(i+1)){
				if(b[final[0]-1] != b[final[1]-1]){
					cout<<-1<<'\n'; 
					return;
				}
				
			}
		}else{
			ans.clear();
			f(j,0,m){
				if(b[j]!=g[i][j]){
					ans.pb(j+1);
				}
			}
			if(ans.size()>2){
				cout<<-1<<"\n"; return;
			}
			if((int)(final.size()) == 0){
				final = ans;
			}
			else{
				if(final!=ans){
					cout<<-1<<'\n'; return;
				}
			}
		}
	}
	if(final.size()){
		f(i,0,n){
			b = g[i];
			sort(all(b));
			if(b == g[i]){
				
				if(b[final[0]-1] != b[final[1]-1]){
					cout<<-1<<'\n'; 
					return;
				}
				
			}
		}
	}
	if(cnt == n){
		cout<<1<<' '<<1<<'\n'; return;
	}
	else{
		cout<<final<<'\n';
	}
}


void solve4(){
	int n,k; 
	cin>>n>>k;
	vll a(n); vpll b(n);
	f(i,0,n){
		cin>>a[i];
		b[i].F = a[i]+i;
		b[i].S = i;
	}
	if(k == n){
		cout<<0<<'\n'; return;
	}
	sort(all(b));
	reverse(all(b));
	vll j;
	f(i,0,k){
		j.pb(b[i].S);
	}
	sort(all(j));
	// cout<<j<<'\n';
	ll ans = 0, jj=0, bon = 0;
	f(i,0,n){
		if(i == j[jj] && jj<j.size()){
			jj++; 
			bon++;
			continue;
		}
		ans+=a[i]+bon;
	}
	cout<<ans<<'\n';


}

void solve5(){
	int n,k; cin>>n>>k;
	vll a(n);
	map<int,int> m;
	f(i,0,n){
		cin>>a[i];
		m[a[i]]++;
	}
	if(k>=n){
		cout<<"0\n"; return;
	}

	sort(all(a));

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