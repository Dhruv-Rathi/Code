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
	int x,y,a,b,k;
	cin>>x>>y>>a>>b>>k;
	if(x+k*a<y+k*b){
		cout<<"PETROL\n";
	}
	else if(x+k*a == y+k*b)
		cout<<"SAME PRICE\n";
	else
		cout<<"DIESEL\n";
}

void solve2(){
	ll x,y;
	cin>>x>>y;
	if(x%2 == 0 && y%2 == 0){
		cout<<"YES\n";
	}
	else{
		if(y%2){
			if(x%2==0 && x>=2)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
		else if(x%2){
			cout<<"NO\n";
		}
	}
}

void solve3(){
	ll n; cin>>n;
	vi a(n);
	ll cnt = 0;
	rep(i,0,n) {
		cin>>a[i];
		if(a[i]%2)
			cnt++;
	}
	cout<<(cnt/2)<<'\n';

}

void solve4(){
	ll n; cin>>n;
	vi a(n);
	rep(i,0,n) cin>>a[i];
	sort(a.rbegin(), a.rend());
	bool flag = true;
	rep(i,1,n){
		if(a[i] == a[i-1]) {
			flag = false; 
			break;
		}
	}
	if(flag){
		cout<<a<<'\n';
		return;
	}

	map<ll,ll> cnt;
	rep(i,0,n){
		cnt[a[i]]++;
	}
	// cout<<cnt<<'\n';
	if(cnt[a[0]]>1){
		cout<<"-1\n";
		return;
	}
	int f = 0;
	for(ll i=0;i<n;i++){

		if(cnt[a[i]]>2){
			f = 1;
			break;
		}
	}
	if(f) {
		cout<<"-1\n";
		return;
	}
	for(ll i=n-1;i>0;i--){
		if(cnt[a[i]] == 2){
			cout<<a[i]<<' ';
			i--;
		}
	}
	cout<<a[0]<<' ';
	for(ll i = 1;i<n;i++){
		cout<<a[i]<<' ';
		if(cnt[a[i]]==2) i++;
	}
	cout<<'\n';


}

void solve5(){
	ll n,m;
	cin>>n>>m;
	for(ll i = 1; i<n;i++){
		cout<<i<<' '<<(i+1)<<'\n';
	}
	m = m-(n-1);
	while(m>0){
		ll i = 1;
		
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
    solve5();
    
    
    
}