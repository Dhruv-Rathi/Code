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
string ans="";
void dfs(int l, int n, int o){
    if(l == n){
        assert(o=1);
        ans+=')';
        cout<<ans<<'\n';
        ans.pop_back();
        return;
    }
    if(!o){
        ans+='(';
        dfs(l+1, n, o+1);
        ans.pop_back();
    }
    else{
        int rem = n-l+1;
        if(rem>o){
            ans+='(';
            dfs(l+1, n,o+1);
            ans.pop_back();
        }
        ans+=')';
        dfs(l+1, n, o-1);
        ans.pop_back();
    }
}


void solve2(){
	int n; cin>>n;
	string ans;
	for(int i=0;i<n/2; i++){
		ans+='(';
	}
	for(int i=0;i<n/2;i++){
		ans+=')';
	}
	cout<<ans<<'\n';
	int x = n/2 - 1;
	for(int i=x;i>0;i--){
		string ans="";
		for(int j=0;j<i;j++){
			ans+='(';
		}
		char prev='(';
		for(int j=0;j<(n-2*i);j++){
			if(prev=='('){
				ans+=')';
				prev=')';
			}
			else{
				ans+='(';
				prev='(';
			}
		}
		for(int j=0;j<i;j++){
			ans+=')';
		}
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
	
    int n;
    cin>>n;
    dfs(1,n,0);
 
    // test(t)
    // solve2();
    
    return 0;
    
}