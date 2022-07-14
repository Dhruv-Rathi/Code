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


vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int m = (int)matrix.size();
    int n = (int)matrix[0].size();
    vector<vector<int>> vis( 101 , vector<int> (101, 0)); 
    
    int dx[] = {1,0,-1,0};
    int dy[] = {0,-1,0,1};
    
    int cnt = 0,i=0, j=0,k=0;
    
    while(cnt<(n*m)){
        while(i>=0 && i<m && j>=0 && j<n && (!vis[i][j])){
            ans.push_back(matrix[i][j]);
            vis[i][j] = 1;
            j+=dx[k];
            i+=dy[k];
            cnt++;
        }
        j-=dx[k];
        i-=dy[k];
        k = (k+1)%4;
        j+=dx[k];
        i+=dy[k];
    }
    return ans;
}
 

void solve(){
	int m,n; cin>>m>>n;
	vector<vector<int>>a(m,vector<int>(n,0));
	f(i,0,m){
		f(j,0,n){
			cin>>a[i][j];
		}
	}
	vector<int> ans = spiralOrder(a);
	cout<<ans;
}

void solve2(){
	int n; cin>>n;
	for(int i=1;i<=n;i++){
		if(i%3==0 && i%5==0){
			cout<<"Algozenith";
		}else if(i%3==0){
			cout<<"Algo";
		}else if(i%5==0){
			cout<<"Zenith";
		}else{
			cout<<i;
		}
		cout<<'\n';
	}
}

void solve3(){
	int n; cin>>n;
	int a[n];
	f(i,0,n){
		cin>>a[i];
	}
	sort(a,a+n);
	int i=0;
	while(a[i]<=0 && i<n){
		i++;
	}
	int k = 1;
	while(i<n){
		if(a[i]!=k){
			break;
		}
		while(a[i] == k && i<n){
            i++;
        }
        k++;
	}
	cout<<k<<'\n';
}

const int N = 1000010;
int a[N];
int t[4*N];

#define mid (l+r)/2
void build(int id, int l, int r){
	if(l == r){
		t[id] = a[l]; return;
	}
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	t[id] = max(t[id<<1], t[id<<1|1]);
}

void update(int id, int l, int r, int pos, int val){
	if(pos<l || pos>r) return;
	if(l == r){
		t[id] = val;
		return;
	}
	update(id<<1,l,mid,pos,val);
	update(id<<1|1,mid+1,r,pos,val);
	t[id] = max(t[id<<1], t[id<<1|1]);
}

int query(int id, int l, int r, int k){
	if(l == r){
		if(a[l]>=k) return l;
		return 1e9;
	}
	if(t[id<<1]>=k){
		return query(id<<1,l,mid,k);
	}
	return query(id<<1|1,mid+1,r,k);
}
#undef mid

void solve4(){
	int n,q; cin>>n>>q;
	
	f(i,0,n) cin>>a[i];
	build(1,0,n-1);
	while(q--){
		int ch; cin>>ch;
		if(ch == 1){
			int x,y; cin>>x>>y;
			a[x-1] = y;
			update(1,0,n-1,x-1,y);
		}else{
			int k; cin>>k;
			int ans = query(1,0,n-1,k);
			if(ans == 1e9){
				cout<<-1<<'\n';
			}else{
				cout<<(ans+1)<<'\n';
			}
		}
	}
}


void solve5(){
	ll n; cin>>n;

	ll a[n];
	f(i,0,n){
		cin>>a[i];
	}

	ll ans = 0;
	ll lo = 0, hi = n-1;
	while(lo<hi){
		ll x = abs(hi - lo)*(min(a[lo],a[hi]));
        ans = max(ans,x);
		if(a[lo]<=a[hi]){
            lo++;
        }else{
            hi--;
        }
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