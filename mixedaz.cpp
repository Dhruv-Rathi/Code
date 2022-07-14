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
	ll n; cin>>n;
	vector<pair<ll,ll>> v;
	f(i,0,n){
		ll x,y; cin>>x>>y;
		v.push_back({x,1});
		v.push_back({y,-1});
	}
	sort(all(v));
	ll cur = 0, ans = 0;
	for(auto i: v){
		cur+=i.ss;
		ans = max(ans, cur);
	}
	cout<<ans<<'\n';
}
void solve2(){
	int n; cin>>n;
	ll a[n], cur = 0,ans = 0;
	map<ll,ll> m;
	f(i,0,n){
		cin>>a[i];
	}
	f(i,0,n){
		while(m[a[i]] == 1){
			m[a[cur]]--;
			cur++;
		}
		m[a[i]]++;
		ans = max(ans, i-cur+1);
	}
	cout<<ans<<'\n';
}

void solve3(){
	int n,m; cin>>n>>m;
	set<int> uni, inter, diff;
	f(i,0,n){
		int x; cin>>x;
		uni.insert(x);
		inter.insert(x);
		diff.insert(x);
	}
	set<int> inters;
	f(i,0,m){
		int x; cin>>x;
		uni.insert(x);
		if(inter.find(x)!=inter.end()){
			inters.insert(x);
		}
		if(diff.find(x)!=diff.end()){
			diff.erase(x);
		}
	}

	for(int i: uni){
		cout<<i<<' ';
	}
	cout<<'\n';
	for(int i: inters){
		cout<<i<<' ';
	}
	cout<<'\n';
	for(int i: diff){
		cout<<i<<' ';
	}
	cout<<'\n';
}

int pre(char c){
	if(c=='+' || c=='-')
		return 1;
	else if(c == '*' || c == '/')
		return 2;
	else if(c == '^')
		return 3;
	else
		return -1;
}

void solve4(){
	string s; cin>>s;
	stack<char> ss;
	string ans;
	f(i,0,s.size()){
		if(s[i]>='a' && s[i]<='z'){
			ans+=s[i];
		}
		else if(s[i] == '('){
			ss.push('(');
		}
		else if(s[i] == ')'){
			while(!ss.empty() && ss.top()!='('){
				ans+=ss.top();
				ss.pop();
			}
			if(!ss.empty() && ss.top() == '('){
				ss.pop();
			}
		}
		else{
			while(!ss.empty() && pre(s[i])<=pre(ss.top())){
				ans+=ss.top();
				ss.pop();
			}
			ss.push(s[i]);
		}
	}
	while(!ss.empty()){
		ans += ss.top();
		ss.pop();
	}
	cout<<ans<<'\n';
}

void solve5(){
	ll q; cin>>q;
	queue<ll> qq;
	f(i,0,q){
		string s;
		cin>>s;
		if(s == "add"){
			int x; cin>>x;
			qq.push(x);

		}else if(s == "remove"){
			if(!qq.empty()){
				qq.pop();
			}
		}else{
			if(!qq.empty())
			cout<<qq.front()<<'\n';
		}
	}
}

void solve6(){
	ll n,k; cin>>n>>k;
	priority_queue<int> q;
	f(i,0,n){
		ll x; cin>>x;
		q.push(x);
	}
	int ans = 0;
	f(i,0,k){
		int x = q.top();
		ans+=x;
		q.pop();
		q.push(x/2);
	}

	cout<<ans<<'\n';
}

void solve7() {
	int q,k; cin>>q>>k;
	multiset<ll, greater<ll>> m;
	f(i,0,q){
		int ch; cin>>ch;
		ll x,sum,j; char s;
		switch(ch){
			case 1: cin>>x;
			m.insert(x);
			break;
			case 2: cin>>x;
			if(m.find(x) != m.end()){
				m.erase(m.find(x));
			}
			break;
			case 3: cin>>s;sum = 0, j = 0;
			for(auto a: m){
				if(j<k){
					sum+=a;
				}else{
					break;
				}
				j++;
			}
			cout<<sum<<'\n';
		}
	}
}

void solve8(){
	ll h,w,n; cin>>h>>w>>n;
    set<int> h1,w1;
    h1.insert(0); h1.insert(h); w1.insert(0); w1.insert(w); 
    multiset<int> h2, w2;
    h2.insert(h);
    w2.insert(w);
	f(i,0,n){
		char c; cin>>c;
		if(c == 'H'){
			ll y; cin>>y;
            h1.insert(y);
            auto it = h1.lower_bound(y);
            auto it1 = it, it2 = it;
            it1--; it2++;
            h2.erase(h2.find(*it2 - *it1));
            h2.insert(*it2-*it);
            h2.insert(*it-*it1);
		}else{
			ll x; cin>>x;
            w1.insert(x);
            auto it = w1.lower_bound(x);
            auto it1 = it, it2 = it;
            it1--; it2++;
            w2.erase(w2.find(*it2 - *it1));
            w2.insert(*it2-*it);
            w2.insert(*it-*it1);
		}
        int ans = (*prev(w2.end()))*(*prev(h2.end()));
        cout<<ans<<'\n';
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
    solve8();
    
    
    
}