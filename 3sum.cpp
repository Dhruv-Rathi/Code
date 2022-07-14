#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define vi vector<ll>
#define vvi vector<vi>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define ss second
#define ff first
#define all(arr) arr.begin(), arr.end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test(t) ll t;cin>>t;while(t--)
 
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}
ll x,y;
vector<pair<ll,ll>> a;

bool check(ll z){
    
    ll cnt=0, st=-1;
    for(ll i=0; i<(ll)a.size(); i++){
        ll l = a[i].ff;
        ll r = a[i].ss;
        if(!i) {
            ll len = r-l;
            cnt+=(len/z+1);

            ll lastP = len/z * z + l;
            st = lastP+z;
        }
        else{
            // We have something for st;
            if(st<=l){
                ll len = r-l;
                cnt+=(len/z+1);

                ll lastP = len/z * z + l;
                st = lastP+z;
            }
            else{
                // Starting >= st and st >l
                if(st > r){
                    continue;
                }
                ll len = r-st;
                cnt+=(len/z+1);

                ll lastP = len/z * z + st;
                st = lastP+z;
            }
        }
    }
    return cnt>=x;
}

void solve()
{
    cin>>x>>y;
    a.resize(y);
    rep(i,0,y){
        ll a1,b;
        cin>>a1>>b;
        a.pb({a1,b});
    }
	sort(all(a));
    ll ans = 0;
    ll L=1, R=1e18;
    while(L<=R){
        ll mid = (L + R) / 2;
        if(check(mid)){
            ans = mid;
            L = mid+1;
        }
        else{
            R = mid-1;
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

 
    // test(t)
    solve();
    
    
    
}