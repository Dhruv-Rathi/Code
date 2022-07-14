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
	string s; cin>>s;

	int d = 0, ch1 = 0, ch2 = 0, sp = 0;

	f(i,0,n){
		if(s[i]>='0' && s[i]<='9'){
			d++;
		}else if(s[i]>='a' && s[i]<='z'){
			ch1++;
		}else if(s[i]>='A' && s[i]<='Z'){
			ch2++;
		}else{
			sp++;
		}
	}
	while(n<7){
	    if(ch1==0){
		s+='a';
		ch1++;
    	}
    	else if(ch2 == 0){
    		s+='A';
    		ch2++;
    	}
    	else if(d==0){
    		s+='1';
    		d++;
    	}
    	else if(sp == 0){
    		s+='#';
    		sp++;
    	}else{
    	    s+='a';
    	    ch1++;
    	}

		
		n++;
	}
	if(ch1==0){
		s+='a';
	}
	if(ch2 == 0){
		s+='A';
	}
	if(d==0){
		s+='1';
	}
	if(sp == 0){
		s+='#';
	}

	cout<<s<<'\n';

}

void solve2(){
	ll n,x,y; cin>>n>>x>>y;
	cout<<"POSSIBLE\n";
	cout<<"IMPOSSIBLE\n";
}
 
signed main()
{
    fast
    
   #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    int tc; cin>>tc;
    for(int i=1;i<=tc;i++){
    	cout<<"Case #"<<i<<": ";
    	solve();
    }
    
    
    
    
}