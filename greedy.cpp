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
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test(t) int tc; cin>>tc; while(tc--)
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}

void solve()
{
	string s; ll x,y;
	cin>>s>>x>>y;
	ll ans=0;
	string s1="ab", s2="ba";
	if(x<y){
		swap(x,y);
		swap(s1,s2);
	}
	stack<char> st;
	f(i,0,s.length()){
		if(!st.empty() && s[i]==s1[1] && st.top() == s1[0]){
			ans+=x;
			st.pop();
		}
		else
			st.push(s[i]);
	}
	string snew;
	while(!st.empty())
	{
		snew+=st.top();
		st.pop();
	}
	reverse(all(snew));
	f(i,0,snew.length()){
		if(!st.empty() && snew[i]==s2[1] && st.top() == s2[0]){
			ans+=y;
			st.pop();
		}
		else st.push(snew[i]);
	}

	cout<<ans<<'\n';
}

void solve2(){
	int n; cin>>n;
	int a[n], b[n];
	f(i,0,n){
		cin>>a[i];
	}
	f(i,0,n) cin>>b[i];
	sort(a,a+n);
	sort(b,b+n);
	ll sum = 0;
	f(i,0,n){
		sum+=abs(a[i]-b[i]);
	}

	cout<<sum<<'\n';
}

void solve3() {
	int n; cin>>n;
	int x[n],y[n];
	f(i,0,n) cin>>x[i]>>y[i];
	sort(x,x+n); sort(y,y+n);
	ll ans = 0;
	f(i,0,n){
		ans+=abs(x[i]-x[n/2])+abs(y[i]-y[n/2]);
	}
	cout<<ans<<'\n';
}
void solve4() {
	int n; cin>>n;
	int a[n];
	f(i,0,n) cin>>a[i];
	ll ans = 0;
	f(i,1,n){
		if(a[i-1]>a[i]){
			ans+=a[i-1]-a[i];
		}
	}

	cout<<ans<<'\n';
}
 
void solve5() {
	int n; cin>>n;
	vi c(n);
	f(i,0,n) cin>>c[i];
	sort(all(c));
	reverse(all(c));
	f(i,0,n){
		
		while(c[i]>0){
			if()
		}
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
    solve4();
    
    
    
}