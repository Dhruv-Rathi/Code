#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	ll n; cin>>n;
	vector<ll> a(n);
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	stack<int> st;
	for(ll i=0;i<n;i++){
		if(a[i]<0 && !st.empty() && st.top()>0){
			if(-a[i]>st.top()){
				st.pop();
				i--;
			}else if(-a[i] == st.top()){
				st.pop();
			}
		}
		else{
			st.push(a[i]);
		}
	}
	cout<<st.size()<<'\n';
	vector<ll> ans;
	while(!st.empty()){
		ans.push_back(st.top());
		st.pop();
	}
	reverse(ans.begin(), ans.end());
	for(ll i=0;i<ans.size(); i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
}

 
signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    ll tc = 1;
    cin>>tc;
    for(int i=1;i<=tc;i++){
    //	cout<<"Case #"<<i<<": ";
    	solve();
    }
    
}