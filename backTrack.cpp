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
 
int n=8;
int ans;
string board[8];
vector<int> queens;

bool check(int row,int col){
	for(int prow=0;prow<row;prow++){
		int pcol = queens[prow];
		if(pcol == col || abs(prow-row)==abs(pcol-col)){
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
		if(board[level][col] == '.'){
			if(check(level,col)){ // check
			queens.push_back(col);
			rec(level+1); // go into the recursion
			queens.pop_back();
			}
		}
		
	}
}

void solve(){
	ans = 0;
	for(int i=0;i<8;i++){
		cin>>board[i];
	}
	rec(0);
	cout<<ans<<endl;
}	

void solvek(){
	int n, k;
	cin>>n>>k;
	vi ans(n);
	rep(i,0,n){
		ans[i] = i+1;
	}
	rep(i,0,k-1){
		next_permutation(all(ans));
	}
	for(auto e:ans){
		cout<<e<<' ';
	}
}

void solvek2(){
	ll n,k;
	cin>>n>>k;
	ll a[n];
	for(int i=1;i<=n;i++){
		a[i-1]=i;
	}
	while(k>1){
		ll temp=1;
		ll j=n-1;
		for(int i=1;;i++){
			if(temp*i>=k){
				break;
			}
			temp *= i;
			j--;
		}
		int val = (k+temp-1)/temp;
		swap(a[j], a[j+val-1]);
		sort(a+j+1, a+n);
		k -= (val-1)*temp;
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<' ';
	}
}


signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	//int _t;cin>>_t;while(_t--)
	solvek2();
}