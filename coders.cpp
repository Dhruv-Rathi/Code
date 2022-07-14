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

void solve()
{
    ll n,l,r,k;
    cin>>n>>l>>r>>k;
    vi a(n);
    vi b;ll z = 0;
    rep(i,0,n) {
        cin>>a[i];
        if(a[i]>=l && a[i]<=r){
            b.pb(a[i]);
            z++;
        }
    }
    sort(b.begin(), b.end());
    ll ans = 0;
    rep(i,0,z){
        if(k>=b[i]){
            k-=b[i];
            ans++;
        }
        else{
            break;
        }
    }
    cout<<ans<<'\n';    
    

}
bool sortbysec(const pair<ll,ll> &a,
              const pair<ll,ll> &b)
{
    return (a.second > b.second);
}
  

void solve2(){
    ll n; cin>>n;
    vi a(n);
    vi a1 = a;
    vector<pair<ll,ll>> p;
    rep(i,0,n) 
    {
        cin>>a[i];
        p.push_back({i,a[i]});
    }
    sort(a.rbegin(), a.rend());
    sort(p.begin(), p.end(), sortbysec);
    // for(auto e: p){
    //     cout<<e.first<<' '<<e.second<<'\n';
    // }
    
    vi ans(n+1);
    ans[0] = 0;
    ll sum = 0;
    ll k = 1;
    for(ll i=0;i<n;i+=2){
        if(i == n-1)
        {
            sum+=k*a[i];
            ans[p[i].first+1] = k;
            break;
        }
        sum+=(k)*(a[i]+a[i+1]);
        ans[p[i].first+1]=k;
        ans[p[i+1].first+1] = -1*k;
        k++;
    }
    
    cout<<(2*sum)<<'\n';
    cout<<ans<<'\n';
    

}

void solve3(){

    
}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    test(t)
    solve2();
    
    
    
}