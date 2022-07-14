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
 

 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  

#define int ll
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
	ll n; cin>>n;
	if((n%2)||(n<4)){
		cout<<-1<<'\n'; return;
	}
	if((n%6 == 0)&&(n%4 == 0)){
		cout<<(n/6)<<' '<<(n/4)<<'\n'; return;
	}

	ll mi,ma = n/4;
	if(n%6 == 0) mi = n/6;
	else mi = n/6+1;
	cout<<mi<<' '<<ma<<'\n';

}

void solve2(){
	ll n,q; cin>>n>>q;
	ll a[n]; ll sum = 0;
	f(i,0,n){
		cin>>a[i];
		sum+=a[i];
	}
	
	ll f = 0;	

	vll arr;
	map<ll,ll> m;

	while(q--){
		int t; cin>>t;
		if(t == 1){
			ll i,x; cin>>i>>x;
			if(f == 0)
			{
				sum-=a[i-1];
				a[i-1] = x;
				sum+=x;
			}
			else{
				if(m[i]==0){
					sum-=f;
					a[i-1] = x;
					// cout<<sum<<' '<<x;
					sum+=x;
					m[i]++;
				}else if(m[i]){
					sum-=a[i-1];
					a[i-1] = x;
					sum+=x;
				}
			}
		}
		else{
			m.clear();
			ll x; cin>>x;
			f = x;
			sum = n*x;
		}

		cout<<sum<<'\n';
	}

}

void solve3(){
    
	int n, q;
	cin>>n>>q;
	vll row(n+1,0), col(n+1,0);
	ordered_set r;
	ordered_set c;

	while(q--){
		int t; cin>>t;

		if(t == 1){
			int x,y; cin>>x>>y;
			row[x]++;
			col[y]++;
			r.insert(x);
			c.insert(y);
		}else if(t ==2){
			int x,y; cin>>x>>y;
			row[x]--;
			col[y]--;

			if(row[x] == 0){
				r.erase(r.find(x));
			}
			if(col[y] == 0){
				c.erase(c.find(y));
			}
		}else{
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			bool f1=0, f2=0;
			int p1=r.order_of_key(x1);
			int p2=r.order_of_key(x2);
			if(x1 == *(r.find_by_order(p1)) && x2 == *(r.find_by_order(p2))){
				if(x2-x1 == p2-p1){
					f1=1;
				}
			}
			if(!f1){
				int p1 = c.order_of_key(y1);
				int p2 = c.order_of_key(y2);
				if(y1 == *(c.find_by_order(p1))&& y2 == *(c.find_by_order(p2))){
					if(y2-y1 == p2-p1){
						f2 = 1;
					}
				}
			}

			if(f1 || f2){
				cout<<"Yes\n";
			}
			else{
				cout<<"No\n";
			}

			// int f = 1;
			// for(int i=x1;i<=x2;i++){
			// 	for(int j=y1;j<=y2;j++){
			// 		if(m1[i]==0 && m2[j]==0){
			// 			cout<<"NO\n";
			// 			f = 0;i = x2+1; break;
			// 		}
			// 	}
			// }

			// if(f) cout<<"YES\n";
		}
	}
}

void solve4(){
	// Finding Indivifual contribution of each element in the 
	// final total sum of min. of all subarrays.
	int n; cin>>n;
	vll a(n);
	vll b; b.pb(-1e18);
	stack<ll> s;
	f(i,0,n){
		cin>>a[i];
		b.pb(a[i]);
	}
	b.pb(-1e18);

	ll prev[n+2], next[n+2];

	ll ans = 0;

	s.push(0);
	f(i,1,n+1){
		while(!s.empty() && b[s.top()]>=b[i]){
			s.pop();
		}
		prev[i] = s.top();
		s.push(i);
	}
	while(!s.empty()) s.pop();

	s.push(n+1);
	for(int i=n;i>=1;i--){
		while(!s.empty() && b[s.top()]>=b[i]){
			s.pop();
		}
		next[i] = s.top();
		s.push(i);
	}

	f(i,1,n+1){
		ans+=1LL*(b[i])*(i-prev[i])*(next[i]-i);
	}

	cout<<ans<<'\n';

}

ll sum;

void solve5(){
	ll n,k; cin>>n>>k;
	f(i,0,n){
		ll x;
		cin>>x;
		// cout<<x<<' ';
	}
	sum+=n;
	// if(sum>1e6){
	// 	return;
	// }
	// cout<<n<<'\n';
}
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    int tc; cin>>tc;
    cout<<tc<<'\n';
    while(tc--)
    solve5();
    cout<<sum<<'\n';
    
    
}