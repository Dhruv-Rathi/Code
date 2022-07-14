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

// Fenwick tree acts as a dynamic prefix sum.
// Fenwick tree is always 1 index.
// Least significant one.

#define LSOne(i) (i&(-i))
struct Fen{
	vector<ll> ft;
	Fen(ll i=0){ft.assign(i+2,0);}
	ll rsq(ll b){b++;
		int sumer=0;
		for(;b>0;b-=LSOne(b))sumer+=ft[b];
		return sumer;
	}
	int rsq(int l, int r){
		return rsq(r)-rsq(l-1);
	}
	void addat(int k, int v){k++;
		for(;k<(ll)ft.size();k+=LSOne(k)) ft[k]+=v;
	}
};



void solve(){
	int n, u; cin>>n>>u;
	Fen F(n+10);

	for(int i=0;i<u;i++){
		int l, r, val;
		cin>>l>>r>>val;
		l++; r++;
		F.addat(l,val);
		F.addat(r+1,-val);
	}

	int q; cin>>q;
	while(q--){
		int w; cin>>w; w++;
		cout<<F.rsq(w)<<'\n';
	}
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