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

void solve3()
{
	ll n; int d;
	cin>>n>>d;
	ll n1 = n, pos = 0;
	stack<ll> s;
	while(n1>0)
	{
		ll x = n1%10;
		s.push(x);
		n1 = n1/10;
		pos++;
	}

	ll ans = 0,cnt = 0;
	if(d == 9)
	{
		for(ll i = pos;i>0;i--){
			if(s.top() == 8){
			ans+=(s.top())*pow(10,i-1);
			cnt++;
		}
		else if(s.top() == 9)
		{
			ans+=(s.top()+1)*pow(10,i-1);
			break;
		}
		else{
			ans+=(s.top())*pow(10,i-1);
			cnt = 0;
		}
		s.pop();
		}
		ans = ans-n ;
		ll ans2 = ans;
		ll x = 0;
		while(ans2%10 == 0){
		    x++;
		ans2/=10;
		}
		
		if(ans2%10 == 1)
		{
			for(ll i = 0;i<cnt;i++)
			{
			    
				ans = ans*10+pow(10,x);
			}
			cout<<ans<<'\n';
			return;
		}
		ll ans1 = 0;
		ll z = ans;
		for(ll i=0;i<cnt;i++)
		{
		    
			ans1 = ans1*10 + 1;
		}
		while(z>0)
		{
			ans1 *= 10;
			z/=10;
		}

		ans1 *= 10;
		cout<<(ans1+ans)<<'\n';
		return;
		
	}
	for(ll i = pos;i>0;i--)
	{
		if(s.top() == d)
		{
			ans+=(s.top()+1)*pow(10,i-1);
			if(d!=0){break;}
		}
		else{
			ans+=(s.top())*pow(10,i-1);
		}
		s.pop();
	}

	cout<<(ans - n)<<'\n';
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
        solve3();
    }  
    
    
   return 0;
}