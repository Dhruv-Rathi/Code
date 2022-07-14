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

vector<int> lis(vector<int> arr){
	vector<int> temp;
	vector<int> pos;
	for(auto v: arr){
		if(temp.empty() || v>temp.back()){
			pos.push_back(temp.size());
			temp.push_back(v);
		}
		else{
			auto it = lower_bound(all(temp), v);
			pos.push_back(it-temp.begin());
			*it = v;
		}
	}
	cout<<temp<<'\n'<<arr<<'\n'<<pos<<'\n';
	int lisVal = temp.size()-1;
	vector<int> ans;
	for(int i=pos.size()-1;i>=0;i--){
		if(pos[i] == lisVal){
			ans.push_back(arr[i]);
			lisVal--;
		}
	}
	reverse(all(ans));
	return ans;
}


vector<int> lnds(vector<int> arr){
	vector<int> temp;
	vector<int> pos;
	for(auto v: arr){
		if(temp.empty() || v>=temp.back()){
			pos.push_back(temp.size());
			temp.push_back(v);
		}
		else{
			auto it = upper_bound(all(temp), v);
			pos.push_back(it-temp.begin());
			*it = v;
		}
	}
	int lisVal = temp.size()-1;
	vector<int> ans;
	for(int i=pos.size()-1;i>=0;i--){
		if(pos[i] == lisVal){
			ans.push_back(arr[i]);
			lisVal--;
		}
	}
	reverse(all(ans));
	return ans;
}

void solve(){
	vector<int> a = lnds({1,2,3,4,2,3,4,1});
	vector<int> arr = {1,2,3,4,2,3,4,1};
	reverse(all(arr));
	vector<int> lds = lis(arr);
	reverse(all(lds));
	cout<<a<<'\n'<<lds;
}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    // test(t)
    solve();
    
    
    
}