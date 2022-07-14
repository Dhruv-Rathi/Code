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


ll power(ll a, ll b, ll N){ ll p = 1;
    while (b > 0){
        if (b & 1) p = ((p % N) * (a % N)) % N;
        a = ((a % N) * (a % N)) % N; b /= 2;
    } return p;
}



void solve(){
	int q; cin>>q;
	ll sum = 0, cnt = 0;
	set<pll> st; map<ll,ll> m;
	multiset<ll> lo, hi;

	while(q--){
		string s;
		cin>>s;
		if(s == "insert"){
			ll x; cin>>x;
			if(m.find(x)!=m.end()){
				st.erase(mp(m[x],x));
			}
			m[x]++;
			st.insert(mp(m[x],x));
			sum=((sum%mod)+(x%mod))%mod;
			cnt++;
			bool f = 1;
			if(!lo.empty()){
				auto v = lo.end(); v--;
				if(x<=*v) {lo.insert(x); f=0;}
			}
			if(!hi.empty() && (f)){
				auto v= hi.begin();
				if(x>=*v){hi.insert(x); f=0;}
			}
			if(f)
				lo.insert(x);

			while(lo.size()>=hi.size()+2){
				auto it = lo.end(); it--;
				ll val = *it; lo.erase(it);
				hi.insert(val);
			}
			while(hi.size()>lo.size()){
				auto it = hi.begin();
				ll val = *it; hi.erase(it);
				lo.insert(val);
			}

		}else if(s == "remove"){
			ll x; cin>>x;
			if(m.find(x)!=m.end()){
				st.erase(mp(m[x],x));
				m[x]--;
				if(m[x] == 0){
					m.erase(x);
				}else{
					st.insert(mp(m[x],x));
				}
			}
			sum = ((sum%mod)  - (x%mod) + mod)%mod;
			cnt--;
			bool f = 1;
			if(!lo.empty()){
				auto v = lo.end(); v--;
				if(x<=*v) {lo.erase(lo.find(x)); f=0; }
			}
			if(!hi.empty() && (f)){
				auto v= hi.begin();
				if(x>=*v){hi.erase(hi.find(x)); }
			}
			while(lo.size()>=hi.size()+2){
				auto it = lo.end(); it--;
				ll val = *it; lo.erase(it);
				hi.insert(val);
			}
			while(hi.size()>lo.size()){
				auto it = hi.begin();
				ll val = *it; hi.erase(it);
				lo.insert(val);
			}

		}else if(s == "getMean"){
            if(cnt == 0){
                cout<<-1<<'\n'; continue;
            }
			ll mean = ((sum%mod)*power(cnt,mod-2,mod)%mod)%mod;

			cout<<(mean+mod)%mod<<'\n';
		}else if(s == "getMedian"){
            if(cnt == 0){
                cout<<-1<<'\n'; continue;
            }
			if(cnt%2){
				auto it = lo.end(); it--;
                ll med = *it;
				cout<<med<<'\n'; 
			}else{
				auto it = lo.end(); it--;
				ll x = *it;
				it = hi.begin();
				ll y = *it;
				ll med = ((x%mod)+(y%mod))%mod;
				med =  ((med%mod)*(power(2,mod-2,mod)%mod))%mod;
				cout<<(med+mod)%mod<<'\n';
			}
		}else{
            if(cnt == 0){
                cout<<-1<<'\n'; continue;
            }
			auto it = st.end(); it--;
			ll modefreq = it->F;
			it = st.lower_bound(mp(modefreq,-1e18));
            ll mode = it->S;
			cout<<mode<<'\n';
		}
	}
}

class TopK {
private:
	multiset<int> m1,m2;
	ll sum;
	int k;
public:
	TopK(int k){
		this->k = k;
		sum = 0LL;
	}

	void add(int x){
		m1.insert(x);
		sum+=x;
		if((int)m1.size()>k){
			int y = *(m1.begin());
			m1.erase(m1.find(y));
			sum-=y;
			m2.insert(y);
		}
		return;
	}

	void remove(int x){
		if(m2.find(x)!=m2.end()){
			m2.erase(m2.find(x));
		}
		else if(m1.find(x)!=m1.end()){
			sum-=x;
			m1.erase(m1.find(x));
			if(m2.empty()) return;
			int y = *(m2.rbegin());
			sum+=y;
			m1.insert(y);
			m2.erase(m2.find(y));
		}
		return;
	}

	ll getsum() {
		return sum;
	}
};

void solve2(){
	int q,k; cin>>q>>k;
	TopK T(k);
	while(q--){
		int ch; cin>>ch;
		if(ch == 1){
			int x; cin>>x;
			T.add(x);
		}else if(ch == 2){
			int x; cin>>x;
			T.remove(x);
		}else{
			char c; cin>>c;
			cout<<T.getsum()<<'\n';
		}
	}
}

void solve3(){
	int n; cin>>n;
	int a[n];
	int freq[100100] = {0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans = 0, cnt = 0;
	for(int i=0;i<n;i++){
		freq[a[i]]++;
		if(a[i]>ans) cnt++;

		if(cnt>ans) {
			ans++;
			cnt-=freq[ans];
		}

		cout<<ans<<' ';
	}
	cout<<'\n';
}


void solve4(){
	ll n,k; cin>>n>>k;
	vll a(n);map<ll,ll> m;
	f(i,0,n){
		cin>>a[i];
		m[a[i]]++;
	}

	if(k>n){
		cout<<n*(n-1)/2<<'\n'; return;
	}
    priority_queue<pll> q;
	ll ans = n*(n-1)/2;
    
    for(auto it: m){
        if(it.S>1){
            q.push({it.S,it.F});
            ans-= it.S*(it.S-1)/2;
        }
    }
    
    f(i,0,k){
        if(q.empty()) break;
        auto it = q.top();
        q.pop();
        ans+=it.F-1;
        it.F--;
        if(it.F>1) q.push(it);
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
    
    test(t)
    solve4();
   
}