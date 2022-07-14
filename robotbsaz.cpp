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

// void print_status(set<pll> st){
// 	cout<<"Current status: ";
// 	for(auto v: st){
// 		cout<<"("<<v.F<<","<<v.S<<"), ";
// 	}
// 	cout<<'\n';
// }

void solve(){
    
    set<pll> st;
    ll cnt=0;

	ll n,k,a; cin>>n>>k>>a;
	st.insert({1,n});

	ll m; cin>>m;
	cnt = (n+1)/(a+1);
	ll x[n];
	f(i,0,m){
		cin>>x[i];
	}

	f(i,0,m){
		
		ll l,r;
		auto it = st.upper_bound({x[i],1e18});

		if(it!=st.begin()){
			it--;
			l = it->F; r = it->S;
			if(r>=x[i]){
				st.erase(it);
				if(x[i] != l){
					st.insert({l,x[i]-1});
				}
				if(x[i] != r){
					st.insert({x[i]+1,r});
				}
			}else{continue;}
		}else{
			continue;
		}
		// print_status(st);
		
		cnt -=((r-l+1)+1)/(a+1);
		if(x[i]!=l){
			cnt+=((x[i]-l)+1)/(a+1);
		}
		if(x[i]!=r){
			cnt+=((r-x[i])+1)/(a+1);
		}
		// cnt+=((x[i]-l)+1)/(a+1) + ((r-x[i])+1)/(a+1);
		// cout<<cnt<<'\n';
		if(cnt<k){
			cout<<(i+1)<<'\n'; return;
		}
	}

	

	cout<<-1<<'\n';
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