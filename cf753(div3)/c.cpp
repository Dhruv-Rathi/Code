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
	ll n;
	cin>>n;
	vi a(n);
	rep(i,0,n) cin>>a[i];
	sort(all(a));
	vi ans(n);
	ans[0] = a[0];
	ll m = ans[0];
	rep(i,1,n){
		ans[i] = a[i]-a[i-1];
		m = max(m, ans[i]);
	}
	cout<<m<<'\n';
}

void solve2(){
	int n;
	cin>>n;
	vi a(n+1);
	rep(i,1,n+1){
		cin>>a[i];
	}
	ll cnt = 0, n1=n;
	for(ll i=1;i<(n+1);){
		if(a[i]%(i+1)){
			cnt++;
			n--;
		}
		else{
			i++;
		}
	}
	if(cnt==n1){
		cout<<"YES\n";
	}
	else
		cout<<"NO\n";

	
}


void solve3(){
	int n; cin>>n;
	bool ok = true;
	for(int i=1;i<=n;i++){
		int x; cin>>x;
		bool found = false;
		for(int j=(i+1);j>=2;j--){
			if(x%j){
				found=true;
				break;
			}
		}
		ok&=found;
	}
	if(ok){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
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
    solve3();
    
    
    
}