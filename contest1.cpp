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
#define mod 1e9+7
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {
  
  for(auto element : v) {
 
    os << element << " ";
  }
 
  return os;
}



void solve()
{
	ll a,b,c;
	cin>>a>>b>>c;
	ll d = (b*b) - (4*a*c);
	if(a==0)
	{
		cout<<"1\n";
		return;
	}
	if(d>0)
	{
		cout<<"2\n";
	}
	else if(d == 0)
	{
		cout<<"1\n";

	}
	else cout<<"0\n";
}

void solve2()
{
	string s;
	cin>>s;

	vector<int> freq(26,0);
	for(int i=0;i<(int)s.length();i++)
		freq[s[i]-'a']++;
	string first_half;
	char mid;
	bool is_odd = false;
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<freq[i]/2;j++)
		{
			first_half += ('a'+i);
		}
		if(freq[i]%2 == 1){
			if(!is_odd)
			{
				is_odd = true;
				mid = 'a'+i;
			}
		}
	}

	string second_half = first_half;
	reverse(second_half.begin(), second_half.end());
	string ans;
	if(!is_odd)
	{
		ans = first_half+second_half;
	}
	else {
		ans = first_half+mid+second_half;
	}
	cout<<ans<<'\n';
}

void solve3(){
	ll n;
	cin>>n;
	vi arr(n);
	rep(i,0,n) cin>>arr[i];

		
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