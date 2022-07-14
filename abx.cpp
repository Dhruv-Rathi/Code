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
	string s;
	cin>>s;
	int n = s.length();
	int z = (int)(count(all(s),'0'));
	int o = (int)(count(all(s),'1'));

	// cout<<z<<' '<<o<<'\n';

	int head = -1, tail=0,ans = 1e9, cur0=0, cur1=0;

	while(tail<n){
		while((head+1<n)&&(s[head+1]=='1' || (cur0+1<=ans))){
			head++;
			if(s[head] == '1') cur1++;
			else cur0++;

			ans = min(ans,max(cur0,o-cur1));
		}
		if(head>=tail){
			if(s[tail]=='0') cur0--;
			else cur1--;
			ans = min(ans, max(cur0,o-cur1));
			tail++;
		}
		else{
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
    solve();
    
    
    
}