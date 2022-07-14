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

void solve(ll tcnt)
{
	cout<<"Case #"<<tcnt<<": ";
	ll n,d,c,m;
	cin>>n>>d>>c>>m;
	string s;
	getline(cin,s);
	getline(cin,s);
	// cout<<s<<'\n';

	rep(i,0,n)
	{
		if(d == 0 && s[i] == 'D')
		{
			cout<<"NO\n";
			return;
		}
		if(c == 0 && s[i] == 'C')
		{

			rep(j,i,n)
			{
				// cout<<"Hello";
				if(s[j] == 'D'){
					cout<<"NO\n";
					return;
				}
			}
			break;
		}
		if(s[i] == 'D')
		{
			d--;
			c+=m;
		}
		if(s[i] == 'C')
		{
			c--;
		}

	}
	cout<<"YES\n";
	

}

void solve2(ll tcnt)
{
	cout<<"Case #"<<tcnt<<": ";
	ll k; cin>>k;
	vi x1(k),y1(k),x2(k),y2(k);
	ll x=0,y=0;
	rep(i,0,k)
	{
		cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
		
	}
	ll cnt[k] = {0};
	ll cnt1[k] = {0};
	rep(i,0,k)
	{
		x = x1[i];
		y = y1[i];
		rep(i,0,k)
		{
			if((x<=x2[i] && x>=x1[i])&&(y<=y2[i] && y>=y1[i]))
				cnt[i]++;
		}
		x=x2[i];
		y=y2[i];
		rep(i,0,k)
		{
			if((x<=x2[i] && x>=x1[i])&&(y<=y2[i] && y>=y1[i]))
				cnt1[i]++;
		}
	}
	ll m=0, m1=0;
	ll p=0, p1=0;
	rep(i,0,k)
	{
		if(cnt[i]>m)
		{
			m = cnt[i];
			p=i;
		}
		if(cnt1[i]>m)
		{
			m = cnt1[i];
			p1=i;
		}
	}
	if(m>=m1)
	{
		rep(i,0,k)
		{
			if(cnt[i] == m)
			{
				cout<<x1[i]<<' '<<y1[i]<<'\n';
				return;
			}
		}
	}
	else{
		rep(i,0,k)
		{
			if(cnt1[i] == m1)
			{
				cout<<x2[i]<<' '<<y2<<'\n';
				return;
			}
		}
	}
	
	
}
 

void solve3(ll tcnt)
{
	cout<<"Case #"<<tcnt<<": ";
	ll n,k;
	cin>>n>>k;
	vi b(n), s(n,0);
	cin>>b[0];
	s[0] = b[0];
	rep(i,1,n){
		cin>>b[i];
		s[i] = s[i-1]+b[i];
	}
	// cout<<s<<'\n';
	ll z=2;
	ll ans = 0;
	for(ll i=0;i<n;i++)
	{
		for(ll j = i+1;j<n;j++)
			{
				
			}
	}

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
        solve2(i);
    }  
    
    
   return 0;
}