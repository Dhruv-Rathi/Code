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
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <class T> ostream &operator<<(ostream &os, const vector<T> a){ for (auto ele : a) os << ele << " "; return os;} 
template <class T> istream &operator>>(istream &is, vector<T> &a){ for (auto &ele : a) is >> ele; return is; }

void solve(){
	ll n; cin>>n;

	vll a(n); cin>>a;
	sort(all(a));
	map<ll,ll> mp;
	f(i,0,n){
		mp[a[i]%10]++;
	}
	if(mp[1]>=3 || (mp[1] && mp[0] && mp[2])||(mp[3] && mp[0]>=2)){
		yes; return;
	}
	if((mp[9]>=2 && mp[5])||(mp[9]&&mp[8]&&mp[6])||(mp[9]&&mp[7]>=2)||(mp[8]>=2&&mp[7])){
		yes; return;
	}
	if((mp[0] && ((mp[6]&&mp[7])||(mp[8]&&mp[5])||(mp[9]&&mp[4])))||
		(mp[1] && ((mp[6]>=2)||(mp[7]&&mp[5])||(mp[8]&&mp[4])||(mp[9]&&mp[3])))||
		(mp[2] && ((mp[6]&&mp[5])||(mp[7]&&mp[4])||(mp[8]&&mp[3])||(mp[9]&&mp[2])))||
		(mp[3]>=2 && mp[7])||(mp[6]&&mp[4]&&mp[3])||(mp[5]>=2&&mp[3])||(mp[4]>=2&&mp[5])){
		yes; return;
	}
	no;
}

void solve2(){
	ll n; cin>>n;

	vll a(n); cin>>a;
	sort(all(a));
	map<ll,ll> m;
	f(i,0,n){
		m[a[i]%10]++;
	}
	f(i,0,10){
    	f(j,0,10){
    		f(k,0,10){
    			if((i+j+k)%10 == 3){
	    			if(m[i] && m[j] && m[k] && (i!=j && j!=k && i!=k)){
	    				yes; return;
	    			}else if(m[i] && m[j] && m[k] && (i==j || i==k || j==k)){
	    				if(i==j && j==k){
	    					if(m[i]>2){
	    						yes; return;
	    					}
	    				}
	    				if(i==j && (i!=k)){
	    					if(m[i]>1){
	    						yes; return;
	    					}
	    				}
	    				if(i == k && (i!=j)){
	    					if(m[i]>1){
	    						yes; return;
	    					}
	    				}
	    				if(j==k && (i!=j)){
	    					if(m[j]>1){
	    						yes; return;
	    					}
	    				}
	    			}
	    		}
    		}
    	}
    }
    no;
}
 
signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 	

    // f(i,0,10){
    // 	f(j,i,10){
    // 		f(k,j,10){
    // 			if((i+j+k)%10 == 3){
    // 				cout<<i<<' '<<j<<' '<<k<<'\n';
    // 			}
    // 		}
    // 	}
    // }

    test(t)
    solve2();
    
}