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
#define pb push_back
#define mp make_pair
#define S second
#define F first
#define all(a) a.begin(), a.end()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define yesorno(x) cout<<((x)?"YES":"NO")<<"\n"
#define test(t) int tc; cin>>tc; while(tc--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}

void solveA(){
	int n; cin>>n;
	int a[n]; int s = 0;
	f(i,0,n){
		cin>>a[i];
		s+=a[i];
	}

	f(i,0,n){
		s-=a[i];
		if(s%(n-1) == 0){
			int x = s/(n-1);
			if(x == a[i]){
				cout<<"YES\n"; return;
			}
		}
		s+=a[i];
	}
	cout<<"NO\n";
}

void solveB(){
	int n; cin>>n;
	int a[n];
	f(i,0,n){
		cin>>a[i];
	}
	int ans = 0;
	f(i,1,n){
		if(a[i]<a[i-1]){
			ans++; i++;
		}
	}
	cout<<ans<<'\n';
}

void solve3(){
	int n; cin>>n;
	vll a(n);
	f(i,0,n){
		cin>>a[i];
	}
	if(n%2){
		cout<<"NO\n"; return;
	}
	sort(all(a));
	vll ans;
	f(i,0,n/2){
		ans.pb(a[i]);
		ans.pb(a[i+n/2]);
	}
	if(!((ans[0]>ans[n-1] && ans[0]>ans[1])||(ans[0]<ans[n-1] && ans[0]<ans[1]))){
		cout<<"NO\n"; return;
	}
	f(i,1,n-1){
		if(!((ans[i]>ans[i-1] && ans[i]>ans[i+1])||(ans[i]<ans[i-1] && ans[i]<ans[i+1]))){
			cout<<"NO\n"; return; 
		}
	}
	if(!((ans[n-1]>ans[n-2] && ans[n-1]>ans[0])||(ans[n-1]<ans[n-2] && ans[n-1]<ans[0]))){
		cout<<"NO\n"; return;  
	}
	cout<<"YES\n";
	cout<<ans<<'\n';

}


ll a,b,c,d,n;
string s;
ll a1,b1,c1,d1;

ll dp[200200][5];

ll rec(ll i, ll x){
	if(i == n){
		if(a1 == a && b1 == b && c1 == c && d1 == d){
			return 1;
		}
		return 0;
	}
	// if(dp[i][x]!=-1) return dp[i][x];

	ll ans = 0;
	if(s[i] == 'A'){
		if((i+1)<n && s[i+1] == 'B'){
			c1++;
			ll x = rec(i+2,3);
			c1--;
			a1++;
			ll y = rec(i+1,1);
			a1--;
			ans = x|y;
		}else{
			a1++;
			ans = rec(i+1,1);
			a1--;
		}
	}else if(s[i]=='B'){
		if((i+1)<n && s[i+1] == 'A'){
			d1++;
			ll x = rec(i+2,4);
			d1--;
			b1++;
			ll y = rec(i+1,2);
			b1--;
			ans = x|y;
		}else{
			b1++;
			ans = rec(i+1,2);
			b1--;
		}
	}
	return ans;
}

void solveD(){
	cin>>a>>b>>c>>d;
	cin>>s;
	n = (a+b+2*c+2*d);

	a1 = b1 = c1 = d1 = 0;
	f(i,0,n){
		f(j,0,5){
			dp[i][j] = -1;
		}
	}
	if(rec(0,0)){
		cout<<"YES\n";
	}else{
		cout<<"NO\n";
	}
}

void solveD2(){
	ll a,b,c,d,n;
	cin>>a>>b>>c>>d;
	string s; cin>>s;
	if(count(all(s),'A')!=(a+c+d)){
		no; return;
	}

	n = a+b+2*c+2*d;

	s+=string(1,s[n-1]);
	string cur = string(1,s[0]);

	// cout<<s<<' '<<cur<<'\n';

	vll ab, ba;

	ll commonCnt = 0;
	f(i,1,n+1){
		if(s[i] == s[i-1]){
			if(cur.size()==1){

			}else if(cur.size()&1){
				commonCnt+=cur.size()/2;
			}else{
				if(cur[0] == 'A'){
					ab.pb(cur.size()/2);
				}else{
					ba.pb(cur.size()/2);
				}
			}
			cur = "";
		}
		cur.pb(s[i]);
	}

	sort(all(ab)); sort(all(ba));

	ll cntAB = 0, cntBA = 0;
	ll comCntleft = commonCnt;

	for(auto &x: ab){
		ll req = c-cntAB;
		if(req>=x){
			cntAB+=x;
			x = 0;
		}
		else{
			cntAB+=req;
			x-=req;
		}
	}

	for(auto &x: ba){
		ll req = d-cntBA;
		if(req>=x){
			cntBA+=x;
			x = 0;
		}
		else{
			cntBA+=req;
			x-=req;
		}
	}
	if(cntAB<c){
		ll req = c-cntAB;
		cntAB+=min(req, comCntleft);
		comCntleft -= min(req, comCntleft);

		req = c-cntAB;

		if(req>0){
			for(auto &x: ba){
				if(!x) continue;
				ll re = c-cntAB;
				if(re>=x-1){
					cntAB+=x-1;
					x = 0;
				}else{
					cntAB+=re;
					x-=re+1;
				}
			}
		}
	}

	if(cntBA<d){
		ll req = d-cntBA;
		cntBA+=min(req, comCntleft);
		comCntleft -= min(req, comCntleft);

		req = d-cntBA;

		if(req>0){
			for(auto &x: ab){
				if(!x) continue;
				ll re = d-cntBA;
				if(re>=x-1){
					cntBA+=x-1;
					x = 0;
				}else{
					cntBA+=re;
					x-=re+1;
				}
			}
		}
	}

	if(cntBA>=d && cntAB>=c){
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
    solveD2();
    
    
    
}
