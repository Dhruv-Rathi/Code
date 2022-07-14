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

	ll a[n][5];
	rep(i,0,n)
	{
		rep(j,0,5){
			cin>>a[i][j];
		}
	}
	int count[5] = {0};
	rep(i,0,5)
	{
		rep(j,0,n)
		{
			if(a[j][i] == 1){
				count[i]+=1;
			}
		}
	}
	int f = 0;
	rep(i,0,5)
	{
		if(count[i] >= (n/2)){
			rep(j,i+1,5)
			{
				if(count[j]>=(n/2))
				{
					bool all=true;
					rep(k,0,n)
					{
						if(a[k][i] == 0 && a[k][j] == 0)
						{
							all = false;
							break;
						}
					}
					if(all)
					{
						f = 1;
						break;
					}
				}
				if(f) break;
			}
		}
		if(f) break;

			
	}
	if(f)
		cout<<"YES\n";
	else
		cout<<"NO\n";


}

void solve2()
{
	ll n;
	cin>>n;
	vi a(n);
	ll sum = 0;
	map<ll, ll> m;
	rep(i,0,n){
		cin>>a[i];
		sum+=a[i];
		m[a[i]]++;
	}
	ll ans = 0;
	sum *= 2;
	if(sum%n != 0)
	{
		cout<<0<<'\n';
		return;
	}
	sum/=n;
	rep(i,0,n)
	{
		ans+=m[sum - a[i]];
		if(sum-a[i] == a[i])
		{
			ans--;
		}
	}
	ans/=2;
	cout<<ans<<'\n';

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
        solve2();
    }  
    
    
   return 0;
}