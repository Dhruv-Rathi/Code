#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1e9+7
#define vi vector<ll>
#define vvi vector<vi>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define ss second
#define ff first
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {
  
  for(auto element : v) {
 
    os << element << " ";
  }
 
  return os;
}


void solveB1(){
       ll s,b;
       cin>>s>>b;
       vi a(s);
       rep(i,0,s) cin>>a[i];
       vector<pair<ll, ll>> p;
       
       rep(i,0,b){
              ll d,g;
              cin>>d>>g;
              p.pb(make_pair(d,g));
       }
       sort(p.begin(), p.end());
       vi p2(b);
       rep(i,0,b){
              p2[i] = p[i].ff;
       }
       // cout<<p2<<'\n';
       vi ans(b,0);
       ans[0] = p[0].ss;
       rep(i,1,b){
              ans[i] = p[i].ss + ans[i-1];
       }
       // cout<<ans<<'\n';
       rep(i,0,s){
              if(a[i]<p2[0])
              {
                     cout<<0<<' ';
                     continue;
              }
              ll x = lower_bound(p2.begin(), p2.end(), a[i]) - p2.begin();
              // cout<<p2[x]<<' ';
              // cout<<x<<' ';
              if(p2[x]>a[i] )
                     x--;
              

              cout<<ans[x]<<' ';
       }
}

int main()
{
    fast
    #ifndef ONLINE_JUDGE
              freopen("input.txt","r",stdin);
              freopen("output.txt","w",stdout);
              #endif
    // ll t;
    // cin>>t;
    // for(int i=1;i<=t;i++)
    // {

    //     solve1();
    // }  
    solveB1();
    
    
   return 0;
}