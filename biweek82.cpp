#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll len;
ll dp[15][110][110][2][2];

ll gcd(ll a, ll b){
	return (b==0)?a:(gcd(b, a%b));
}

ll rec(ll l, ll sod, ll pro, ll f, ll az, string &s){
	if(sod<0) return 0;
	if(l == len) return (sod == 0 && pro == 1);
	if(dp[l][sod][pro][f][az]!=-1) return dp[l][sod][pro][f][az];
	ll ans = 0, y;
	if(f == 1){
		for(ll i=0; i<(s[i]-'0'+1);i++){
			if(i<s[l]-'0') f = 0;
			else f = 1;
			if(i == 0) y = (az?pro: 1);
			else{
				y = pro/gcd(pro,i) ;
			}
		ans += rec(l+1, sod-i, y, f, az&(i == 0), s);
		}
	}else{
		for(ll i=0;i<10;i++){
			ll y = pro;
			if(i == 0) y = (az?pro:1);
			else{
				y = pro/gcd(pro, i) ;
			}
			ans+=rec(l+1,sod-i,y,f,az&(i==0),s);
		}
	}
	return dp[l][sod][pro][f][az]=ans;
}

void solve(){
	
	ll a, b;
	cin>>a>>b;
	memset(dp,-1,sizeof(dp));
	string s = to_string(b);
	len = s.length();
	ll ans = 0;
	for(int i=1;i<110;i++) ans+=rec(0,i,i,1,1,s);
	memset(dp,-1,sizeof(dp));
	a--;
	s = to_string(a);
	len = s.length();
	for(int i=1;i<110;i++) ans-=rec(0,i,i,1,1,s);

	cout<<ans<<'\n';
	


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
    	cout<<"Case #"<<i<<": ";
    	solve();
    }
    
}