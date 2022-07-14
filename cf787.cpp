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
	ll a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	x-=a;
	y-=b;
	if(x<=0 && y<=0){
		yes; return;
	} 

	if(x>0){
		c-=x;
	}
	if(c<0){
		no; return;
	}
	if(y>0){
		c-=y;
	}
	if(c<0){
		no; return;
	}
	yes;
}

void solve2(){
	int n; cin>>n;
	ll a[n];
	f(i,0,n){
		cin>>a[i];
	}
	ll ans = 0;
	for(int i=n-2;i>=0;i--){
		while(a[i]>=a[i+1]){
			a[i]/=2;
			ans++;
			if(a[i] == a[i+1] && a[i] == 0){
				cout<<-1<<'\n'; return;
			}
		}
	}

	cout<<ans<<'\n';
}

void solve3(){
	string s; cin>>s;
	if(s.length() == 1){
		cout<<1<<'\n'; return;
	}
	int n = s.length();
	
	if(s[0]=='0' || s[n-1] == '1') {
		cout<<1<<'\n'; return;
	}
	
	int i=0;
	while(s[i]!='0' && i<n){
		i++;
	}
	if(i == n){
		int ans = 0;
		i--;
		while(s[i]!='1' && i>=0){
			i--;
			ans++;
		}
		if(s[i] == '1') ans++;
		cout<<ans<<'\n'; return;
	}
	int j = i;
	while(s[j]!='1' && j>=0){
		j--;
	}
	// cout<<i<<' '<<j<<'\n';
	if(j<0) j = 0;
	cout<<(i-j+1)<<'\n';



}


void solve4(){
	int n; cin>>n;
	vii p(n+1);
	int root;
	vvll path; vll vis(n+1,0);
	set<ll> s;
	f(i,1,n+1){
		cin>>p[i];
		s.insert(p[i]);
	}

	if(n == 1){
		cout<<"1\n1\n1\n\n"; return;
	}

	vll temp;
	f(i,1,n+1){
		if(!vis[i]){
			if(s.find(i)==s.end()){
				ll j=i;
				while(1){
					if(vis[j] == 1) break;
					temp.pb(j);
					vis[j] = 1;
					j = p[j];
				}
				path.pb(temp);
				temp.clear();
			}
		}
	}

	cout<<(n-s.size())<<'\n';
	f(i,0,path.size()){
		cout<<path[i].size()<<'\n';
		for(ll j=path[i].size()-1;j>=0;j--){
			cout<<path[i][j]<<' ';
		}
		cout<<'\n';
	}

	cout<<'\n';



}

void solve5(){
	ll n,k; cin>>n>>k;
	string s; cin>>s;
	ll sum = 0;
	if(k>=25){
		f(i,0,n){
			s[i] = 'a';
		}
		cout<<s<<'\n'; return;
	}
	ll j = 0;
	while(k && j<n){
		ll x = s[j]-'a';
		if(x<=k){
			ll i = j;
			while(s[i]-'a'<=k && i<n){
				x = max(x,(ll)(s[i]-'a'));
				s[i] = 'a';
				// cout<<i<<' ';
				i++;
			}
			j=i; j--;
			while(i<n){
				if(s[i]-'a'<=x){
					s[i] = 'a';
				}
				i++;
			}
			k-=x;
		}else{
			x = s[j] - k;
			char t = s[j]-k, t1 = s[j];
			for(ll i=j;i<n;i++){
				if(s[i]<=t1 && s[i]>t){
					s[i] = t;
				}
			}
			break;
		}
		j++;
	}

	cout<<s<<'\n';
	
}

void solve6(){
	ll n,k; cin>>n>>k;
	string s; cin>>s;
	int i = 0; char t = 'a';
	f(i,0,n){
		if((s[i]-'a')<=k){
			t = max(s[i],t);
		}
	}

	f(i,0,n){
		if(s[i]<=t){
			s[i] = 'a';
		}
	}
	k-=(t-'a');

	cout<<s<<'\n';



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