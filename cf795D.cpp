#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef vector<int> vii;
typedef vector<vector<int>> vvii;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<pll>> vvpll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
#define mod 1000000007
#define mod2 998244353
#define f(x,a,b) for(int x=a;x<b;x++)
#define frev(x,a,b) for(int x=a;x>=b;x--)
#define PB push_back
#define MP make_pair
#define S second
#define F first
#define all(a) (a).begin(), (a).end()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define yesorno(x) cout<<((x)?"YES":"NO")<<"\n"
#define test(t) int tc; cin>>tc; while(tc--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <class T> ostream &operator<<(ostream &os, const vector<T> a){ for (auto ele : a) os << ele << " "; return os;} 
template <class T> istream &operator>>(istream &is, vector<T> &a){ for (auto &ele : a) is >> ele; return is; }


vii nextGreater(vll &arr, int n){
	stack<int> s;
	vii result(n,n);
	for(int i=0; i<n; i++){
		while(!s.empty() && arr[s.top()]<arr[i]){
			result[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	return result;
}

vii prevGreater(vll &arr, int n){
	stack<int> s;
	vii result(n,-1);
	for(int i=n-1; i>=0; i--){
		while(!s.empty() && arr[s.top()]<arr[i]){
			result[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	return result;
}

ll query(vector<ll> &t, int id, int l, int r, int lq, int rq){
	if(rq<l || lq>r) return -1e18;
	if(lq<=l && rq>=r){
		return t[id];
	}
	int mid = (l+r)/2;
	ll leftQ = query(t,id<<1,l,mid,lq,rq);
	ll rightQ = query(t,id<<1|1,mid+1,r,lq,rq);
	return max(leftQ, rightQ);
}

void solve(){
	int n, _n; cin>>n;
	vll arr(n,0);
	cin>>arr;
	
	_n = n;
	while(__builtin_popcount(_n)!=1) _n++;

	vll preSum(n,0), sufSum(n,0);
	preSum[0] = arr[0];
	for(int i=1;i<n;i++){
		preSum[i] = preSum[i-1]+arr[i];
	}
	sufSum[n-1] = arr[n-1];
	for(int i=n-2;i>=0;i--){
		sufSum[i] = sufSum[i+1]+arr[i];
	}

	vll preTree(2*_n, -1e18), sufTree(2*_n, -1e18);

	f(i,0,n){
		preTree[_n+i] = preSum[i];
		sufTree[_n+i] = sufSum[i];
	}
	frev(i,_n-1,1){
		preTree[i] = max(preTree[i<<1], preTree[i<<1|1]);
		sufTree[i] = max(sufTree[i<<1], sufTree[i<<1|1]);
	}
	vii ng = nextGreater(arr,n);
	vii pg = prevGreater(arr,n);
	bool flag = true;

	f(i,0,n){
		ll rMax = query(preTree, 1,0,_n-1,i+1,ng[i]-1) - preSum[i];
		ll lMax = query(sufTree, 1,0,_n-1,pg[i]+1,i-1) - sufSum[i];
		if(max(lMax, rMax)>0){
			flag = false;
			break;
		}
	}
	if(flag){
		yes;
	}else{
		no;
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