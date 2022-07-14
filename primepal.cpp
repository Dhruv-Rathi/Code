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


bool isPrime(ll x){
    if(x%2==0) return 0;
    for(ll i=3;i*i<=x;i+=2){
        if(x%i == 0) return 0;
    }
    return 1;
}

ll a,b,len,temp;
ll ans = 0;

void rec(ll level, ll req){
	if(level == (req+1)/2){
		string s1 = to_string(temp);
		string s2 = s1;
		if(req%2){
			s2.pop_back();
		}
		reverse(all(s2));
		s1+=s2;
		ll num = stoll(s1);
		if(num<a || num>b) return;
		if(isPrime(num)) ans++;
		return;
	}

	for(int i=0;i<=9;i++){
		if(level == 0 && i == 0) continue;
		temp*=10;
		temp+=i;
		rec(level+1,req);
		temp/=10;
	}
}

void solve(){
	cin>>a>>b;

	string st = to_string(b);
	len = st.size();
	for(ll i=1;i<=len;i++){
		rec(0,i);
	}
	cout<<ans<<'\n';
}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    // test(t)
    solve();
    
    
    
}