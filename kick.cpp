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
	int n; cin>>n;
	ll ans = 1;
	f(i,0,n){
		ll x;
		cin>>x;
		ans = ((ans%mod1)*(x%mod1))%mod1;
	}

	cout<<ans<<'\n';
}

void solve2() {
	ll n,x; cin>>n>>x;
	ll a[n];
	f(i,0,n) cin>>a[i];
	sort(a,a+n);ll ans = 0;
	f(i,0,n){
		ll j = upper_bound(a, a+n, x-a[i])-a;
		if(a[i]<=x-a[i]) j--;
		ans += j;
	}

	cout<<ans<<'\n';
}

void solve3() {
	int q;
	cin>>q;
	stack<int> st;
	f(i,0,q){
		string s;
		cin>>s;
		if(s == "add"){
			int x; cin>>x;
			st.push(x);
		}else if(s == "remove"){
			if(!st.empty())
				st.pop();
		}else{
			if(!st.empty()){
				cout<<st.top()<<'\n';
			}
			else cout<<0<<'\n';
		}
	}
}

void queuestack(){
	int q; cin>>q;
	stack<int> s1,s2;
	int front;
	f(i,0,q){
		string s;
		cin>>s;
		if(s == "push"){
			int x; cin>>x;
			if(s1.empty()){
				front = x;
			}
			s1.push(x);
		}else if(s == "pop"){
			if(s2.empty()){
				while(!s1.empty()){
					s2.push(s1.top());
					s1.pop();
				}
			}
			int x = s2.top();
			s2.pop();
			cout<<x<<'\n';
		}
		else{
			if(s2.empty()){
				cout<<front<<'\n';
			}
			else{
				cout<<s2.top()<<'\n';
			}
		}
	}
}

void paranthesis() {
	string s;
	cin>>s;
	stack<char> st;
	st.push(s[0]);
	f(i,1,s.length()){
		if(s[i] == ')'){
			if(!st.empty() && st.top() == '(')
				st.pop();
			else
				st.push(s[i]);
		}
		else{
			st.push(s[i]);
		}
	}

	cout<<st.size()<<'\n';
}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    test(t)
    paranthesis();
    
    
    
}