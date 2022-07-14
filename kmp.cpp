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
	int kmp[n+1];

	int i=0, j=-1; kmp[0]=-1;
	while(i<n){
		while(j!=-1 && s[i]!=s[j]) j=kmp[j];
		j++; i++;
		kmp[i] = j;
	}
	for(int i=0;i<=n;i++){
		cout<<kmp[i]<<' ';
	}
}

void Zalgo(){
	string s; cin>>s;
	int n = s.length();
	vector<int> z(n,0);
	z[0] = -1;
	for(int i=1,l=0,r=0;i<n;i++){
		// reuse information from starting block.
		if(i<=r){
			z[i] = min(r-i+1,z[i-l]);
		}
		// extend as long as possible.
		while(i+z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;
		// if zbox crossed, make new box.
		if(i+z[i]-1>r){
			l = i;
			r = i+z[i]-1;
		}
	}
	cout<<z<<'\n';
}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    // test(t)
    Zalgo();
    
    
    
}