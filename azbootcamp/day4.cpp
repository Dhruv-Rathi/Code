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
	int n,x; cin>>n>>x;
	vii a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int lo = upper_bound(all(a),x-1)-a.begin();
    int hi = upper_bound(all(a),x)-a.begin();
    hi--;
    if(hi<0 || a[hi]!=x){
        cout<<-1<<'\n';
    }else{
        cout<<(lo+1)<<' '<<(hi+1)<<'\n';
    }
}

void solve2(){
	int n,m; cin>>n>>m;
	vii a(n), b(m);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	int i=0, j=0;
	vii ans;
	while(i<n && j<m){
		if(a[i]<b[j]){
			ans.pb(a[i]);
			i++; 
		}else{
			ans.pb(b[j]);
			j++; 
		}
	}
	while(i<n){
		ans.pb(a[i]);
		i++;
	}
	while(j<m){
		ans.pb(b[j]);
		j++;
	}
	// for(auto i: ans){
	// 	cout<<i<<' ';
	// }
	// cout<<'\n';

	int p = ans.size();
	if(p%2){
		cout<<ans[p/2];
	}
	else{
		int med = (ans[p/2]+ans[p/2 -1])/2;
		cout<<med;
	}cout<<'\n';
}

void solve3(){
	set<pll> st;
	int n; cin>>n;
	while(n--){
		ll l,r; cin>>l>>r;
		auto it = st.upper_bound({l,1e9});
		if(it!=st.begin()){
			it--;
			if(it->S>=l){
				l = it->F;
				r = max(r, it->S);
				st.erase(it);
			}
		}

		it = st.upper_bound({r,1e9});
		if(it!=st.begin()){
			it--;
			if(it->S>=r){
				r = it->S;
				l = min(l, it->F);
				st.erase(it);
			}
		}

		while(1){
			auto it = st.lower_bound({l,0});
			if((it == st.end()) || (it->F>r)) break;
			else{
				st.erase(it);
			}
		}
		st.insert({l,r});
	}
	for(auto v: st){
		cout<<v.F<<" "<<v.S<<"\n";
	}
}


void tower(int n, char from, char to, char aux){
    if(n == 1){
        cout<<"Move disk 1 from rod "<<from<<" to rod "<<to<<'\n';
        return;
    }
    tower(n-1,from, aux, to);
    cout<<"Move disk "<<n<<" from rod "<<from<<" to rod "<<to<<'\n';
    tower(n-1,aux,to,from);
}

bool check_pal(string s){
	int n = s.length();
	for(int i=0;i<n/2;i++){
		if(s[i]!=s[n-i-1]) return false;
	}
	return true;
}

 
signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

  
    int t=1;
    cin>>t;
    while(t--){
        // int n; cin>>n;
        // tower(n,'A','C','B');
        // cout<<((1<<n)-1)<<'\n';
        string s; cin>>s;
        if(check_pal(s)){
        	cout<<"Y\n"; continue;
        }
        string snew = ""; bool f = 1;
        for(int i=0;i<s.length();i++){
        	snew+=s.substr(0,i)+s.substr(i+1);
        	if(check_pal(snew)){
        		f=0;
        		cout<<"Y\n"; break;
        	}
        	snew="";
        }
        if(f){
        	cout<<"N\n";
        }
    }

    
}