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
	int w,x,y,z;
    cin>>w>>x>>y>>z;
    w+=z*y;
    if(w>x){
        cout<<"overflow";
    }else if(w == x){
        cout<<"filled";
    }else cout<<"unfilled";
    cout<<'\n';
}

void solve2(){
    ll n,m; cin>>n>>m;
    vll a(n);
    f(i,0,n){
        cin>>a[i];
    }
    sort(all(a));
    

    reverse(all(a));
    // ll s = 0;
    // f(i,0,n){
    //     f(j,0,n){
    //         s = max(s,a[i]+a[j]+((a[i]-a[j])%m+m)%m);
    //     }
    // }

    // cout<<a<<'\n';
    ll i = 0;
    // while((i+2<n) && ((a[i]+a[i+1]+((a[i+1]-a[i])%m+m)%m)<(a[i+1]+a[i+2]+((a[i+2]-a[i+1])%m+m)%m))){
    //     i++;
    // }

    while(i+2<n){
        ll x = max((a[i]+a[i+1]+((a[i+1]-a[i])%m+m)%m), (a[i]+a[i+1]+((a[i]-a[i+1])%m+m)%m));
        ll y = max(a[i+1]+a[i+2]+((a[i+2]-a[i+1])%m+m)%m, a[i+1]+a[i+2]+((a[i+1]-a[i+2])%m+m)%m);
        if(x<y){i++; }
        else break;
    }

    ll ans = max((a[i]+a[i+1]+((a[i+1]-a[i])%m+m)%m), (a[i]+a[i+1]+((a[i]-a[i+1])%m+m)%m));
    cout<<ans<<'\n';
}

void solveB(){
    ll n,m; cin>>n>>m;
    vll a(n);
    f(i,0,n){
        cin>>a[i];
    }
    sort(all(a));
    reverse(all(a));

    ll s = 0;
    f(i,1,n){
        ll x = max((a[i]+a[0]+((a[0]-a[i])%m+m)%m), (a[i]+a[0]+((a[i]-a[0])%m+m)%m));
        s = max(s,x);
    }

    cout<<s<<'\n';



    
}

void solveC(){
    int n; cin>>n;
    int a[n];
    int final = (1<<30)-1;
    f(i,0,n){
        cin>>a[i];
        final &= a[i];
    }
    int cnt = 0;
    int cur = (1<<30)-1;

    for(int i=0;i<n;i++){
        cur&=a[i];
        if(cur == final){
            cnt++;
            cur = (1<<30)-1;
        }
    }

    cout<<(n-cnt)<<'\n';
}

vvll g;
vll a,b;

void solveD(){
    ll n; cin>>n;
    a.assign(n+1,0);
    b.assign(n+1,0);
    g.resize(n+1);
    ll sum = 0;
    f(i,1,n+1){
        ll x; cin>>x;
        a[i] = x;
        b[i] = 1-x;
        sum+=x;
    }

    f(i,1,n){
        ll x,y; cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    if(sum == (n/2)){
        cout<<0<<'\n'; return;
    }
    cout<<1<<'\n';
    for(int i=n-1;i>0;i--){
        a[i] += a[i+1];
    }
    f(i,1,n+1){
        if(a[i] == (n/2)){
            cout<<i;
            cout<<'\n'; return;
        }
    }


    for(int i=n-1;i>0;i--){
        b[i] += b[i+1];
    }
    // cout<<b<<'\n';
    f(i,1,n+1){
        if(b[i] == (n/2)){
                cout<<i;
            cout<<'\n'; return;
        }
    }

}

void solveD2(){
    ll n; cin>>n;
    vll a(n);
    ll sum = 0;
    f(i,0,n){
        cin>>a[i];
        sum+=a[i];
    }
    f(i,1,n){
        ll x,y; cin>>x>>y;
    }
    if(sum == n/2){
        cout<<"0\n\n";
    }
    cout<<1<<'\n';
    ll ans = n;
    while(sum!=(n/2)){
        if(a[ans-1] == 1){
            sum--;
        }else{
            sum++;
        }
        if(sum == n/2){
            cout<<ans<<'\n'; return;
        }
        ans--;
    }
}


void solveE(){
    ll n,q; cin>>n>>q;
    ll p[n];
    f(i,0,n){
        cin>>p[i];
    }
    while(q--){
        ll l,r; cin>>l>>r;
        ll ans = 1;
        ll i;
        for(i=l;i<r;i++){
            if(p[i]<p[i-1]){
                ans+=2;i++;
            }
        }
        // cout<<i<<'\n';
        if(i>r){
            ans--;
        }
        cout<<ans<<'\n';
    }
}

signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    test(t)
    solveC();
    

    
    
}