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

vi diva(1001001,0);
void preCompute(){
	for(ll i=1;i<1001001;i++){
		for(ll j=1; j*i<=1001001;j++){
			diva[i*j]++;
		}
	}
}
ll pre[1001001]={0};
void preSum(){
	pre[1] = diva[1];
	for(ll i=2; i<1001001;i++){
		pre[i] = pre[i-1]+diva[i];
	}
}

void solve()
{
	ll l,r;
	cin>>l>>r;
	cout<<(pre[r]-pre[l-1])<<'\n';
}

void solve2(){
	
}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    preCompute();
    preSum();
 
    test(t)
    solve();
    
    
    
}