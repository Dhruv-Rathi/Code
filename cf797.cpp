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
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <class T> ostream &operator<<(ostream &os, const vector<T> a){ for (auto ele : a) os << ele << " "; return os;} 
template <class T> istream &operator>>(istream &is, vector<T> &a){ for (auto &ele : a) is >> ele; return is; }

void solve(){
	int n; cin>>n;
	int x = n/3;
	int y = n%3;
	if(n%3 == 2){
		cout<<(x+1)<<' '<<(x+2)<<' '<<(n-2*x-3)<<'\n';
	}else if(n%3 == 1){
		cout<<(x)<<' '<<(x+2)<<' '<<(n-2*x-2)<<'\n';
	}
	else{
		cout<<(x)<<' '<<(x+1)<<' '<<(x-1)<<'\n';
	}
}

void solve2(){
	int n; cin>>n;
	vll a(n);
	cin>>a;
	vll b(n);
	cin>>b;
	bool f = 1;
	ll x = (a[0]-b[0]);
	if(x<0){
		no; return;
	}
	vll c(n);
	c[0] = x;
	f(i,1,n){
		c[i] = a[i]-b[i];
		if(c[i]<0){
			no; return;
		}
	}

	ll cnt = 0, pos = -1;
	if(b[0] != 0) {
		cnt=1; pos = 0;
	}
	f(i,1,n){
		if(cnt && b[i]!=0 && c[i]!=c[pos]){
			no; return;
		}else if(cnt == 0 && b[i]!=0){
			cnt = 1; pos = i;
		}else if(cnt && b[0] == 0 && c[i]>c[pos]){
			no; return;
		}
	}
	if(cnt){
		ll z;
		f(i,0,n){
			if(b[i]!=0){
				z = c[i]; break;
			}
		}
		f(i,0,n){
			if(b[i] == 0){
				if(c[i]>z){
					no; return;
				}
			}
		}
		f(i,0,n){
			if(b[i]!=0){
				if(c[i]!=z){
					no; return;
				}
			}
		}
	}
	yes;
	
}

void solve3(){
	int n; cin>>n;
	vll s(n); cin>>s;
	vll fr(n); cin>>fr;
	cout<<(fr[0]-s[0])<<' ';
	f(i,1,n){
		if(s[i]>fr[i-1]){
			cout<<fr[i]-s[i]<<' ';
		}else{
			cout<<(fr[i]-fr[i-1])<<' ';
		}
	}
	cout<<'\n';
}

void solve4(){
	ll n,k; cin>>n>>k;
	string s; cin>>s;
	ll i=0, j=0;
	ll cntB = 0;
	for(i=0;i<k;i++){	
		if(s[i] == 'B') cntB++;
	}
	ll ans = (k-cntB);
	while(i<n){
		if(s[j] == 'B') cntB--;
		j++; 
		if(s[i]=='B') cntB++;
		i++;
		// cout<<i<<' '<<j<<' '<<cntB<<'\n';
		ans = min(ans, (k-cntB));
	}
	cout<<ans<<'\n';
}

void solve5(){
	int n,k; cin>>n>>k;
	vll a(n);
	ll ans = 0;
	f(i,0,n){
		cin>>a[i];
		ans+=(a[i]/k);
		a[i]%=k;
	}
	sort(all(a)); reverse(all(a));
	ll i,j;
	for(i=0,j=n-1;i<j;i++){
		while(j>i && a[i]+a[j]<k)
			j--;
		if(j>i) ans++;
		j--;
	}
	cout<<ans<<'\n';
}

void solve6(){
	ll n; cin>>n;
	string s; cin>>s;
	vll p(n);
	cin>>p;

	string sn = "";
	f(i,0,n){
		sn+=s[p[i]-1];
	}
	ll ans = 1;
	while(sn!=s){
		string t="";
		f(i,0,n){
			t+=sn[p[i]-1];
		}
		sn = t;
		ans++;
	}cout<<ans<<'\n';
}
 
signed main()

{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    test(t)
    solve5();
    
}