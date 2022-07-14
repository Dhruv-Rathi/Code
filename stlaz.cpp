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
	int n; cin>>n;
	string s; cin>>s;
	int dir = 0,x=0,y=0;
	int dx[] = {0,1,0,-1};
	int dy[] = {1,0,-1,0};
	for(char c: s){
		if(c == 'L'){
			dir = (dir-1+4)%4;
		}else if(c == 'R'){
			dir = (dir+1)%4;
		}else{
			x+=dx[dir];
			y+=dy[dir];
		}
	}
	if(x==0 && y==0){
		cout<<"YES";
	}else if(dir != 0){
		cout<<"YES";
	}else{
		cout<<"NO";
	}cout<<'\n';
}

void solve2(){
	int n; cin>>n;
	int h[n];
	f(i,0,n){
		cin>>h[i];
	}
	
	ll ans = 0; int i=0;
	stack<int> s;
	while(i<n){
		if(s.empty() ||(h[i]>=h[s.top()])){
			s.push(i);
			i++;
		}else{
			int t = s.top();
			s.pop();
			if(s.empty()){
				ans = max(ans, 1LL*i*h[t]);
			}else{
				ans = max(ans, 1LL*h[t]*(i-s.top()-1));
			}
		}
	}

	while(!s.empty()){
		int t = s.top();
		s.pop();
		if(s.empty()){
			ans = max(ans, 1LL*i*h[t]);
		}else{
			ans = max(ans, 1LL*h[t]*(i-s.top()-1));
		}
	}
	cout<<ans<<'\n';
}

void solve3(){
	int n; cin>>n;
	vii h(n);
	f(i,0,n){
		cin>>h[i];
	}
	
	ll ans = 0;
	int r[n];
	int rmax = 0;

	for(int i=n-2;i>=0;i--){
		rmax = max(rmax, h[i+1]);
		r[i] = rmax;
	}
	int lmax = 0;
	for(int i=1;i<n-1;i++){
		lmax = max(lmax, h[i-1]);
		int a = min(lmax, r[i]);
		if(a>h[i]){
			ans+=(a-h[i]);
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
    solve3();
    
    
    
}