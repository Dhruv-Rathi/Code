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

int n;

bool check(ll x,ll y){
	if(x<0 || x>=n || y<0 || y>=n) return 0;
	return 1;
}


int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void solveBomb(){
	int d;
	cin>>n>>d;
	char a[n][n];
	int dis[n][n];
	queue<pii> q;
	f(i,0,n){
		f(j,0,n){
			cin>>a[i][j];
			if(a[i][j] == '#'){
				q.push({i,j});
				a[i][j] = 'x';
				dis[i][j] = 0;
			}else{
				dis[i][j] = -1;
			}
		}
	}

	while(!q.empty()){
		pii p = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			if(check(p.F+dx[i],p.S+dy[i]) && (dis[p.F+dx[i]][p.S+dy[i]] == -1)){
				q.push({p.F+dx[i],p.S+dy[i]});
				dis[p.F+dx[i]][p.S+dy[i]] = dis[p.F][p.S]+1;
				if(dis[p.F+dx[i]][p.S+dy[i]]<=d){
					a[p.F+dx[i]][p.S+dy[i]] = 'x';
				}
			}
		}
	}
	f(i,0,n){
		f(j,0,n) cout<<a[i][j];
		cout<<'\n';
	}


}

void solve2(){
	ll n,k; cin>>n>>k;
	vll a(n);
	f(i,0,n){
		cin>>a[i];
	}
	ll ans = 0;
	for(int i=31;i>=0;i--){
		vll v; map<ll,ll> m;
		for(auto x: a){
			if(x&(1LL<<i) && m[x]==0){
				v.pb(x);
			}
			m[x]++;
		}
		if((ll)(v.size())>=k){
			ans+=(1LL<<i);
			a = v;
		}
	}
	// cout<<a<<'\n';
	cout<<ans<<'\n';

}


bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}

ll power(ll a, ll b, ll N){ ll p = 1;
    while (b > 0){
        if (b & 1) p = ((p % N) * (a % N)) % N;
        a = ((a % N) * (a % N)) % N; b /= 2;
    } return p;
}

const int N = 500010;

int fact[N];

void pre(){
	fact[0] = 1;
	for(int i=1;i<N;i++){
	fact[i] = 1LL*fact[i-1]*i%mod;
	}
}

int ncr(int n, int r){
	if(n<r) return 0;
	int ans = fact[n];
	ans = 1LL*ans*power(fact[n-r],mod-2,mod)%mod;
	ans = 1LL*ans*power(fact[r],mod-2,mod)%mod;
	ans = (ans+mod)%mod;
	return ans;
}


void solve3(){
	ll n; cin>>n;
	vll a(n);
	map<ll,ll> mp;
	f(i,0,n){
		cin>>a[i];
		mp[a[i]]++;
	}
	ll ans = 0;

	for(auto i: mp){
		if(i.F == 0){
			ans = ((ans+power(2,i.S,mod2))%mod2-1 + mod2)%mod2;
		}
		else{
			ans = (ans+power(2,i.S-1,mod2))%mod2;
		}
	}
	ll den = (power(2,n,mod2)%mod2 - 1 + mod2)%mod2;

	ans = ((ans%mod2)*(power(den,mod2-2,mod2)%mod2))%mod2;

	cout<<(ans+mod2)%mod2<<'\n';

}

void solve4(){
	int n,m; cin>>n>>m;
	vector<string> s(n);
	f(i,0,n){
		cin>>s[i];
	}
	int pre[n+1][26];
	memset(pre,0,sizeof(pre));

	f(i,1,n+1){
		f(j,0,s[i-1].size()) pre[i][s[i-1][j]-'a']++;
		f(j,0,26) pre[i][j]+=pre[i-1][j];
	}

	char ans;

	while(m--){
		int l,r,k; cin>>l>>r>>k;
		
		int cnt = 0;
		while(k>(pre[r][cnt]-pre[l-1][cnt])){
			k-=(pre[r][cnt]-pre[l-1][cnt]);
			cnt++;
		}
		ans = 'a'+cnt;
		cout<<ans<<'\n';
	}
}

void solve5(){
	ll n,k; cin>>n>>k;
	vll a(n);
	f(i,0,n){
		cin>>a[i];
	}
	ll cur = 0, ans = 0;
	map<ll,ll> m;
	f(i,0,n){
		cur+=(a[i]-k);
		if(cur==0){
			ans++;
		}
		if(m.find(cur)!=m.end())
			ans+=m[cur];
		m[cur]++;
	}

	cout<<ans<<'\n';
}

void solveXor(){
	int n; cin>>n;
	ll a[n];
	f(i,0,n){
		cin>>a[i];
	}
	ll cnt = 0, ans = 0;
	f(i,0,60){
		cnt = 0;
		f(j,0,n){
			if(a[j]&(1LL<<i)){
				cnt++;
			}
		}
		ans = ((ans%mod)+(((((power(2,i,mod)%mod)*(cnt%mod))%mod)*(((n-cnt)%mod+mod)%mod))%mod))%mod;
	}

	cout<<(ans+mod)%mod<<'\n';
}


 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    test(t)
    solveXor();
    
    
    
}