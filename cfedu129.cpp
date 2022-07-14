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


void solve(){
	int n; cin>>n;
	vii a(n);
	f(i,0,n){
		cin>>a[i];

	}
	int m; cin>>m;
	vii b(m);
	f(i,0,m){
		cin>>b[i];
	}
	sort(all(a));
	reverse(all(a));
	sort(all(b));
	reverse(all(b));
	// cout<<a<<'\n'<<b<<'\n';
	if(a[0]>=b[0]){
		cout<<"Alice";
	}else{
		cout<<"Bob";
	}cout<<'\n';
	if(b[0]>=a[0]){
		cout<<"Bob";
	}else{
		cout<<"Alice";
	}cout<<'\n';
}	

void solve2(){
	ll n; cin>>n;
	vll a(n);
	f(i,0,n){
		cin>>a[i];
	}
	ll m; cin>>m;
	ll sum = 0;
	vll b(m);
	f(i,0,m){
		cin>>b[i];
		sum+=b[i];
	}

	cout<<a[sum%n]<<'\n';


}

void solve3(){
	int n; cin>>n;
	vii a(n), b(n);
	f(i,0,n){
		cin>>a[i];
	}
	f(i,0,n){
		cin>>b[i];
	}
	vii c = a, d = b;
	vii a1 = a, b1 = b;
	sort(all(c));
	sort(all(d));
	if(a==c && b==d){
		cout<<0<<'\n'; return;
	}
	int cnt1=0, cnt2=0;
	vpii p1; vpii p2;
	f(i,0,n){
		if(a[i]!=c[i]){
			f(j,i+1,n){
				if(c[i] == a[j] && a[i] == c[j]){
					p1.pb({i,j});
					cnt1++;
				}
			}
			
		}
	}
	// cout<<cnt1<<' '<<cnt2<<'\n';
	// cout<<p1.size()<<' '<<p2.size()<<'\n';
	int ans = 0;
	vpii p;
	f(i,0,cnt1){
		// cout<<p1[i].F<<' '<<p1[i].S<<'\n';

		swap(b[p1[i].F], b[p1[i].S]);
		p.pb({p1[i].F, p1[i].S});
		ans++;
	}
	a = c;
	f(i,0,n){
		if(b[i]!=d[i]){
			f(j,i+1,n){
				if(d[i] == b[j] && b[i] == d[j]){
					p2.pb({i,j});
					cnt2++;
				}
			}
			
		}
	}

	f(i,0,cnt2){
		swap(a[p2[i].F], a[p2[i].S]);
		p.pb({p2[i].F, p2[i].S});
		ans++;
	}

	if(a!=c){
		p1.clear(); p2.clear(); p.clear();
		cnt1=0; cnt2=0;ans =0;
		f(i,0,n){
			if(b1[i]!=d[i]){
				f(j,i+1,n){
					if(d[i] == b1[j] && b1[i] == d[j]){
						p2.pb({i,j});
						cnt2++;
					}
				}
			}
		}
		f(i,0,cnt2){
			swap(a1[p2[i].F], a1[p2[i].S]);
			p.pb({p2[i].F, p2[i].S});
			ans++;
		}

		f(i,0,n){
			if(a1[i]!=c[i]){
				f(j,i+1,n){
					if(c[i] == a1[j] && a1[i] == c[j]){
						p1.pb({i,j});
						cnt1++;
					}
				}
				
			}
		}

		f(i,0,cnt1){
			swap(b1[p1[i].F], b1[p1[i].S]);
			p.pb({p1[i].F, p1[i].S});
			ans++;
		}
		if(b1!=d)
			cout<<-1<<'\n';
		else{
			cout<<ans<<'\n';
			f(i,0,ans){
				cout<<(p[i].F+1)<<' '<<(p[i].S+1)<<'\n';
			}
		}

	}else{
		cout<<ans<<'\n';
		f(i,0,ans){
			cout<<(p[i].F+1)<<' '<<(p[i].S+1)<<'\n';
		}
	}
	
	
}

void solve31(){
	int n; cin>>n;
	vii a(n), b(n);
	f(i,0,n){
		cin>>a[i];
	}
	f(i,0,n){
		cin>>b[i];
	}
	vii c = a, d = b;
	sort(all(c));
	sort(all(d));
	if(a==c && b==d){
		cout<<0<<'\n'; return;
	}
	int ans = 0;
	vpii p1,p2,p;
	while(ans<=10000){
		p1.clear(); p2.clear();
		int cnt1=0, cnt2=0;
		f(i,0,n){
			if(a[i]!=c[i]){
				f(j,i+1,n){
					if(c[i] == a[j] && a[i] == c[j]){
						p1.pb({i,j});
						cnt1++;
					}
				}
				
			}
		}
		
		f(i,0,cnt1){
			swap(b[p1[i].F], b[p1[i].S]);
			swap(a[p1[i].F], a[p1[i].S]);
			p.pb({p1[i].F, p1[i].S});
			ans++;
		}

		f(i,0,n){
			if(b[i]!=d[i]){
				f(j,i+1,n){
					if(d[i] == b[j] && b[i] == d[j]){
						p2.pb({i,j});
						cnt2++;
					}
				}
				
			}
		}

		f(i,0,cnt2){
			swap(a[p2[i].F], a[p2[i].S]);
			swap(b[p2[i].F], b[p2[i].S]);
			p.pb({p2[i].F, p2[i].S});
			ans++;
		}

		if(a == c && b == d){
			cout<<ans<<'\n';
			f(i,0,ans){
				cout<<(p[i].F+1)<<' '<<(p[i].S+1)<<'\n';
			}
			return;
		}
	}

	cout<<-1<<'\n';
}


void solveC(){
	int n; cin>>n;
	map<int, int> mp;
	vii a(n), b(n);
	f(i,0,n){
		cin>>a[i]; mp[a[i]]++;
	}
	f(i,0,n){
		cin>>b[i];
	}

	vpii v;
	f(i,0,n){
		v.pb({a[i],b[i]});
	}
	sort(all(v));
	vpii ans;
	f(i,0,n){
		if(a[i] == v[i].F && b[i] == v[i].S){}
		else{
			for(int j=i+1;j<n;j++){
				if(a[j] == v[i].F && b[j] == v[i].S){
					swap(a[i],a[j]);
					swap(b[i],b[j]);
					ans.pb({i,j});
				}
			}

		}
	}

	f(i,1,n){
		if(v[i].F>=v[i-1].F && v[i].S>=v[i-1].S){

		}else{cout<<-1<<'\n'; return;}
	}

	cout<<ans.size()<<'\n';
	for(auto x: ans){
		cout<<(x.F+1)<<' '<<(x.S+1)<<'\n';
	}

}

void solveD(){
	ll n,x; cin>>n>>x;
	queue<pll> q;
	q.push({x,0});
	map<ll,ll> mp;
	mp[x] = 1;
	while(!q.empty()){
		pll cur = q.front();
		// cout<<cur.F<<' '<<cur.S<<'\n';
		q.pop();
		ll cnt = 0;
		ll m = cur.F;
		while(cur.F){
			ll d = cur.F%10;
			if(!mp[m*d]){
				mp[m*d] = 1;
				q.push({m*d,cur.S+1}); 
			}
			cur.F/=10;
			cnt++;
		}
		if(cnt == n){
			cout<<cur.S<<'\n'; return;
		}
	}

	cout<<-1<<'\n';
}

signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    // test(t)
    solveD();
    
    
    
}