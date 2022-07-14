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
	string s;
	cin>>s;
	string s1 = s;
	// cout<<s;
	sort(s.begin(), s.end());
	
	cout<<s[0]<<' ';
	int f = 0;
	for(ll i=0;i<s1.length();i++){
		if(s1[i] == s[0] && f == 0)
		{
			f = 1;
			continue;
		}
		cout<<s1[i];
	}
	cout<<'\n';
}

void solve2(){
	ll n; cin>>n;
	vi a(n);
	vi m(2000,0);
	rep(i,0,n){
		cin>>a[i];
		m[a[i]]++;
	}
	vi m1(2000,0);
	m1 = m;
	vi a1(n);
	a1 = a;

	ll z = 0;
	while(1){
		ll cnt = 0;
		rep(i,0,n){
			if(a[i] == m[a[i]]){
				cnt++;
			}
			a[i] = m[a[i]];

		}
		if(cnt == n){
			break;
		}
		rep(i,0,2000){
			m[i] = 0;
		}
		rep(i,0,n){
			m[a[i]]++;
		}
		z++;
	}
	ll q;
	cin>>q;
	while(q--){
		ll x,k;
		cin>>x>>k;
		
		if(k == 0){
			cout<<a1[x-1]<<'\n';
			continue;
		}

		if(k>=z)
		{
			cout<<a[x-1];
		}
		else{
			vi a2(n), m2;
			a2 = a1;
			m2 = m1;
			for(ll i=1;i<=k;i++){
				rep(i,0,n){
					a2[i] = m2[a2[i]];
				}
				rep(i,0,2000){
					m2[i] = 0;
				}
				rep(i,0,n){
					m2[a2[i]]++;
				}
			}
			cout<<a2[x-1];
		}
		
		cout<<'\n';
	}

}	

void solve3(){
	ll n;
	cin>>n;
	vi a(n);
	rep(i,0,n){
		cin>>a[i];
	}
	cout<<'1 ';
	for(ll i=2;i<=n;i++){
		
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
    solve2();
    
    
    
}