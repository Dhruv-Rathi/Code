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

void solve()
{
	ll n;
	cin>>n;
	ll b[n];
	for(ll i=0;i<n;i++)
	{
		cin>>b[i];
	}
	vector<pair<ll,ll>> p;
	for (ll i=0;i<n;i++)
		p.pb({b[i],i});
	sort(p.rbegin(),p.rend());
	// for(ll i=0;i<n;i++)
	// {
	// 	cout<<p[i].ff<<' '<<p[i].ss<<'\n';
	// }
	ll x = p[0].ff - 1;
	vector<pair<ll,ll>> ans;
	for(ll i=0;i<n;i++)
	{
		if(x<0){
			x = p[0].ff-1;
		}
		if(x<p[i].ff){
			ans.pb({p[i].ss,x--});
		}
		else{
			x = p[i].ff-1;
			ans.pb({p[i].ss,x--});
		}
	}
	sort(ans.begin(),ans.end());
	for(ll i=0;i<n;i++)
	{
		cout<<ans[i].ss<<' ';
	}
	cout<<'\n';
}

void solve2()
{
	string s1, s2,x;
	getline(cin,s1);
	getline(cin,s2);
	getline(cin,x);
	

}
 
int main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    ll t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }  
    
    
   return 0;
}