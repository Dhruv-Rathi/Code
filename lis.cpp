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

// O(nlogn)
int lis(vi arr){
	vi temp;
	for(auto v: arr){
		if(temp.empty()||temp.back()<v){
			temp.pb(v);
		}
		else{
			auto it = lower_bound(temp.begin(), temp.end(),v);
			*it = v;
		}
	}
	return temp.size();
}
// LCS of A and B.
void solve()
{
	vi A, B, temp;
	map<int, int> mp;
	for(int i=0;i<(A.size());i++){ // all elements of A is distinct.
		mp[a[i]] = i;
	}
	for(auto v: B){
		if(mp.find(v)!=mp.end()){
			temp.pb(mp[v]);
		}
	}

	cout<<lis(temp)<<'\n';
}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    test(t)
    solve();
    
    
    
}