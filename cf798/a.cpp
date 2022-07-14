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
#define FOR(x,a,b) for(int x=a;x<b;x++)
#define FORr(x,a,b) for(int x=a;x>=b;x--)
#define PB push_back
#define MP make_pair
#define S second
#define F first
#define all(a) (a).begin(), (a).end()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define yesorno(x) cout<<((x)?"YES":"NO")<<"\n"
#define test(t) int tc; cin>>tc; while(tc--)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <class T> ostream &operator<<(ostream &os, const vector<T> a){ for (auto ele : a) os << ele << " "; return os;} 
template <class T> istream &operator>>(istream &is, vector<T> &a){ for (auto &ele : a) is >> ele; return is; }

void solve(){
	int n,m,k; cin>>n>>m>>k;
	string a,b; cin>>a>>b;
	sort(all(a)); sort(all(b));
	string c="";
	int i=0, j=0, l1=0, l2=0;
	while(i<n && j<m){
		if(a[i]<b[j]){
			if(l1<k){
				c+=a[i]; i++;
				l1++;  l2 = 0;
			}else{
				c+=b[j]; j++;
				l1 = 0; l2++;
			}
		}else{
			if(l2<k){
				c+=b[j]; j++;
				l2++; l1 = 0;
			}else{
				c+=a[i]; i++;
				l2 = 0; l1++;
			}
		}
	}

	cout<<c<<'\n';

	
}
 
signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    test(t)
    solve();
    
}