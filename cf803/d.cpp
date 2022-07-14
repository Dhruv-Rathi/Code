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
#define test(t) int tc; cin>>tc; while(tc--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <class T> ostream &operator<<(ostream &os, const vector<T> a){ for (auto ele : a) os << ele << " "; return os;} 
template <class T> istream &operator>>(istream &is, vector<T> &a){ for (auto &ele : a) is >> ele; return is; }

inline vector<int> query(int l, int r){
	cout << "? " << l <<" "<<r<< endl;
	cout.flush();
	vector<int> a;
	f(i,0,r-l+1){
		int x;
		cin>>x;
		a.PB(x);
	}
	return a;
}

inline void answer(int ans){
	cout << "! " << ans << endl;
	cout.flush();
}

bool check(int l, int mid){
	vector<int> a = query(l, mid);
	int x = a.size();
	ll ans = 0;	
	f(i,0,x){
		if(a[i]>=l && a[i]<=mid) ans++;
	}
	return (ans%2);
}

void solve(){
	int n;
	cin>>n;
	int lo = 1, hi = n, ans = 1;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(check(lo, mid)){
			ans = mid;
			hi = mid-1;
		}else{
			lo = mid+1;
		}
	}
	answer(ans);

}

signed main()
{

	int t; cin>>t; while(t--)
	solve();
   


   return 0; 
}