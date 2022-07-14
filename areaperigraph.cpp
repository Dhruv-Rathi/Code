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

// Solution for Area and Perimeter q is commented

// int n,R;
// char g[1010][1010];
// int region[1010][1010], area[1000100], peri[1000100];

// void visit(int i, int j, int r){
// 	stack<pii> st;
// 	st.push(mp(i,j));
// 	while(!st.empty()){
// 		pii cur = st.top();
// 		st.pop();
// 		i = cur.F; j = cur.S;
// 		if(region[i][j]!=0 || g[i][j]=='.') continue;

// 		region[i][j] = R;
// 		area[R]++;
// 		st.push(mp(i-1,j));
// 		st.push(mp(i+1,j));
// 		st.push(mp(i,j-1));
// 		st.push(mp(i,j+1));
// 	}
// }

// void find_peri(){
// 	for(int i=1;i<=n;i++){
// 		for(int j=1;j<=n;j++){
// 			int r = region[i][j];
// 			if(r == 0) continue;
// 			if(region[i-1][j] == 0) peri[r]++;
// 			if(region[i+1][j] == 0) peri[r]++;
// 			if(region[i][j-1] == 0) peri[r]++;
// 			if(region[i][j+1] == 0) peri[r]++;
// 		}
// 	}
// }



// void solve(){
// 	cin>>n;
// 	string s;
// 	for(int i=0;i<n+2;i++){
// 		g[0][i] = g[n+1][i] = '.';
// 	}
// 	for(int i=1;i<=n;i++){
// 		g[i][0] = g[i][n+1] = '.';
// 		// cin>>s;
// 		for(int j=1;j<=n;j++){
// 			cin>>g[i][j];
// 		}
// 	}

// 	// f(i,0,n+2){
// 	// 	f(j,0,n+2) cout<<g[i][j]<<' ';
// 	// 	cout<<'\n';
// 	// }
// 	for(int i=1;i<=n;i++){
// 		for(int j=1;j<=n;j++){
// 			if(g[i][j] == '#' && region[i][j] == 0) visit(i,j,++R);
// 		}
// 	}

// 	find_peri();

// 	int ar=0,p = 0;
// 	for(int i=1;i<=R;i++){
// 		if(area[i]>ar || (area[i] == ar && peri[i]<p)){
// 			ar = area[i];
// 			p = peri[i];
// 		}
// 	}

// 	cout<<ar<<' '<<p;

// }

/*
Solution for Vertical Graph Q.
*/

int n,k;
int g[110][10], region[110][10],rsize[1110];

void visit(int i, int j, int r, int c){
	if(i<0 || i>=n || j<0 || j>9|| g[i][j]!=c || region[i][j]) return;
	region[i][j] = r;
	rsize[r]++;
	visit(i-1,j,r,c);
	visit(i+1,j,r,c);
	visit(i,j-1,r,c);
	visit(i,j+1,r,c);
}

void gravity(){
	for(int j=0;j<10;j++){
		int top = n-1, bottom = n-1;
		while(top>=0){
			while(g[top][j] == 0 && top>=0) top--;
			if(top>=0)
				g[bottom--][j] = g[top--][j];
		}
		while(bottom>=0) g[bottom--][j] = 0;
	}
}

void print(){
	for(int i=0;i<n;i++){
		for(int j=0;j<10;j++)
			cout<<g[i][j];
		cout<<'\n';
	}

}


void VerticalGrid(){
	cin>>n>>k;
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=0;j<10;j++){
			g[i][j] = s[j]-'0';
		}
	}

	while(1) {
		int r = 1;
		for(int i=0;i<n;i++)
			for(int j=0;j<10;j++)
				region[i][j] = 0;

		for(int i=0;i<n;i++)
			for(int j=0;j<10;j++)
				if(g[i][j] && region[i][j] == 0){
					visit(i,j,r++,g[i][j]);
				}

		bool f = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<10;j++){
				if(g[i][j] && rsize[region[i][j]]>=k){
					g[i][j] = 0;
					f = 1;
				}
			}
		}

		gravity();
		while(r) rsize[r--] = 0;
		// print(); cout<<'\n';
		if(f == 0) break;
	}

	print();
}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    // test(t)
    VerticalGrid();
    
    
    
}