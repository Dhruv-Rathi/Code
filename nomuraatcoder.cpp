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
template <class T> istream &operator>>(istream &is, vector<T> &a){ for (auto &ele : a) is >> ele; return is; }

void solve(){
	int a,b,c; cin>>a>>b>>c;
	if((b>=a && c>=b)||(a>=b && b>=c)){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
}

void solve2(){
	int h,w; cin>>h>>w;
	char s[h][w];
	int x1=-1, y1=-1, x2=-1, y2=-1;
	f(i,0,h){
		f(j,0,w){
			cin>>s[i][j];
			if(s[i][j] == 'o'){
				if(x1 == -1){
					x1 = i; y1 = j;
				}else{
					x2 = i; y2 = j;
				}
			}
		}
	}
	cout<<(abs(x1-x2)+abs(y1-y2));
	// f(i,0,h){
	// 	f(j,0,w){
	// 		cout<<s[i][j];
	// 	}cout<<'\n';
	// }
}

void solve3(){
	int q; cin>>q;
	multiset<ll> s;
	map<ll,int> mp;
	while(q--){
		int ch; cin>>ch;
		if(ch == 1){
			ll x; cin>>x;
			mp[x]++;
			s.insert(x);
		}else if(ch == 2){
			ll x; cin>>x;
			int c; cin>>c;
			c = min(c, mp[x]);
			if(c == mp[x]){
				s.erase(x);
				mp[x] = 0;
			}else{
				f(i,0,c){
					s.erase(s.find(x));
				}
				mp[x]-=c;
			}
		}else{
			cout<<(ll)(*(s.rbegin())-*(s.begin()))<<'\n';
		}
	}
}

void solve4(){
	ll n,a,b; cin>>n>>a>>b;
	ll sum = (n*(n+1))/2;
	ll x = (n/a);
	sum-=a*((x*(x+1))/2);
	x = (n/b);
	sum -= b*((x*(x+1))/2);
	x = (n/((a*b)/__gcd(a,b)));
	sum+=((a*b)/__gcd(a,b))*((x*(x+1))/2);

	cout<<sum;

}

void solve5(){
	ll n; cin>>n;
	vll c(n); cin>>c;
	vll w(n); cin>>w;
	vll pre(n,0); pre[0] = w[0];
	f(i,1,n){
		pre[i] = pre[i-1]+w[i];
	}

	ll ans = 0, head = -1, tail = 0;
	map<ll,ll> m;

	while(tail<n){
		while(head+1<n && (m[c[head+1]] == 0)){
			head++;
			m[c[head]]++;
		}
		if(tail == 0)
			ans = max(ans, pre[head]);
		else
			ans = max(ans, pre[head]-pre[tail-1]);
		if(tail<=head){
			m[c[tail]]--;
			tail++;
		}else{
			tail++;
			head = tail-1;
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
    solve5();
    
    
    
}