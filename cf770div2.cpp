#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define vi vector<ll>
#define vvi vector<vi>
#define f(x,a,b) for(int x=a;x<b;x++)
#define pb push_back
#define eb emplace_back //faster than push_back
#define mod1 1000000007
#define mod2 998244353
#define ss second
#define ff first
#define all(a) a.begin(), a.end()
#define vecpii vector<pair<int,int>>
#define test(t) int tc; cin>>tc; while(tc--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}

void solve()
{
	int n,k; cin>>n>>k;
	string s;
	cin>>s;
	if(k==0){
		cout<<1<<'\n';return;
	}
	bool f = 0;
	f(i,0,n/2){
		if(s[i]!=s[n-i-1]){
			f = 1;
			break;
		}
	}
	if(f){
		cout<<2<<'\n';
	}else{
		cout<<1<<'\n';
	}
}

void solve2() {
	ll n,x,y;
	cin>>n>>x>>y;
	ll a[n], o=0;

	f(i,0,n) {
		cin>>a[i];
		if(a[i]%2) o++;
	}
	int p = (x%2);
	if(o%2) p = 1-p;
	if(p == y%2) cout<<"Alice\n";
	else cout<<"Bob\n";

}

void solve3(){
	int n,k; cin>>n>>k;
	int e = (n*k)/2;
	int o = n*k - e;
	if(e%k || o%k){
		cout<<"NO\n"; return;
	}
	cout<<"YES\n";
	int x = 2;
	f(i,0,e/k){
		f(j,0,k){
			cout<<x<<' ';
			x+=2;
		}
		cout<<'\n';
	}
	x = 1;
	f(i,0,o/k){
		f(j,0,k){
			cout<<x<<' ';
			x+=2;
		}
		cout<<'\n';
	}
}

void solve4() {
	int n; cin>>n;
	int i=1,j=2,k=3;
	int x[n];
	f(l,0,n){
		if(j == n){
			cout<<"? "<<i<<' '<<j<<' '<<'1';
		}
		else if(i == n){
			cout<<"? "<<i<<' '<<'1'<<' '<<'2';
		}
		else
			cout<<"? "<<i<<' '<<j<<' '<<k;
		i++;j++;k++;
		cout<<'\n';
		cin>>x[l];
	}
	for(int i=n-1;i>=0;i--) {
		// cout<<x[i]<<' ';
		if((i-1)>=0 && x[i] == x[i-1]){
			cout<<"! "<<(i)<<' '<<(i+1)<<'\n';
			return;
		}
	}
}
// ALGOZ Q. NOT CODEFORCES.
void algoz(){
	int n; cin>>n;
	vector<pair<int, string>> v;
	f(i,0,n){
		string s;
		int roll;
		cin>>s>>roll;
		v.pb({roll,s});
	}
	sort(all(v));
	f(i,0,n){
		cout<<v[i].ss<<' '<<v[i].ff<<'\n';
	}

}
 
signed main()
{
    // fast
    
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

 
    test(t)
    solve4();
    
    
    
}