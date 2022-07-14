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
	string s;
	cin>>s;
	
	ll n = s.length();
 
	ll n1 = n;
	ll ans = 0;
	while((s[n1-1]) != '5' && n1>0)
	{
		ans++;
		n1--;
	}

	bool flag;

	if(s[n1-1] == '5')
	{
		ll n2 = n1-2;
		while((s[n2] != '2') && (s[n2] != '7') && n2>=0)
		{
			n2--;
			ans++;
		}
		if(n2<0)
		{
			flag = false;
		}
		else
			flag = true;
	}
	else{
		flag = false;
	}
	n1 = n;
	ll ans1 = 0;
	while(s[n1-1] != '0' && n1>0)
	{
		ans1++;
		n1--;
	}
	bool flag1;
	if(s[n1-1] == '0')
	{
		ll n2 = n1-2;
		while((s[n2]!='5')&&(s[n2]!='0')&&n2>=0)
		{
			ans1++;
			n2--;
		}
		if(n2<0)
			flag1 = false;
		else
			flag1 = true;
	}
	else
		flag1 = false;

	if(flag&&flag1)
		cout<<min(ans,ans1)<<'\n';
	else if(flag)
		cout<<ans<<'\n';
	else
		cout<<ans1<<'\n';


}

void solve2()
{
	ll n,k;
	cin>>n>>k;
	ll x[k];
	rep(i,0,k) cin>>x[i];
	sort(x,x+k);
	ll cnt = 1, val = n-x[k-1];
	for(ll i=k-2;i>=0;i--)
	{
		val+=(n-x[i]);
		if(val<n)
			cnt++;
		else
			break;
	}
	cout<<cnt<<'\n';
}
 
void solveD1()
{
	int n; cin>>n;
	int a[n];
	rep(i,0,n) cin>>a[i];
	sort(a,a+n);
	ll i = 1;
	while(a[i] == a[i-1] && i<n)
	{
		i++;
	}
	if(i == n){
		cout<<-1<<'\n';
		return;
	}
	cout<<(a[i]-a[i-1])<<'\n';
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
        solveD1();
    }  
    
    
   return 0;
}