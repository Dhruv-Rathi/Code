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

void solve(){
	ll l,r; cin>>l>>r;
	
	while(l+3<=r){
		if((l^(l+1)^(l+2)^(l+3)) == 0){
			cout<<l<<' '<<(l+1)<<' '<<(l+2)<<' '<<(l+3)<<'\n';
			return;
		}
		else l++;
	}
	cout<<-1<<'\n';
}

void solve2(){
	ll n,x; cin>>n>>x;
	if(n%2 == 0){
		yes; return;
	}

	if(x%2){
		yes;
	}else
		no;
}

void solve3(){
	ll n; cin>>n;
	if(n == 2){
		cout<<0<<'\n'; return;
	}
	if(n%2 == 0){
		n/=2;
		if(n%2 == 0){
			cout<<((n-1)*(n+1)-1)<<'\n';
		}else{
			cout<<((n-2)*(n+2)-1)<<'\n';
		}
		return;
	}
	cout<<(n/2)*(n/2+1)-1<<'\n';
}

void solve4(){
	int n; cin>>n;
	vll a(n);
	cin>>a;
	ll sum = 0;
	ll x = 1;
	f(i,0,n){
		sum+=a[i];
		x = x&a[i];
	}
	// cout<<x<<'\n';
	if(x){
		yes;
		cout<<n<<'\n';
		f(i,1,n){
			cout<<i<<' '<<i<<'\n';
		}
		return;
	}
	if(sum==0){
		no; return;
	}
	if(n == 2){
		if(a[0]&a[1]){
			yes;
		}else{
			no;
		}
		return;
	}

	vll b(31,0);
	f(i,0,n){
		f(j,0,31){
			if(a[i]&(1LL<<j)) b[j]++;
		}
	}
	int f = 0;
	int ind;
	f(i,0,31){
		if(b[i]<=1){
			continue;
		}else{
			f = 1;
			ind = i;
			break;
		}
	}

	if(f == 0){ 
		no;
	}
	else{
		yes;

		vll v;
		// int n = v.size();
		f(i,0,n){
			if(a[i]&(1LL<<ind))
				v.push_back(i+1);
		}

		int ans_size = v.size();
		cout << ans_size << '\n';
		cout << 1 << " " << v[0] << '\n';
		f(i,1,ans_size-1){
			cout << v[i-1]+1 << " " << v[i] << '\n';
		}

		cout << v[ans_size-2]+1 <<" " << n << '\n';
		// cout<<v<<'\n';
	}
}


void solve5sol(){
	ll n; cin>>n;
	vll dp(n+1);
	vll c(n), a(n);
	cin>>c; cin>>a;
	frev(i,n-1,0){
		dp[i] = dp[i+1];
		if(c[i]&1){
			dp[i] = max(dp[i], a[i]-dp[i+1]);
		}
	}
	cout<<dp[0]<<'\n';
}

void solve6(){
	ll n; cin>>n;
	string s="";
	while(n){
		ll r = n%62;
		if(r<=25){
			s = (char)('a'+r)+s;
		}else if(r<=51){
			r = (r-26);
			s = (char)('A'+r)+s;
		}else{
			r = (r-52);
			s = (char)('0'+r)+s;
		}
		n/=62;
	}
	cout<<s<<'\n';
}

 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    solve6();
    
}