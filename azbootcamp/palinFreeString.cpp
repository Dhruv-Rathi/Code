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
#define PB push_back
#define MP make_pair
#define S second
#define F first
#define all(a) (a).begin(), (a).end()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define yesorno(x) cout<<((x)?"YES":"NO")<<"\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <class T> ostream &operator<<(ostream &os, const vector<T> a){ for (auto ele : a) os << ele << " "; return os;} 
template <class T> istream &operator>>(istream &is, vector<T> &a){ for (auto &ele : a) is >> ele; return is; }

const int N = 5*1e4 +10;

ll dp[N];
ll n;
string s;

bool check(string s){
	int n = s.length();
	if(n<=4) return 1;

	for(int i=0;i<n/2;i++){
		if(s[i]!=s[n-i-1]) return 0;
	}
	return 1;
}

void solve(){
	string c;
	cin>>n; 
	cin>>s;
	queue<string> q1, q2;
	if(n<5){
		cout<<"POSSIBLE\n";return;
	}
	if(s[0] == '?'){
		q1.push("1"); q1.push("0");
	}else if(s[0] == '0'){
		q1.push("0");
	}else{
		q1.push("1");
	}

	f(i,1,n+1){
		while(!(q1.empty())){
			string b = q1.front();
			q1.pop();
			ll l = b.size() +1;
			if(s[i] == '?'){
				c = b+"0";
				if(l<=4){
					q2.push(c);
				}else if(l == 5){
					if(!check(c)){
						q2.push(c);
					}
				}else{
					if(check(c) == 0 && check(c.substr(1,l-1)) == 0){
						q2.push(c.substr(1,l-1));
					}
				}
				c = b+'1';
				if(l<=4){
					q2.push(c);
				}else if(l == 5){
					if(check(c) == 0){
						q2.push(c);
					}
				}else{
					if(check(c) == 0 && check(c.substr(1,l-1)) == 0){
						q2.push(c.substr(1,l-1));
					}
				}
			}else{
				c = b+s[i];
				if(l<=4){
					q2.push(c);
				}else if(l == 5){
					if(check(c) == 0){
						q2.push(c);
					}
				}else{
					if(check(c) == 0 && check(c.substr(1,l-1)) == 0){
						q2.push(c.substr(1,l-1));
					}
				}
			}
			
		}
		while(!q2.empty()){
			q1.push(q2.front());
			q2.pop();
		}
		if(q1.empty()){
			cout<<"IMPOSSIBLE\n"; return;
		}
	}

	cout<<"POSSIBLE\n";
}
 
signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    ll tc = 1;
    cin>>tc;
    for(int i=1;i<=tc;i++){
    	cout<<"Case #"<<i<<": ";
    	solve();
    }
    
}