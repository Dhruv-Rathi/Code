#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll gcd(ll a, ll b){
	return (b == 0)?a:(gcd(b, a%b));
}

const int N = 1e7;

int spf[N];

void fastFact(){
	for(int i=1;i<=N;i++) spf[i] = i;

	for(int i=2;i<=N;i++){
		if(spf[i] == i){
			for(int j=2*i;j<=N;j+=i){
				spf[j] = i;
			}
		}
	}
}

set<int> primeFact(int x){
	set<int> ans;
	while(x>1){
		ans.insert(spf[x]);
		x/=spf[x];
	}
	return ans;
}



void solve(){
	int n; cin>>n;
	vector<int> a(n);
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}

	vector<ll> dp(1e7+1, 0);
	ll ans = 1;
	for(int i=0;i<n;i++){
		if(a[i] == 1) continue;
		set<int> pr = primeFact(a[i]);
		for(auto i: pr){
			dp[i]++;
		}
		ll mx = -1e18;
		for(auto i: pr){
			mx = max(mx, dp[i]);
		}
		for(auto i: pr){
			dp[i] = mx;
		}
		ans = max(ans, mx);
	}

	cout<<ans<<'\n';

}
 
signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
 	fastFact(); 
    ll tc = 1;
    cin>>tc;
    for(int i=1;i<=tc;i++){
    //	cout<<"Case #"<<i<<": ";
    	solve();
    }
    
}