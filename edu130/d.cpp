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

inline int query(string& S){
	cout << "? " << S << endl;
	cout.flush();
	int p;
	cin >> p;
	return p;
}
 
inline void answer(int ans){
	cout << "! " << ans << endl;
	cout.flush();
}

signed main()
{
   int n; cin>>n;
   string s="";
   if(n<=26){
   	for(int i=1;i<=n;i++){
   		cout<<"? 1 "<<i<<endl;
   		cout.flush();
   		char a; cin>>a;
   		s+=a;
   	}
   	cout<<"! "<<s<<endl; cout.flush();
   }else{

   	cout<<"? 1 "<<1<<endl;
	cout.flush();
	char a; cin>>a;
	s+=a;
	int i = 1;
	while(i<=n){
		cout<<"? 2 "<<i<<' '<<(i+1)<<endl;
		cout.flush();
		int x; cin>>x;
		if(x == 1){
			s+=a;
			i++;
		}else{
			cout<<"? 1 "<<i+1<<endl;
			cout.flush();
			cin>>a;
			s+=a;
			i++;
		}
	}
	cout<<"! "<<s<<endl; cout.flush();
   	// for(int i=1;i<=26;i++){
   	// 	cout<<"? 1 "<<i<<endl;
   	// 	cout.flush();
   	// 	char a; cin>>a;
   	// 	s+=a;
   	// }
   	// for(int i = 27;i<=n;i++){
   	// 	cout<"? 2 "<<i<<' '<<(i+1)<<endl;
   	// 	cout.flush();

   	// }

   }

   return 0; 
}