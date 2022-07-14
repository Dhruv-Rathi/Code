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
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <class T> ostream &operator<<(ostream &os, const vector<T> a){ for (auto ele : a) os << ele << " "; return os;} 
template <class T> istream &operator>>(istream &is, vector<T> &a){ for (auto &ele : a) is >> ele; return is; }


void solve(){
	int n,m; cin>>n>>m;
	vii cnt[26][7];

	string s[n];
	// f(i,0,26){
	// 	f(j,0,m) cnt[i][j] = 0;
	// }
	f(i,0,n){
		cin>>s[i];
		for(int j=0;j<m;j++){
			cnt[s[i][j]-'a'][j].PB(i);
		}
	}
	int q; cin>>q;

	vector<int> a(n);
	f(i,0,n) a[i] = 1;

	while(q--){
		vector<int> ans = a;
		int res = n;
		string st; cin>>st;

		f(i,0,m){
			if(st[i] == '?'){
				i++; continue;
			}else{
				char c = st[i]-'a';
				vector<int> b = cnt[c][i];
				// cout<<b<<'\n';
				int j = 0, i=0;
				while(j<b.size() && i<ans.size()){
					if(b[j]!=i && ans[i] == 1){
						ans[i] = 0; res--; i++;
					}else {
						j++; i++;
					}
				}
				while(i<ans.size() ){
					if(ans[i] == 1){
						res--; ans[i] = 0;
					}
					i++;
				}
			}
		}
		if(res){
			cout<<res<<'\n';
		}else{
			cout<<0<<'\n';
		}
	}
}

string s; 

void solve2(){
	cin>>s;
	int n = s.length();
	if(n == 1){
		cout<<0<<'\n'; return;
	}
	if(s[0]!=s[n-1]){
		s = s.substr(1,n-1)+s[0];
	}

	int cnt = 0, ans = 0;
	string s2 = s;
	f(i,0,n-1){
		if(s[i]==s[i+1]){
			cnt++;
			if(s[i] == 'b') s[i+1] = 'w';
			else s[i+1] = 'b';
		}
	}
	// cout<<s2<<'\n'<<s<<'\n';
	frev(i,n-1,1){
		if(s2[i]==s2[i-1]){
			ans++;
			if(s2[i] == 'b') s2[i-1] = 'w';
			else s2[i-1] = 'b';
		}
	}
	// cout<<s2<<'\n';
	cout<<min(ans, cnt)<<'\n';
	// f(i,1,n){
	// 	if(s[i]!=s[i-1]){
	// 		ans+=(cnt-1)/2;
	// 		cnt = 1;
	// 	}else cnt++;
	// }

	// ans+=(cnt-1)/2;
	// cout<<ans<<'\n';
}

void Question_Mark(){
	map<string, int> mp;
	int n,m; cin>>n>>m;
	string s; 

	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=0;j<(1<<m);j++){
			string ans = "";
			for(int k=0;k<m;k++){
				if(j&(1<<k)){
					ans+='?';
				}else{
					ans+=s[k];
				}
			}
			mp[ans]++;
		}
	}

	int q; cin>>q;
	while(q--){
		string s; cin>>s;
		cout<<mp[s]<<'\n';
	}
}

void Minimum_Difference(){
	string s; cin>>s;
	int n = s.length();
	int suff[n][2], pref[n][2];

	memset(suff,0,sizeof(suff));
	memset(pref,0,sizeof(pref));

	for(int i=n-1;i>=0;i--){
		int x = (s[i] == 'b');
		if(i == n-1){
			suff[i][x] = 0;
			suff[i][1-x] = 1;
		}else{
			suff[i][x] = suff[i+1][1-x];
			suff[i][1-x] = suff[i+1][x]+1;
		}
	}
	for(int i=0;i<n;i++){
		int x = (s[i]=='b');
		if(!i){
			pref[i][x] = 0;
			pref[i][1-x] = 1;
		}else{
			pref[i][x] = pref[i-1][1-x];
			pref[i][1-x] = pref[i-1][x]+1;
		}
	}
	int ans = min(suff[0][0], suff[0][1]);
	for(int i=0;i<n-1;i++){
		ans = min(ans, suff[i+1][1]+pref[i][n%2]);
		ans = min(ans, suff[i+1][0]+pref[i][1-n%2]);
	}
	cout<<ans<<'\n';
}
 
signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    ll tc = 1;
    cin>>tc;
    for(int i=1;i<=tc;i++){
    //	cout<<"Case #"<<i<<": ";
    	Minimum_Difference();
    }
    
}