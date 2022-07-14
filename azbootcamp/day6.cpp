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
	int n = s.length();
	map<char,int> m;
	for(int i=0;i<n;i++){
		m[s[i]]++;
	}

	int last[26]={0};
	for(int i=0;i<n;i++){
		m[s[i]]--;
		if(m[s[i]] == 0){
			last[s[i]-'a'] = i;
		}
	}
	int ma = 0;
	int prev = 0;
	for(int i=0;i<n;i++){
		if(last[s[i]-'a']>ma){
			ma = last[s[i]-'a'];
		}
		if(ma == i){
			cout<<(i-prev+1)<<' ';
			prev = i+1;
		}
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
    solve();
    
    
    
}