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

void solve2(){
	int n; cin>>n;
	vll a(n);
	int o = 0, e = 0;
	vll ev;
	f(i,0,n){
		cin>>a[i];
		if(a[i]%2) o++;
		else ev.PB(a[i]);
	}
	e = (n-o);
	if(e == 0){
		cout<<0<<'\n'; return;
	}
	if(e<=o){
		cout<<(e)<<'\n'; return;
	}
	if(o){
		cout<<e<<'\n'; return;
	}
	ll ans = 1e18;
	sort(all(ev));
	f(i,0,n){
		ll cnt = 0;
		f(j,0,31){
			if(ev[i]&(1<<j)){
				cnt = j; break;
			}
		}
		ans = min(ans,cnt);
	}
	ans+=(n-1);
	cout<<ans<<'\n';
}

void solve3(){
	int n; cin>>n;
	string s;
	map<char, ll> m;
	f(i,0,2*n){
		string t;
		cin>>t;
		s+=t;
	}
	string t; cin>>t;
	s+=t;
	f(i,0,s.length()){
		m[s[i]]++;
	}
	f(i,0,26){
		if(m[(char)('a'+i)]%2){
			cout<<((char)('a'+i))<<'\n'; return;
		}
	}
	

}

#define int long long

int maxSum(vll &arr, int n, int k)
{
   
 
    // Compute sum of first window of size k
    int res = 0;
    for (int i=0; i<k; i++)
       res += arr[i];
 
    // Compute sums of remaining windows by
    // removing first element of previous
    // window and adding last element of
    // current window.
    int curr_sum = res;
    for (int i=k; i<n; i++)
    {
       curr_sum += arr[i] - arr[i-k];
       res = max(res, curr_sum);
    }
 
    return res;
}


void solve4(){
	int n; ll k;
	cin>>n>>k;
	vll a(n);
	cin>>a;
	if(k<=n){
		ll ans = maxSum(a,n,k);
		
		ans+=(k-1)*k/2;
		cout<<ans<<'\n'; return;
	}
	ll sum = 0;
	f(i,0,n){
		sum+=a[i];
	}
	sum+=(n*(n-1))/2;
	sum+=(k-n)*n;
	cout<<sum<<'\n';
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