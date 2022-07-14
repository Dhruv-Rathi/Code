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
vector<int> queens;
ll ans=0;
ll n;
bool check(int row,int col){
	for(int prow=0;prow<row;prow++){
		int pcol = queens[prow];
		if(pcol == col || abs(prow-row)==abs(pcol-col)){
			return 0;
		}
		if((prow+2==row && (pcol+1==col || pcol-1==col))||(prow+1==row && (pcol+2==col || pcol-2==col))){
			return 0;
		}
	}
	return 1;
}

void rec(int level){ // level = row
	if(level==n){
		// current state is a solution.
		ans++;
		return;
	}
	for(int col = 0;col<n;col++){ // choices
		
			if(check(level,col)){ // check
			queens.push_back(col);
			rec(level+1); // go into the recursion
			queens.pop_back();
			}
		
		
	}
}

void solve()
{
	cin>>n;
	rec(0);
	cout<<ans;
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
	for(int i=0;i<x;i++){
		string ans="";
		for(int j=0;j<x;j++){
			ans+='(';
		}
		char prev='(';
		for(int j=0;j<(n-2*x);j++){
			if(prev=='('){
				ans+=')';
				prev=')';
			}
			else{
				ans+='(';
				prev='(';
			}
		}
		for(int j=0;j<x;j++){
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

 
    // test(t)
    solve2();
    
    
    
}