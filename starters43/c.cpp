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

// void solve(){
// 	ll a,b,c; cin>>a>>b>>c;
// 	ll ma = max({a,b,c});
// 	vll arr = {a,b,c};
// 	sort(all(arr));
// 	// cout<<arr[0]<<arr[1]<<arr[2]<<'\n';
// 	ll d1 = arr[2]-arr[0]; ll d2 = arr[2]-arr[1];
// 	ll k = 0;
// 	// cout<<d1<<' '<<d2<<'\n';
// 	while(d1>0 && d2>0){
// 		if(d1>d2){
// 			d2-=(ll)pow(2,k);
// 		}else{
// 			d1-=(ll)pow(2,k);
// 		}
// 		k++;
// 	}
// 	if(d1<0 || d2<0){
// 		no; return;
// 	}

// 	while(d2>0){
// 		d2-=pow(2,k); k++;
// 	}
// 	if(d2<0){
// 		no; return;
// 	}
// 	while(d1>0){
// 		d1-=pow(2,k); k++;
// 	}
// 	if(d1<0){
// 		no; return;
// 	}
// 	yes;
// }

// void solve2(){
// 	ll a,b,c; cin>>a>>b>>c;
// 	ll ma = max({a,b,c});
// 	vll arr = {a,b,c};
// 	sort(all(arr));
// 	c = ma; a = arr[0]; b = arr[1];
// 	ll k=0;
// 	while(a<c && b<c){
// 		if(a>b){
// 			a+=(ll)pow(2,k);
// 		}else{
// 			b+=(ll)pow(2,k);
// 		}
// 		k++;
// 	}
// 	if(a>c || b>c){
// 		no; return;
// 	}
// 	while(b<c){
// 		b+=(ll)pow(2,k); k++;
// 	}
// 	if(b>c){
// 		no; return;
// 	}
// 	while(a<c){
// 		a+=(ll)pow(2,k); k++;
// 	}
// 	if(a>c){
// 		no; return;
// 	}
// 	yes;
// }



void solve3(){
    ll a,b,c; cin>>a>>b>>c;
   
    ll ma = max({a,b,c});
    ll cnt = 0;
    while(ma){
        ma/=2; cnt++;
    }
    // cout<<cnt<<'\n';
    bool f = 0;
    for(ll i=0;i<cnt;i++){
    	ll x = (a>>i)&1;
    	ll y = (b>>i)&1;
    	ll z = (c>>i)&1;
    	// cout<<x<<' '<<y<<' '<<z<<'\n';
    	if(x == y && x == z){
    		f = 1; break;
    	}
    	if(x+y+z == 2){
    		if(x == 0){
    			a+=(1<<i);
    		}else if(y == 0){
    			b+=(1<<i);
    		}else{
    			c+=(1<<i);
    		}
    	}else if(x+y+z == 1){
    		if(x == 1){
    			a+=(1<<i);
    		}else if(y == 1){
    			b+=(1<<i);
    		}else{
    			c+=(1<<i);
    		}
    	}
    	// cout<<a<<' '<<b<<' '<<c<<'\n';
    }

    if(a == b && a == c){
    	yes;
    }else no;
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
    //	cout<<"Case #"<<i<<": ";
    	solve3();
    }
    
}