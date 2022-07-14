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
#define pb push_back
#define mp make_pair
#define S second
#define F first
#define all(a) (a).begin(), (a).end()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define yesorno(x) cout<<((x)?"YES":"NO")<<"\n"
#define test(t) int tc; cin>>tc; while(tc--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}


void solve(){
	int n; cin>>n;
	vll a(n);
	ll o = 0, e = 0;
	f(i,0,n){
		cin>>a[i];
		if(a[i]%2){
			o++;
		}else e++;
	}
	if(o<e){
		cout<<o<<'\n';
	}else cout<<e<<'\n';

}

void solve2(){
	ll n; cin>>n;
	vpll a(n);
	map<ll,ll> m; ll dis = 0;
	f(i,0,n){
		ll s;
		cin>>s;
		a[i].F = s;
		a[i].S = i+1;
		if(m[s] == 0){
			dis++;
		}
		m[s]++;
	}
	sort(all(a));
	if(n == 1){
		cout<<-1<<'\n'; return;
	}
	vll ans(n);
	f(i,0,n){
		ans[i] = i+1;
	}

	for(ll i=0;i<n-1;i++){

		if(a[i].F == a[i+1].F){
			swap(ans[i],ans[i+1]);
		}else{
			if(ans[i] == i+1){
				cout<<-1<<'\n';
				return;
			}
		}
	}
	if(ans[n-1] == n){
		cout<<-1<<'\n'; return;
	}
	cout<<ans<<'\n';
}

void solve3(){
	ll n,k; 
	cin>>n>>k;
	string s;
	cin>>s;
	ll ans = 0,cnt = 0, R = 0, L = 0;
	f(i,0,s.length()-1){
		if(s[i]=='1' && s[i+1] == '1'){
			ans+=11;
		}else if(s[i] == '1'){
			ans+=10;
		}else if(s[i+1] == '1'){
			ans+=1;
		}
	}
	f(i,0,n){
		if(s[i] == '1'){
			cnt++;
		}
	}
	if(cnt == 0){
		cout<<0<<'\n'; return;
	}
	ll i = n-1;
	while(s[i] == '0' && i>=0){
		i--;
		R++;
	}
	while(s[L] == '0' && L<n){
		L++;
	}

	if(L && R && (L+R)<=k && cnt>1){
		ans = ans-11;
	}else if(R && R<=k){
		ans = ans-10+!(L||cnt>1);
	}else if(L && L<=k && (R||cnt>1)){
		ans = ans-1;
	}
	
	cout<<ans<<'\n';
	


}

void solve31(){
	ll n,k; 
	cin>>n>>k;
	string s;
	cin>>s;

	ll ans = 0;
	ll prev = n-1, prev1 = 0;
	for(ll i =n-1;i>=0;i--){
		if(s[i] == '1'){
			// cout<<i<<' '<<prev<<' '<<prev1<<' '<<k<<'\n';
			// cout<<s<<'\n';
			if(prev-i>k){
				if(i-prev1>k)
					break;
				else if(i>prev1){
					swap(s[i],s[prev1]);
					k-=(i-prev1);
					prev1++;
				}
				// break;
			}else{
				// cout<<i<<' '<<prev<<'\n';
				swap(s[i],s[prev]);
				k-=(prev-i);
				prev--;
				
			}
		}
	}
	// cout<<s<<'\n';
	f(i,0,s.length()-1){
		if(s[i]=='1' && s[i+1] == '1'){
			ans+=11;
		}else if(s[i] == '1'){
			ans+=10;
		}else if(s[i+1] == '1'){
			ans+=1;
		}
	}
	cout<<ans<<'\n';
}


void solve4(){
	ll n; cin>>n;
	ll arr[n];
	ll pre[n] = {0};
	f(i,0,n){
		cin>>arr[i];
	}
	pre[0] = arr[0];
	f(i,1,n){
		pre[i] = pre[i-1]+arr[i];
	}
	// f(i,0,n) cout<<pre[i]<<' ';
	// cout<<'\n';

	// ll tail = 0, head = -1;
	// while(tail<n){
	// 	while(head+1<n && ())
	// }
	ll ma = arr[0];
	f(i,1,n){
		ma = max(ma,arr[i]);
		if(ma<pre[i]){
			cout<<"NO\n"; return;
		}
	}
	cout<<"YES\n";
}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    test(t)
    solve3();
    
    
    
}