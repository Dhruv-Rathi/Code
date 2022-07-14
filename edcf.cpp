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
	vi a(n), b(n);
	f(i,0,n){
		cin>>a[i];
	}
	f(i,0,n) cin>>b[i];

	for(int i=n-2;i>=0;i--){
		if((abs(a[i]-a[i+1])+abs(b[i]-b[i+1])) > (abs(b[i]-a[i+1])+abs(a[i]-b[i+1]))){
			swap(a[i], b[i]);
		}
	}
	ll ans = 0;
	for(int i=0;i<n-1;i++){
		ans+=abs(a[i]-a[i+1]);
		ans+=abs(b[i]-b[i+1]);
	}

	cout<<ans<<'\n';
}

void solve2(){
	ll n; cin>>n;
	ll m = 32768;

	f(i,0,n){
		ll x, ans = 0; cin>>x;

		ll y = x, d = 0;
		if(x%2) {
			y = (x+1)%m;
			ans++;
		}
		if(y%m==0){
			cout<<ans<<' ';
			continue;
		}
		while(y%m){
			y=(y*2)%m;
			ans++;
		}
		
		ll z = x/m;
		ll ans2 = m*(z+1)-x;
		ans = min(ans, ans2);
		cout<<ans<<' ';
	}

}

void solve3() {
	ll n; cin>>n;
	ll h[n];
	f(i,0,n){
		cin>>h[i];
	}
	sort(h, h+n);

}

void solve5(){
	vector<pair<int,int>> l;
	string s;
	for(int i=0;i<4;i++){
		getline(cin, s);
		l.pb(make_pair(s.length()-2, i));
	}
	sort(all(l));
	// f(i,0,4){
	// 	cout<<l[i].ff<<' '<<l[i].ss<<'\n';
	// }
	if(2*l[0].ff<=l[1].ff && l[3].ff>=2*l[2].ff){
		cout<<"C";
		return;
	}
	if(2*l[0].ff<=l[1].ff){
		cout<<char('A'+l[0].ss);
		return;
	}
	if(l[3].ff>=2*l[2].ff){
		cout<<char('A'+l[3].ss);
		return;
	}
	cout<<"C";

}

void solve4(){
	int n; cin>>n;
	string p;
	int cnt = 0;
	f(i,0,n){
		int x; cin>>x;
		if(x == 0){
			cout<<"0";
			return;
		}
		while(x){
			if(x%10 == 0){
				cnt++;
			}
			else if(x/10 == 0 && x!=1){
				p+=to_string(x);
				break;
			}
			else if(x/10 > 0){
				p+=to_string(x);
				break;
			}
			x/=10;
		}

	}
	f(i,0,cnt){
		p+="0";
	}
	cout<<p;
}

void solve6(){
	int n; cin>>n;
	string p;
	int flag = 0, cnt = 0;
	f(i,0,n){
		string x; cin>>x;
		if(x == "0"){
			cout<<0;
			return;
		}
		if(flag == 0){
			int cnt = 0;
			f(j,0,x.length()){
				if(x[j]!='0' && x[j]!='1'){
					p = x;
					flag = 1;
					break;
				}
				if(x[j] == '1'){
					cnt++;
					if(cnt>1){
						p = x;
						flag = 1;
						break;
					}
				}
			}
		}
		if(flag == 1){
			flag = 2;
			continue;
		}

		cnt+=x.length() - 1;
	}
	if(flag == 0){
		p = "1";
	}
	for(int i=0;i<cnt;i++)
		p+="0";

	cout<<p;
}

signed main()
{
    fast
    

 
    // test(t)
    solve6();
    
    
    
}