#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define vi vector<ll>
#define vvi vector<vi>
#define f(x,a,b) for(int x=a;x<b;x++)
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
	ll a,b; cin>>a>>b;
	cout<<__gcd(a,b)<<'\n';

}

void solve2(){
	ll n; cin>>n;
	vi a(n);
	ll sum = 0;
	rep(i,0,n) {
		cin>>a[i];
		sum += a[i];
	}
	if(sum%4){
		cout<<"NO\n";
		return;
	}
	sum = sum/4;
	set<ll> s1, s2;
	for(ll i=0;i<n/2;i++){

	}

}	

void solve3(){
	ll n,k; cin>>n>>k;
	vi a(n);
	rep(i,0,n) cin>>a[i];
	ll ans=abs(a[0]-k);
	for(ll i=0;i<n;i++){
		ll b = a[i];
		for(ll j=i;j<n;j++){
			ans = min(ans, abs(b-k));
			if(i<n-1)
			b = b&(a[i+1]);
			cout<<ans<<' ';
		}
	}
	cout<<'\n';
	// cout<<ans<<'\n';
}

void solve4(){
	int q; cin>>q;
	multiset<int> m;
	ll sum = 0;
	int x,y; char c;
	while(q--){
		cin>>x;
		switch(x){
			case 1: cin>>y; m.insert(y); sum+=y; break;
			case 2: cin>>y;
					if(m.find(y)!=m.end()){
						m.erase(m.find(y));
						sum-=y;
					}
					break;
			case 3: cin>>c;
					if(m.empty()) cout<<-1<<'\n';
					else{
						cout<<*(m.begin())<<'\n';
					}
					break;
			case 4: cin>>c;
					if(m.empty()) cout<<-1<<'\n';
					else{
						cout<<*(m.rbegin())<<'\n';
					}
					break;
			case 5: cin>>c;
					cout<<sum<<'\n';
		}
	}
	
}

void solve5(){
	ll n; cin>>n;
	ll a[n],b[n];
	ll m = 0;
	f(i,0,n){
		cin>>a[i]>>b[i];
		m = max(m,b[i]);
	}
	ll ans[m+1]={0};
	f(i,0,n){
		ans[a[i]]++;
		ans[b[i]]--;
	}
	f(i,1,m+1){
		ans[i] += ans[i-1];
	}
	sort(ans,ans+m+1);
	cout<<ans[m]<<'\n';
}

void solve6(){
	ll n; cin>>n;
	vector<pair<ll,ll>> v;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		
	}
}
signed main()
{
    fast
    
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

 
    test(t)
    solve5();
    
    
    
}