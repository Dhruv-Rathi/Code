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
	int n; cin>>n;
	ll h[n];
	ll sum = 0, f=0;
	f(i,0,n) {
		cin>>h[i];
		sum+=h[i];
		if(sum<(i*(i+1)/2)){
			f = 1;
		}
	}

	if(f){
		cout<<"NO\n";
	}
	else{
		cout<<"YES\n";
	}

}

void solve2(){
	int x = 0, y = 0, z = 0;
	int n; cin>>n;
	f(i,0,n){
		int a,b,c;
		cin>>a>>b>>c;
		x+=a; y+=b; z+=c;
	}
	if(x!=0 || y!=0 || z!=0){
		cout<<"NO\n";
	}
	else{
		cout<<"YES\n";
	}
}
 
signed main()
{
    fast
    
 
    // test(t)
    solve2();
    
    
    
}