#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define vi vector<ll>
#define vvi vector<vi>
#define f(x,a,b) for(int x=a;x<b;x++)
#define pb push_back
#define eb emplace_back //faster than push_back
#define mod1 1000000007
#define mod2 998244353
#define ss second
#define ff first
#define all(a) a.begin(), a.end()
#define vecpii vector<pair<int,int>>
#define test(t) int tc; cin>>tc; while(tc--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}

bool isPrime(ll x){
    if(x%2==0) return 0;
    for(ll i=3;i*i<=x;i+=2){
        if(x%i == 0) return 0;
    }
    return 1;
}
vi ans ;
ll a,b;

inline bool inrange(ll x){
    if(x<a || x>b || !isPrime(x)) return 0;
    return 1;
}

void getnumns(ll lo, ll hi, ll mul){
    if(hi*mul+lo>b) return;
    if(inrange(hi*mul+lo)){
        ans.pb(hi*mul+lo);
    }
    for(int j=0;j<=9;j++){
        if(inrange((hi*10+j)*mul+lo))
            ans.pb((hi*10+j)*mul+lo);
    }
    for(int j=0;j<=9;j++){
        getnumns(j*mul+lo,hi*10+j,mul*10);
    }
}

void solve(){
    cin>>a>>b;
    f(i,2,10){
        if(inrange(i)){
            ans.push_back(i);
        }
    }
    getnumns(1,1,10);
    getnumns(3,3,10);
    getnumns(5,5,10);
    getnumns(7,7,10);
    getnumns(9,9,10);
    cout<<ans.size()<<'\n';
}

signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    // test(t)
    solve();
    
}